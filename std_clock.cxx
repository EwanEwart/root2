#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime> // std::clock
#include <thread>

void f()
{
   volatile double d = 0;
   for (int n = 0; n < 10000; ++n)
      for (int m = 0; m < 10000; ++m)
      {
         double diff = d * n * m;
         d = diff + d;
      }
}
// void std_clock()
int main()
{
   std::clock_t const c_start = std::clock();
   auto t_start = std::chrono::high_resolution_clock::now();
   std::thread t1(f);
   std::thread t2(f); // f() is called on two threads
   t1.join();
   t2.join();

   std::clock_t const c_end = std::clock();
   auto const t_end = std::chrono::high_resolution_clock::now();

   std::cout
       << std::fixed 
       << std::setprecision(2) 
       << std::setw(30)
       << "CPU time used: "

       << std::setw(10)
       << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC

       << " ms\n"
       
       
       << std::setw(30)
       << "Wall clock time passed: "
       
       << std::setw(10)
       << (std::chrono::duration<double, std::milli>(t_end - t_start)).count()
       << " ms"
       
       << std::endl;
   
   return 0;
}
/*
$ g++ std_clock.cxx && ./a.out ; rm a.out
               CPU time used:    1814.49 ms
      Wall clock time passed:     916.00 ms
*/
/*
https://en.cppreference.com/w/cpp/chrono/c/clock

Returns the 
** approximate processor time *** 
used by the process 
since the beginning of an implementation-defined era 
related to the program's execution. 

To convert the result value to seconds divide it by CLOCKS_PER_SEC.

Only the difference between two values 
returned by different calls to std::clock 
is meaningful, 
as the beginning of the std::clock era 
does not have to coincide 
with the start of the program. 

std::clock time may advance faster or slower 
than the wall clock, 
depending on the execution resources 
given to the program 
by the operating system. 

For example, if the CPU is shared by other processes, 
std::clock time may advance slower than the wall clock. 

On the other hand, if the current process is multithreaded 
and more than one execution core is available, 
std::clock time may advance faster than wall clock.

Parameters
(none)

Return value

Processor time used by the program so far 
or std::clock_t(-1) 
if that information is unavailable 
or its value cannot be represented.

Exceptions

Throws nothing.

Notes

On POSIX-compatible systems, 
clock_gettime with clock id CLOCK_PROCESS_CPUTIME_ID offers better resolution.

The value returned by clock() 
may wrap around on some non-conforming implementations. 

For example, on such an implementation, 
if std::clock_t is a signed 32-bit integer 
and CLOCKS_PER_SEC is 1'000'000, 
it will wrap after about 2147 seconds (about 36 minutes).

Example

This example demonstrates the difference between 
- clock() time and 
- real time.

*/
