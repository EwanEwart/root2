/*
Listing 2.1
A function that returns
while a thread still has access to local variables
*/
#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;
using std::this_thread::sleep_for;

#include <chrono>
using namespace std::chrono_literals;
//////////////////////////////////////
// define REF | NO_REF
#define REF
// #define NO_REF
//////////////////////////////////////

//////////////////////////////////////
// define JOIN | DETACH
//////////////////////////////////////
#define JOIN
// #define DETACH
//////////////////////////////////////

struct Fo
{
#ifdef REF
   int &_ref;
#endif

#ifdef NO_REF
   int _ref;
#endif

#ifdef REF
   Fo(int &ref) : _ref(ref) {}
#endif

#ifdef NO_REF
   Fo(int ref) : _ref(ref) {}
#endif

   void operator()()
   {
      for (auto k{1}; k <= 100; ++k)
      {
         do_something(k);
      }
      cout << endl;
   }
   void do_something(int k)
   {
      cout << k * _ref << ", ";
      if (k % 10 == 0)
         cout << endl;
   }
};

void thr_lst_02_01() // oops
{
   int factor = 2; // possibly dangling reference

   Fo fo(factor); // possibly dangling reference
   thread factor_thread{fo};

#ifdef DETACH
   factor_thread.detach();
#endif
   sleep_for(100ns);

#ifdef JOIN
   factor_thread.join();
#endif
}

// int main(int argc, char const *argv[])
int main() // thread started by the C++ runtime
{
   thr_lst_02_01(); // oops

   return 0;
}
