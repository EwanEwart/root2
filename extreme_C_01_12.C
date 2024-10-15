#define LOOP_3(X, ...) \
   printf("%s\n", #X);

#define LOOP_2(X, ...) \
   printf("%s\n", #X); \
   LOOP_3(__VA_ARGS__)

#define LOOP_1(X, ...) \
   printf("%s\n", #X); \
   LOOP_2(__VA_ARGS__)

#define LOOP(...) \
   LOOP_1(__VA_ARGS__)

void extreme_C_01_12()
{
   /* 1 */ LOOP(copy paste cut) // one stringenised arg only
   /* 2 */ LOOP(copy, paste, cut) // fits
   /* 3 */ LOOP(copy, paste, cut, select) // select will be dropped
}

/*
1.
copy paste cut


2.
copy
paste
cut

3.
copy
paste
cut
*/
