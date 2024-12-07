#include <thread>
using std::thread;

#include <mutex>
using std::lock_guard;
using std::mutex;

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <string>
using std::string;

mutex io_mutex;

//////////////////
// #define LOCK
//////////////////

void greetings(string const& message)
{
#ifdef LOCK
   // guard from message-interleave : chars interleaved from several messages
   lock_guard<mutex> lk(io_mutex); // RAII
#endif
   cout << message << endl;
}

void print_av(int ac, char const *av[])
{
#ifdef LOCK
   // guard from message-interleave : chars interleaved from several messages
   lock_guard<mutex> lk(io_mutex); // RAII
#endif
   cout << "args ..." << endl;
   for (unsigned short k{}; k < ac; ++k)
   {
      cout << (k + 1) << ". " << av[k] << endl;
   }
}

void print_env(char const *ev[])
{
#ifdef LOCK
   // guard from message-interleave : chars interleaved from several messages
   lock_guard<mutex> lk(io_mutex); // RAII
#endif
   cout << "environment ..." << endl;
   for (unsigned short k = 0; ev[k]; ++k)
   {
      cout << (k + 1) << ". " << ev[k] << endl;
   }
}


int thr_02()// entry point : thread started by the C++ runtime
{
   int ac {4};
   char const * av [] = {"thr_02", "arg_1", "arg_2", "arg_3" };
   char const * ev [] = { "env_1", "env_2", "env_3", nullptr };

   cout << '\n'
        << endl;
#ifdef LOCK
   cout << "LOCK : no message interleaving."<<endl;
#else
   cout << "LOCK off: possible message interleaving;\n run programm several times to see it !"<<endl;
#endif

   /* one argument needed : message */
   if (ac < 2)
   {
      cerr << "You need to pass a message to this app!" << endl;
      return (-1);
   }

   /* create another thread with message passing */
   thread another_thread(
       greetings, "This is a greeting from another thread, but the main thread.");

   print_av(ac, av);

   print_env(ev);

   greetings("A main thread greeting ... " + string(av[0]));

   another_thread.join();

   return 0;
}
