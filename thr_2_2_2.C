#include <string>
#include<thread>
#include<iostream>
using namespace std;

void static f(int i, string const &s)
{
   cout<<"t->f: "<<i<<" x "<<s<<endl;
}
void oops(int some_para)
{
   char buf[1024];
   sprintf(buf,"%i",some_para);
   auto t {thread(f,101,buf)}; // potential dangling pointer
   if (t.joinable())
   {
      t.detach();
   }
}  // buf goes out of scope: conversion buf char[] => string hopefully not still underway

void thr_2_2_2()
{
   oops(101);
   /*
root [0] .x thr_2_2_2.C 
t->f: 101 x �     <= oops !!!
root [1] .x thr_2_2_2.C 
t->f: 101 x 101   <= fine.
root [2] 
   */
}
