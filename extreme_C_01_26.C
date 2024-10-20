// generic function ( having a generic pointer (void *))
void print_bytes(void *data, size_t length)
{
   // any type ---> unsigned char *
   auto ptr = static_cast<unsigned char *>(data); // <-- void*
   for (size_t i{}; i < length; ++i, ++ptr)
   {
      printf("0x%x", *ptr);
      if (i + 1 < length)
         printf(", "); // if not last item, comma
   }
   printf("\n");
}
void extreme_C_01_26()
{
   int a = 9;       // data
   double b = 18.9; // data
   print_bytes(&a, sizeof(int));
   print_bytes(&b, sizeof(double));
}
