#include<thread>
using namespace std;

class thread_guard
{
   thread &t;

public:
   explicit thread_guard(thread &t_) : t(t_)
   {
   }
   ~thread_guard()
   {
      if (t.joinable())
      {
         t.join();
      }
   }
   thread_guard(thread_guard const &) = delete; // copy ctor
   thread_guard &operator=(thread_guard const &) = delete; // copy assignment ctor
};
