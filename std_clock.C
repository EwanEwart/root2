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
void std_clock()
{
   clock_t const c_start = clock();
   auto t_start = chrono::high_resolution_clock::now();
   thread t1(f);
   thread t2(f); // f() is called on two threads
   t1.join();
   t2.join();

   clock_t const c_end = clock();
   auto const t_end = chrono::high_resolution_clock::now();

   cout
       << fixed 
       << setprecision(2) 
       << setw(30)
       << "CPU time used: "

       << setw(10)
       << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC

       << " ms\n"
       
       
       << setw(30)
       << "Wall clock time passed: "
       
       << setw(10)
       << (chrono::duration<double, milli>(t_end - t_start)).count()
       << " ms"
       
       << endl;
   
}
/*
root [0] .x std_clock.C 
               CPU time used:    1329.75 ms
      Wall clock time passed:     665.79 ms
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
