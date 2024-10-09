/*
Serialisation

*/
using json = nlohmann::json;

auto fstream_in{"ex_02.json"};
auto fstream_out{"delete.json"};

// either
// json j = json::parse("{\"pi\": 3.141,\"happy\":true,\"name\":\"Niels\",\"nothing\":null,\"answer\":{\"everything\":42},\"list\":[1,0,2],\"object\":{\"currency\":\"USD\",\"value\":42.99}}");

// or
json j;

void ex_10()
{

   unsigned indentation{4};

   // get some json data
   fstream fs_in;
   fs_in.open(fstream_in, fstream::in);
   if (fs_in.is_open()) { fs_in >> j; }
   else { cerr << "--- Couldn't open " << fstream_in << endl; return;
   }

   // default serialisation to string
   auto str01 = j.dump();
   cout << endl;
   cout << "1. serialisation to string - not formatted" << '\n'
        << str01 << '\n'
        << endl;

   // serialisation to string pretty printed
   string str02 = j.dump(indentation);
   cout << "2. serialisation to string - formatted" << '\n'
        << str02 << '\n'
        << endl;

   // to stream
   cout << "3. serialisation to stream - not formatted" << '\n'
        << j << '\n'
        << endl;

   // to stream pretty printed
   cout << "4. serialisation to stream - formatted" << '\n'
        << setw(indentation) << j << '\n'
        << endl;

   fstream fs_out;
   fs_out.open(fstream_out, fstream::out);
   if (fs_out.is_open())
   {
      // to fstream
      fs_out << "5. serialisation to fstream - not formatted" << '\n'
             << j << '\n'
             << endl;

      // to fstream pretty printed
      fs_out << "6. serialisation to fstream - formatted" << '\n'
             << setw(indentation) << j << '\n'
             << endl;

      fs_out.close();
   }
}
