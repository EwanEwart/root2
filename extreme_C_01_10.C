/*
variadic args
*/
#define VERSION "2.3.4"

#define LOG_ERROR(format, ...) \
   fprintf(stderr, format, __VA_ARGS__)

int extreme_C_01_10(int ac, char const *av[])
{
   if (ac < 3)
   {
      LOG_ERROR("Invalid number of arguments for version %s\n.", VERSION);
      return 1;
   }
   if (strcmp(av[1], "-n") != 0)
   {
      LOG_ERROR("\"%s\" is the wrong parameter at index %d for version %s.\n", av[1], 1, VERSION);
      return 1;
   }
   return 0;
}
/*
a session ...

root [0] .L extreme_C_01_10.C

root [1] char const * sss[] {"arg1","-n","arg3"}
(const char *[3]) { "arg1", "-n", "arg3" }

root [2] extreme_C_01_10(3,sss)
(int) 0

root [3] char const * sss[] {"arg1","arg2","arg3"}
(const char *[3]) { "arg1", "arg2", "arg3" }

root [4] extreme_C_01_10(3,sss)
"arg2" is the wrong parameter at index 1 for version 2.3.4.
(int) 1

root [5] extreme_C_01_10(2,sss)
Invalid number of arguments for version 2.3.4
.(int) 1

root [6] 

*/
