/*
invocation:

root [0] .x extreme_C_01_07.C 
1 2 3 4 5 6 7 8 9 10 

root [1] RUN_LOOP(counter,-2,17)
-2 -1 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 

*/
#define PRINT(v) printf("%d ", v);
#define PRINTLN printf("\n");
#define RUN_LOOP(c, s, e)       \
   for (c = s; c <= e; ++c) \
   {                        \
      PRINT(counter)        \
   }                        \
   PRINTLN

int counter = 0;

void extreme_C_01_07()
{
   RUN_LOOP(counter, 1, 10)
}
