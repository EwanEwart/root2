#include<iostream>
#include<iostream>
#include<thread>
using namespace std;

// custom terminate_hander
void ee_terminate_handler()
{
   cout
   <<"The \"thread destructor\" called the \"terminate_handler\": \n"
      "Neiter \"thread::join\" nor \"thread::detach\" was called !!!\n"
      "Please either \"join\" or \"detach\" the thread !"
   << endl;
   ;
   
   exit(EXIT_FAILURE);
}

void tf()
{
   this_thread::sleep_for(5s);
   cout<<"tf ..."<<endl;
}

void thr_1_4()
{
   set_terminate(ee_terminate_handler);
   
   auto t1 {thread(tf)};
   // t1.join();
   t1.detach();
}

int main(int argc, char const *argv[])
{
   thr_1_4();
   return 0;
}
