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
   // j << cin; // deprecated
   cin >> j;

   // serialise / dump formatted JSON
   cout << setw(indent) << j << endl;

   char text[] =
   R"(
      {
         "Image": {
            "Width":  800,
            "Height": 600,
            "Title":  "View from 15th Floor",
            "Thumbnail": {
                "Url":    "http://www.example.com/image/481989943",
                "Height": 125,
                "Width":  100
            },
            "Animated": false,
            "IDs": [116, 943, 234, 38793]
         }
      }
   )";
}
