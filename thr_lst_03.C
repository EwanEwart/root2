/*
 * A function that returns
 * while a thread still has access
 * to local variables
 *
 */

#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

///////////////////////
// #define DETACH
//////////////////////

void do_something(int m)
{
   static auto k{0};

   if (++k > m)
   {
      k = 0*m;
   }

   cout << '.';
   if (k % 24 == 0)
      cout << '\n';
   cout.flush();
}

struct func_obj
{
   int &i;

   func_obj(int &i_) // ctor
       : i(i_)
   {
   }

   void operator()()
   {
      for (unsigned j = 0; j < 1000000; ++j)
      {
         do_something(i); // ref i of oops() might be gone
      }
   }
};

void oops()
{
   auto some_local_state{50};

   cout << endl;

   func_obj some_function_object(some_local_state);

   thread some_thread(some_function_object);

#ifdef DETACH
   some_thread.detach();
#else
   some_thread.join();
#endif

   cout << endl;
}

int main() // thread started by the C++ runtime
{

   oops();

   cout << endl;

   return 0;
}
