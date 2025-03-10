#include <iostream> // for build .so
using std::cerr;
using std::cout;
using std::endl;

/*
   Macro with arguments
   =====================

   shell (quoted):
   ---------------

$ root 'macro_01.C(1)'
   ------------------------------------------------------------------
  | Welcome to ROOT 6.30/08                        https://root.cern |
  | (c) 1995-2024, The ROOT Team; conception: R. Brun, F. Rademakers |
  | Built for linuxx8664gcc on Jul 14 2024, 22:53:16                 |
  | From tags/v6-30-08@v6-30-08                                      |
  | With c++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0                   |
  | Try '.help'/'.?', '.demo', '.license', '.credits', '.quit'/'.q'  |
   ------------------------------------------------------------------

root [0]
Processing macro_01.C(1)...
ac == 1 expected
root [1]

   root (unquoted):
   ---------------

root [1] .x macro_01.C(1)
ac == 1 expected
root [2]


*/

// simulate main:
// char const* arr[] {"abc","def","ghi","jkl","mno"}
// call : args(size(arr),args)
void args(size_t const ac, char const *av[]) // two args
{
   for (size_t ii{}; ii < ac; ++ii)
   {
      cout << ii + 1 << ". : " << av[ii] << endl;
   }
}
// treat no int passed
void macro_01()
{
   cout << "macro_01 has to be invoked with an int, not no arg: macro_01(int i)" << endl;
}
// treat no int passed
void macro_01(float f)
{
   cout << "macro_01 has to be invoked with an int, not float: macro_01(int i)" << endl;
}
// treat no int passed
void macro_01(double f)
{
   cout << "macro_01 has to be invoked with an int, not double: macro_01(int i)" << endl;
}
// treat no int passed
void macro_01(char c)
{
   cout << "macro_01 has to be invoked with an int, not char: macro_01(int i)" << endl;
}

// an int is expected to be passed
void macro_01(int integer)
{
   cout << "void macro_01(int integer) // one arg" << endl;
   cout << "void args(int ac, char const* av[]) // two args" << endl;

   if (integer == 0)
   {
      cout << "integer == 0" << " expected" << endl;
   }
   else if (integer == 1)
   {
      cout << "integer == 1" << " expected" << endl;
   }
   else
   {
      cerr << "integer == " << integer << " surprise" << endl;
   }
}
