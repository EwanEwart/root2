#include <iostream>

int main()
{
   std::cin.sync_with_stdio(false); // Disable synchronization with C standard streams

   while (true)
   {
      // Check if there is any input available in the input buffer
      if (std::cin.rdstate() & std::ios_base::failbit)
      {
         std::cin.clear();
         std::cin.ignore();
         std::cout << '.';
         continue;
      }

      // Read input from std::cin if available
      std::string input;
      std::getline(std::cin, input);

      // Handle the input
      if (!input.empty())
      {
         std::cout << "Received input: " << input << std::endl;
      }
      else
      {
         std::cout << "No input available" << std::endl;
      }
   }

   return 0;
}
