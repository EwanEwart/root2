/*
Deserialisation / Parsing
*/

using json = nlohmann::json;

void ex_11()
{

   // from string
   json j01 = json::parse("[1,null,false]");
   cout << "j01 from string ... " << setw(4) << j01 << endl;

   // from raw string
   json j02 = json::parse(  R"( [1,null,false] )"   );
   cout << "j02 from raw string ... " << setw(4) << j02 << endl;

   // from stream
   json j03;
   stringstream("{\"one\": 1}") >> j03;
   cout << "j03 from stream ... " << setw(4) << j03 << endl;

   // from raw stream
   json j04;
   stringstream(R"( {"one": 1}  )") >> j04;
   cout << "j04 from raw stream ... " << setw(4) << j04 << endl;

   // from string *literal*
   json j05 = "[3.1515]"_json;
   cout << "j05 from string literal ... " << setw(4) << j05 << endl;

   // from "raw" string literal
   json j06 = R"( {"one": 1, "two": 2, "three": [1,null,false], "four": "z" }  )"_json;
   cout << "j06 from raw string literal ... " << setw(4) << j06 << endl;

}
