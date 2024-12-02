/*
Listing 2.2
Waiting for a thread to finish
using try-catch -
not a good idea
*/
#include <iostream>
#include <thread>
using namespace std;

// struct func;
#include "listing-2.1-functor.H"

void do_something_in_current_thread() { throw string{"Delibrate string exception"}; }

void f()
{
   int some_local_state = 0;
   func my_func(some_local_state);
   thread t(my_func);
   try
   {
      do_something_in_current_thread();
   }
   catch (string const &message)
   {
      cerr << message << endl; // <-- delibrate string exception
      t.join(); // <---
   }
   catch (exception const &e)
   {
      cerr << e.what() << endl;
      t.join(); // <---
   }
   catch (...)
   {
      cerr << "Unknown exception !" << endl;
      t.join(); // <---
      throw;
   }
   t.join(); // <---
   
}
int main()
{
   try
   {
      f();
   }
   catch (exception const &e)
   {
      cerr << e.what() << endl;
   }
   catch (string const& message)
   {
      cerr<<"2. "<<message<<endl;
   }
   catch (...)
   {
      cerr << "exception : ???" << endl;
   }
}
