#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include<sstream>
using std::istringstream;

#include <future>
using std::async;
using std::future;
using std::future_status;
using std::launch;

#include <chrono>
using namespace std::chrono_literals;

#include <string>
using std::string;

int main() // thread started by the C++ runtime
{
   future<string> userInput
   {
       async
       (
             launch::async
           , []()
           {
               string input;
               cin>>input;
               return input; 
           }
       )
   };
   // wait for input for 5 seconds
   future_status status { userInput.wait_for(5s) };
   if (status == future_status::ready)
   {
      cout << "User input received: " << userInput.get() << endl;
   }
   else
   {
      cout << "Timeout reached. No input received within 5 seconds." << endl;
   }

   return 0;
}
