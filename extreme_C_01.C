#define PRINT(v) printf("%d ", v);
#define PRINTLN printf("\n");
#define RUN_LOOP(c, s, e)       \
   for (c = s; c <= e; ++c) \
   {                        \
      PRINT(counter)        \
   }                        \
   PRINTLN

int counter = 0;

void extreme_C_01()
{
   RUN_LOOP(counter, -2, 17)
}
