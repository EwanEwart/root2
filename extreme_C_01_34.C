struct sample_t
{
   char first;
   char second;
   char third;
   short fourth;
};
void print_size(sample_t *var)
// void print_size(struct sample_t *var)
{
   printf("Size: %lu bytes\n", sizeof(*var));
}
void print_bytes(sample_t *var)
// void print_bytes(struct sample_t *var)
{
   // byte arithmetic
   // auto ptr = static_cast<unsigned char *>(var) ;
   // auto ptr { static_cast<unsigned char *>(var) };
   unsigned char *ptr = (unsigned char *)var;

   for (int i{}; i < sizeof(*var); ++i, ++ptr)
   {
      printf("%d ", static_cast<unsigned int>(*ptr));
      // printf("%d ", (unsigned int)*ptr);
   }
   printf("\n");
}
void extreme_C_01_34()
{
   sample_t var;
   var.first   = 'A';
   var.second  = 'B';
   var.third   = 'C';
   var.fourth  = 765;

   print_size(&var);
   print_bytes(&var);
}
/*
root [5] .x extreme_C_01_34.C
Size: 6 bytes
65 66 67 167 253 2 

*/
