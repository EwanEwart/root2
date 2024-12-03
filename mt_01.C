#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

mutex g_mtx_values;
mutex g_mtx_cout;
vector<int> g_values;

#include "mt_randGen.H" // multithreading randGen()

// thread of execution
void threadFunc(int tid)
{
   g_mtx_cout.lock();
   cout << "Start of thread no. " << tid << endl;
   g_mtx_cout.unlock();

   g_mtx_values.lock();
   int value{g_values[0]};
   g_mtx_values.unlock();

   int rval = randGen(0, 10);
   value += rval;

   g_mtx_cout.lock();
   cout << "Thread " << tid << " adding " << rval << ". "
   << " =>  New value: " << value << endl;
   g_mtx_cout.unlock();

   g_mtx_values.lock();
   g_values.push_back(value);
   g_mtx_values.unlock();

}
void mt_01()
{
   g_values.push_back(42);

   thread t01(threadFunc, 1);
   thread t02(threadFunc, 2);
   thread t03(threadFunc, 3);
   thread t04(threadFunc, 4);

   t01.join();
   t02.join();
   t03.join();
   t04.join();

   cout << "Input     : " << g_values[0] << endl;
   cout << "g_values[1] : " << g_values[1] << endl;
   cout << "g_values[2] : " << g_values[2] << endl;
   cout << "g_values[3] : " << g_values[3] << endl;
   cout << "g_values[4] : " << g_values[4] << endl;

   return;
}
