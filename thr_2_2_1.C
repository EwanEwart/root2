#include <iostream>
#include <string>
#include <thread>
#include <typeinfo>
using namespace std;

void f(int i, string const &s)
{
   /*
   $ c++filt -t NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
   demangled =>
   std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >
   */
   cout << typeid(s).name() << endl;
   
   
   string const& sr =s ;
   cout << typeid(sr).name() << endl;

}
void thr_2_2_1()
{
   auto t1{thread(f, 10, /* char const * */"abc")};
   if (t1.joinable())
   {
      t1.join();
      cout << "joined f"<<endl;
   }
}
