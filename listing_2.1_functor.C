// Listing 2.1
// a fuction that returns
// while a thread still has access
// to local variables
//
struct func
{
   int& i;
   func(int& i_)
   :i(i_){}

   void operator() ()
   {
      for(unsigned j{1};j<1001;++j)
      {
         [&j](int k){cout<<(k*j)<<(j%25?' ':'\n');}(i);
      }
      cout<<endl;
   }
};

void oops()
{
   int i {8};
   func f1(i);
   // f1();
   thread t1(f1);
   t1.detach();// critical int& i
}

