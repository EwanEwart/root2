#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

void the_message_thread()
{
   cout
       << '\n'
       << "2. the_message_thread"
       << '\n'
       << endl
       ;
}
void thr_lst_01() // thread started by the C++ runtime
{
   cout << '\n' << endl;

   cout << "1. The Main Thread starts the_message_thread." << endl;

   thread t02(the_message_thread);

   // join
   //
   // t02.join();
   /*
   root [0] .x thr_lst_01.C
   1. The Main Thread starts the_message_thread.
   2. the_message_thread
   3. The main Thread.
   */
   // detach
   //
   t02.detach();
   /*
   root [1] .x thr_lst_01.C
   1. The Main Thread starts the_message_thread.
   3. The main Thread.
   2. the_message_thread
   */

   cout << "3. The main Thread." << endl;

   cout << '\n' << endl;
}

// int main ( int ac, char const * av [], char const * ev [] )
int main()
{
   thr_lst_01();

   return 0;
}
