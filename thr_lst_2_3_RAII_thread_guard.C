/*
One way of not using try/catch  to call join is
to use the standard Resource Acquisition Is Initialisation (RAII) idiom
and provide a class that does the join() in its destructor,
as in the following listing.
See how it simplifies the function f().
*/
#include<iostream>
#include<thread>
using namespace std;

#include"thr_lst_2_3_RAII_thread_guard.H"
#include"thr_lst_2_1_functor.H"

void do_something_in_current_thread(){}

void f()
{
   int some_local_state{};
   func my_func(some_local_state); // <-- takes ref of some_local_state
   thread t(my_func);
   thread_guard g(t); // RAII / call thread.join() if necessary
   do_something_in_current_thread();
}
void listing_2_3_RAII_thread_guard()
{
	f();
	cout<<"f() exited"<<endl;
}
