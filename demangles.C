auto demangle = [](auto var)
{
   char*         realname;
   int           status;
   string        rv;

   realname = abi::__cxa_demangle(typeid(var).name(),0,0,&status);

   if(status == 0)
   {
      rv = realname;
      free(realname);
   }
   else
   {
      rv = "The demangle operation failed.";
   }
   return rv;
};

// testbed
void demangles()
{
   unsigned long ul1 { 1000000 };
   cout<<demangle(ul1)<<endl;
}
