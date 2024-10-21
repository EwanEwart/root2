// function signature && alias via typedef
#include<cstdio> // not necessary for macro .C

typedef int bool_t;
typedef bool_t (*less_than_func_t)(int, int);
bool_t less_than(int a, int b)
{
   return a < b ? 1 : 0;
}
bool_t less_than_modular_5(int a, int b)
{
   return (a % 5) < (b % 5) ? 1 : 0;
}
void extreme_C_01_32()
{
   less_than_func_t func_ptr;

   // func_ptr = &less_than;
   func_ptr = less_than;
   bool_t result = func_ptr(3, 7);
   printf("%d\n", result);
   
   // func_ptr = &less_than_modular;
   func_ptr = less_than_modular_5;
   result = func_ptr(3, 7);
   printf("%d\n", result);
}

int main(int argc, char const *argv[])
{
   extreme_C_01_32();
   return 0;
}
