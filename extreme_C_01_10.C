/*
variadic args
*/
#define VERSION "2.3.4"

#define LOG_ERROR(format, ...) \
   fprintf(stderr, format, __VA_ARGS__)

int test(int ac, char const *av[])
{
   if (ac < 3)
   {
      LOG_ERROR("version %s: Invalid number of arguments.\n", VERSION); // %s: 1 arg
      return 1;
   }
   if (strcmp(av[1], "-n") != 0)
   {
      // %s,%s,%d: 3 args
      LOG_ERROR("version %s: parameter \"%s\" at index %d is incorrect.\n", VERSION, av[1], 1);
      return 1;
   }
   return 0;
}
void extreme_C_01_10()
{
   // test correctness of 2nd arg: correct
   char const *args1[]{"arg1", "-n", "arg3"};
   printf("return value: %d\n", test(3, args1));

   // test correctness of 2nd arg: incorrect
   char const *args2[]{"arg1", "arg2", "arg3"};
   printf("return value: %d\n", test(3, args2));

   // test no. of args: incorrect
   printf("return value: %d\n", test(2, args1));
}
