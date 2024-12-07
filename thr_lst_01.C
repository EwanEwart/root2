#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

void the_message_thread()
{
   cout
       << '\n'
       << "2. The Message Thread."
       << '\n'
       << endl;
}
void threads_01() // thread started by the C++ runtime
{
   cout << '\n' << endl;

   cout << "1. The Main Thread." << endl;

   thread t(the_message_thread);

   t.join();

   cout << "3. The Main Thread." << endl;

   cout << '\n' << endl;
}
// int main ( int ac, char const * av [], char const * ev [] )
int main()
{
   threads_01();

   return 0;
}
