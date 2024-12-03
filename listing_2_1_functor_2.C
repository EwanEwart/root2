// Listing 2.1
// a fuction that returns
// while a thread still has access
// to local variables
//
#include<iostream>
#include<thread>
#include<fstream>
using namespace std;

auto output_file {"listing_2_1_functor_2.text"};

struct functor
{
   size_t& factor;
   functor(size_t& factor_)
   :factor(factor_)
   {
      cout<<"ctor factor == "<<factor<<endl;
   }

   // void operator() ()
   // void operator() (size_t& factor)
   void operator() (size_t factor)
   {
      ofstream ofs;
      ofs.open(output_file);
      cout<<"operator factor == "<<factor<<endl;
      for(unsigned j{1};j<1000001;++j)
      {
         [&j,&ofs](int k){ofs<<(k*j)<<(j%10?' ':'\n');}(factor);
      }
      ofs<<endl;
      ofs.close();
   }
};
void oops()
{
   size_t factor {8};
   functor f1(factor);

   // f1(); // factor == 8
   // f1(factor); // factor == 8

   // std::thread t1(f1);
   thread t1(f1,factor);
   t1.detach();// critical int& i
}
void listing_2_1_functor_2()
{
   oops();
}