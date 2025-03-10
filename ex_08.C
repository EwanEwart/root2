/*
Type Conversion
converson from / to UDFs
can be defined using

- to_json   (json& j, udf const& u) {...}
- from_json (json const& j, udf& u) {...}

these functions will be called automatically
*/

using json = nlohmann::json;

// some UDF
struct person 
{
   string name;
   unsigned age;
};

// person => json
void to_json(json &j, person const &p)
{
   j = {{"name", p.name}, {"age", p.age}};
}

// json => person
void from_json(json const &j, person &p)
{
   p.name = j["name"];
   p.age = j["age"];
}

void ex_08()
{
   // conversions to & from UDFs
   //
   person p{"Kate", 62};
   // to_json
   json j = p;
   cout << "(to_json)" << endl;
   cout << setw(4) << j << endl;

   // from_json
   person p2 = j;
   cout << "(from_json)" << endl;
   cout << "person p2 = {" << p2.name << "," << p2.age << "}\n" << endl;
}
