/*
#  <--- stringeniser
## <--- congatenator
*/
#define CMD(NAME)             \
   char NAME ## _cmd[256] = ""; \
   strcpy(NAME ## _cmd, #NAME);

void extreme_C_01_08()
{
   CMD(copy)
   CMD(cut)
   CMD(paste)

   char cmd[256];

   scanf("%s", cmd);

   if (strcmp(cmd, copy_cmd) == 0)
   {
      cout << cmd << endl;
   }
   else if (strcmp(cmd, paste_cmd) == 0)
   {
      cout << cmd << endl;
   }
   else if (strcmp(cmd, cut_cmd) == 0)
   {
      cout << cmd << endl;
   }
   else
   {
      cerr << "unknown cmd" << endl;
   }
}
