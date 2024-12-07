#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

mutex g_mtx_values;
mutex g_mtx_cout;

struct Result
{
   int tid;
   int value;
};
vector<Result> g_values;

#include "mt_randGen.H" // multithreading randGen()

// thread of execution
void threadFunc(int tid)
{
   g_mtx_cout.lock();
   cout << "Start of thread no. " << tid << endl;
   g_mtx_cout.unlock();

   g_mtx_values.lock();
   Result result{tid, g_values[0].value};
   // int value{g_values[0].value};
   g_mtx_values.unlock();

   int rval = randGen(1, 10);
   result.value += rval;

   g_mtx_cout.lock();
   cout
       << "Thread " << tid
       << " adding " << rval << ". "
       << " =>  New value: " << result.value 
       << endl;
   g_mtx_cout.unlock();

   g_mtx_values.lock();
   g_values.push_back(result);
   g_mtx_values.unlock();
}
void mt_01()
{
   g_values.clear();
   Result input{0, 42};
   g_values.push_back(input);

   thread t01(threadFunc, 1);
   thread t02(threadFunc, 2);
   thread t03(threadFunc, 3);
   thread t04(threadFunc, 4);

   t01.join();
   t02.join();
   t03.join();
   t04.join();

   // print
   string line(10, '-');
   cout << line << endl;
   cout << "Input     : " << g_values[0].value << endl;
   for (auto k{1}; k <= g_values.size() - 1; ++k)
      cout
          << "g_values[" << k << "] .tid / .value : "
          << g_values[k].tid << " / "
          << g_values[k].value
          << endl;
   cout << line << endl;

   return;
}
