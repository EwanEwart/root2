#include<climits>

void do_something(int i){}

struct func
{
   int &i;
   func(int &i_) : i(i_) {}
   void operator()()
   {
      // https://cplusplus.com/reference/climits/
      for (unsigned long long int jj = 0; jj < ULLONG_MAX; ++jj)
      {
         for (unsigned long long int j = 0; j < ULLONG_MAX; ++j)
         // for (unsigned j = 0; j < 1000000; ++j)
         {
            do_something(i); // <-- potential reference to dangling reference
         }
      }
   }
};
