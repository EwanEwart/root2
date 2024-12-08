#include <iostream>
#include <thread>
#include <utility>
#include <stdexcept>
using namespace std;

class scoped_thread
{
   thread t;

public:

   explicit scoped_thread(thread t_)
   : t(move(t_))
   {
      if(!t.joinable())
      {
         throw logic_error("This isn't a thread !");
      }
      cout<<"scoped_thread ctor => took ownership of thread"<<endl;
   }

   ~scoped_thread()
   {
      cout<<"scoped_thread dtor => going to join the thread passed to this scoped_thread"<<endl;
      t.join();
      cout<<"scoped_thread dtor => joined the reowned/passed thread"<<endl;
      cout<<"scoped_thread dtor => scoped_thread dying"<<endl;
   }
    
    scoped_thread(scoped_thread const&)=delete;
    scoped_thread& operator=(scoped_thread const&)=delete;
};

void do_something(int& i)
{
    ++i;
}

struct functor
{
   int& i;

   functor(int& i_)
   : i(i_)
   {}

   void operator()()
   {
      for(unsigned j=0;j<1000000;++j)
      {
         do_something(i);
      }
   }
};

void do_something_in_current_thread()
{
   cout<<"do_something_in_current_thread"<<endl;
   for(unsigned long k{1};k<1000000000;++k)
   {
      int i;
      ++i;
      --i;
   }
}

void f()
{
    int some_local_state{4711};
    
    scoped_thread t
    {
      thread
      {
         functor
         {
            some_local_state
         }
      }
   };
        
   do_something_in_current_thread();
}

void thr_lst_2_6()
{
   f();
}
