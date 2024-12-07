#include <string>
#include <thread>
#include <iostream>
using namespace std;

void static f(int i, string const &s)
{
   cout << "t->f: " << i << " x " << s << endl;
}
void oops(int some_para)
{
   char buf[1024];
   sprintf(buf, "%i", some_para);
   auto t{thread(f, 101, /*remedy*/string{buf})}; // convert string before passing; no thread internal conversion - no dangling pointer
   if (t.joinable())
   {
      t.detach();
   }
}

void thr_2_2_3()
{
   oops(101);
/*
root [0] .x thr_2_2_3.C 
t->f: 101 x 101
root [1] .x thr_2_2_3.C 
t->f: 101 x 101
root [2] .x thr_2_2_3.C 
t->f: 101 x 101
root [3] 
*/
}
