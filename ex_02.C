/*
trivial integration
- single header file
- no build system required
- vanille C++11
- gcc 4.8+
- clang 3.4+
- vcc 2015+
*/

// JSON pretty printer
void ex_02()
{
   unsigned indent{4};

   using json = nlohmann::json;
   json j;

   // deserialise / parse unformatted JSON 
   // (copy ex_02.json content) or better ...
   // Enter at the bash prompt: 
   //
   // root ex_02.C < ex_02.json
   //
   j << cin;

   // serialise / dump formatted JSON
   cout << setw(indent) << j << endl;
}
