using json = nlohmann::json;

// First-class datatype
/*
- use JSON
  like any other C++ literal
- use initialisation lists 
  for arrays & objects
*/
void ex_03_json() {
   json j = {
      { "pi",3.1415 },
      { "happy",true },
      { "name","Niels" },
      { "nothing", nullptr },
      { "answer", {
         {"everything",42 }
      }},
      {"list",{1,0,2}},
      {"object",{
         {"currency","USD"},
         {"value",42.99}
      }}
   };
   cout
   << "loaded json j = C++ initialisers "
      "for JSON arrays & objects"
   << endl;
   // setw(4) <-- format JSON serialisation output
   cout << setw(4) << j << endl;
}
