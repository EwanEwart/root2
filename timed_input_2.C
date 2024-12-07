#include <iostream>
#include <chrono>
#include <thread>

std::string readInputWithTimeout(int timeoutSec)
{
   std::string input;
   std::chrono::seconds timeout{timeoutSec};

   std::cout << "Enter your input within " << timeoutSec << " seconds: ";
   std::chrono::time_point<std::chrono::steady_clock> start_time = std::chrono::steady_clock::now();
   while (std::chrono::steady_clock::now() - start_time < timeout)
   {
      if (std::cin >> input)
      {
         std::cout<<'.';
         return input;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
   }

   return "";
}

int main() // thread started by the C++ runtime
{
   std::string userInput = readInputWithTimeout(5); // Timeout after 5 seconds

   if (!userInput.empty())
   {
      std::cout << "You entered: " << userInput << std::endl;
   }
   else
   {
      std::cout << "Timeout reached. No input received." << std::endl;
   }

   return 0;
}
