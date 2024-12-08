#include <iostream>
#include <thread>
#include <math.h>

void do_something(int &i)
{
   ++i;
}

struct function_object
{
   int &i; // a reference

   function_object(int &i_) : i(i_) {}

   void operator()()
   {
      auto loops{pow(10, 6)};
      for (unsigned j = 0; j < loops; ++j)
      {
         do_something(i); // potential access to dangling reference
      }
   }
};

void oops()
{
   auto dummy{0};
   int int_local_state{};
   function_object a_function_object(int_local_state);
   std::thread a_thread_object(a_function_object);

////////////////////////////////////////
// define DETACH or JOIN or define none
//////////////////////////////////////
// #define JOIN
   // #define DETACH
   //////////////////////////////////////

#ifdef DETACH
   a_thread_object.detach(); // don't wait for thread to finish
   std::cout << "detached thread"<<std::endl;
   /*
   root [0] .L ./listings/listing_2.1.cpp
   root [1] main()
   (int) 0

    *** Break *** segmentation violation
    Generating stack trace...
   */
#elifdef JOIN
   if (a_thread_object.joinable())
   {
      a_thread_object.join();
      std::cout<< "joind thread"<<std::endl;
   }
   else
      std::cerr << ">>> thread wasn't joinable <<<"<<std::endl;

   /*
   root [0] .L ./listings/listing_2.1.cpp
   root [1] main()
   (int) 0
 */
#else
   ++dummy;
   // Neither join nor detach
   /*
   root [0] .L ./listings/listing_2.1.cpp
   root [1] main()
   terminate called without an active exception
   ewan@ewan-TravelMate-5760:
*/
#endif
} // new thread might still be running

void thr_listing_2_1()
{
   oops();
   // int int_local_state{}; : <<<--- out of oop() scope --->>> segmentation violation
}
