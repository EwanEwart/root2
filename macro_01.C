#include <iostream> // for build .so
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
void args(size_t ac, char const* av[]) // two args
{
   for(size_t ii{};ii<ac;++ii)
   {
      cout << ii << ". : " << av[ii] << endl;
   }
}
void macro_01(int ac) // one arg
{
   cout << "void macro_01(int ac) // one arg" << endl;
   cout << "void args(int ac, char const* av[]) // two args" << endl;
   
   if (ac==0)
   {
      cout << "ac == 0" << " expected" << endl;
   }
   else if (ac==1)
   {
      cout << "ac == 1" << " expected" << endl;
   }
   else
   {
      cerr << "ac == " << ac << " surprise" << endl;
   }
   
}
