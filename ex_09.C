/*
Type Deduction
- types are deduced automatically
- conversion from/to compatible types works
- member functions tell you the type
*/
void ex_09()
{
   using json = nlohmann::json;

   // automatic type deduction
              // c++             JSON
   json j01 = nullptr;           // null
   json j02 = false;             // boolean
   json j03 = 12.29;             // number
   json j04 = {1, 2, 3};         // array
   json j05 = {"key", "value"};  // array
   json j06 = {{"key", "value"}};// object
   json j07 = "string";          // string

   // quick checks
   // - member functions tell you the type
   if (
       j01.is_null() 
       &&
       j02.is_boolean() 
       &&
       j03.is_number() 
       &&
       j04.is_array() 
       &&
       j05.is_array() 
       &&
       j06.is_object() 
       &&
       j07.is_string()
      )
   {
      cout << "Quick deduction-checks successful." << endl;
   }
   else
   {
      cerr << "Quick deduction-checks failed." << endl;
   }
}
