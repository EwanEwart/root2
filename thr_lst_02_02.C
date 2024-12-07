#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <chrono>
using namespace std::chrono_literals;
using std::chrono::duration;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;

#include <thread>
using std::thread;
using std::this_thread::sleep_for;

#include <ratio>
using std::nano;

#include <exception>

// using namespace std::literals ; // c++14

struct func_obj
{
   unsigned long long _cycles; // printed as dots
   int _line_length;

   func_obj() = delete;
   func_obj(
       unsigned long long const &cycles = 100, int const &line_length = 100 // line length: dots == cycles per line
       )
       : _cycles(cycles), _line_length(line_length)
   {
   }

   void operator()()
   {
      for (unsigned long k{1}; k <= _cycles; ++k)
      {
         cout << ".";
         if ( ( k % _line_length ) == 0 )
         {
            cout 
               << ' ' 
               << ( k / _line_length ) 
               << endl;
         }
      }
   }
};

void g_do_something_within_current_thread
(
#if 200800L < __cpluscplus && __cpluscplus < 201200L
    nanoseconds const &ns = 5
#else
    nanoseconds const &ns = 5ns
#endif
    ,
    bool throw_exception = true
)
{

   cout
       << '\n'
       << "1. This job has to be done within "
       << ns.count()
       << " ns"
       << endl;

   auto start{high_resolution_clock::now()};

   sleep_for(ns);

   if (throw_exception)
   {
      throw("The time is up!");
   }

   auto end{high_resolution_clock::now()};

   duration<double, nano> elapsed{end - start};

   cout << "\n2. This job was done within ... " << elapsed.count() << " ns" << endl;
}

void g_fn
(
#if 200800L < __cpluscplus && __cpluscplus < 201200L
    /* 1 */ chrono::nanoseconds const &ns = 5
#else
    /* 1 */ nanoseconds const &ns = 5ns
#endif
    /* 2 */,
    unsigned long long const &cycles = 100
    /* 3 */,
    int const &line_length = 100
    /* 4 */,
    bool exc = false
)
{

   func_obj fo{cycles, line_length};

   std::thread t{fo}; // start the second thread, "fo" copied to "t"

   try
   {
#if 200400L < __cpluscplus && __cpluscplus < 201200L
      g_do_something_within_current_thread(ns); // c++11
#else
      g_do_something_within_current_thread(ns, exc); // c++14
                                                       //  g_do_something_within_current_thread ( ns ) ; // c++14
#endif
   }
   catch (...)
   {
      t.join(); // join in the event of an exception
      cerr 
         << '\n'
         << "!!! Going to propagate an exception !!!\n"
         << endl;
      throw; // propagate exception
   }

   t.join(); // normal join
}

// int main ( int ac, char const* av [] )
int main() // thread started by the C++ runtime
{
   cout << '\n' << "Start _ _ _ " << endl;
   try
   {
      // g_fn(); // time for the job 5ns, 100 cycles, 100 line_length
      g_fn(1766762ns,100,10,false);
   }
   catch (char const *message)
   {
      cerr << '\n' << message << endl;
   }
   catch (...)
   {
      cerr << '\n' << "A propagated exception has been caught.\n" << endl;
   }
   cout << '\n' << "End _ _ _ " << endl;

   return 0;
}
