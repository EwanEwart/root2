/*
One way of not using try/catch  to call join is
to use the standard Resource Acquisition Is Initialisation (RAII) idiom
and provide a class that does the join() in its destructor,
as in the following listing.
See how it simplifies the function f().
*/
#include<thread>
using namespace std;

#include"listing-2.3.-RAII-thread-guard.H"
#include"listing-2.1-functor.H"

void do_something_in_current_thread(){}

void f()
{
   int some_local_state = 0;
   func my_func(some_local_state);
   thread t(my_func);
   thread_guard g(t); // RAII / join if necessary
   do_something_in_current_thread();
}
