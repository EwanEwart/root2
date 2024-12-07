/*
Listing 2.1
A function that returns
while a thread still has access to local variables
*/
#include <thread>
using namespace std;

#include "thr_lst_2_1_functor.H"

void oops()
{
   int some_local_state = 0;
   func my_func(some_local_state);
   std::thread my_thread(my_func);
   my_thread.detach(); // <-- don't wait for thread to finish
} // <-- new thread might still be running

void listing_2_1_functor()
{
   oops();
}
