#include <thread>

void do_something(int &i)
{
   ++i;
}

struct functor
{
   int &i;

   functor(int &i_) : i(i_) {}

   void operator()()
   {
      for (unsigned j{}; j < 1000000; ++j)
      {
         do_something(i);
      }
   }
};

void do_something_in_current_thread(bool fail=false)
{
   static unsigned counter{};
   unsigned const limit {1000000};
   for (size_t i = 0; i < limit; ++i)
   {
      ++counter;
   }

   if(fail) throw; 
}

void f()
{
   auto some_local_state{0};
   functor a_functor(some_local_state);
   std::thread t1(a_functor);
   try
   {
      do_something_in_current_thread();
      /*
      root [0] .L listings/listing_2.2.cpp 
      root [1] main()
      (int) 0
      */

      // do_something_in_current_thread(true);
      /*
      root [3] .L listings/listing_2.2.cpp 
      root [4] main()
      terminate called without an active exception
      */
   }
   catch (...)
   {
      t1.join();
      throw;
   }
   t1.join();
}

int main()
{
   f();
}
