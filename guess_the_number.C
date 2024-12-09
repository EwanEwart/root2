#include <iostream>
#include <string>
using namespace std;

#include "mt_randGen.H"

int random_number(int min, int max)
{
   if (min < max)
      return randGen(min, max);
   else
      return randGen(max, min);
}
void guess_the_number()
{
   cout << ">> Press ctrl-d to terminate the program." << endl;

   // min
   cout << ">> Enter min ... ";
   string str_min;
   cin >> str_min;
   auto min{atoi(str_min.c_str())};

   // max
   cout << ">> Enter max ... ";
   string str_max;
   cin >> str_max;
   auto max{atoi(str_max.c_str())};

   auto carry_on{true};
   for (; carry_on;)
   {
      // random number
      auto rn{random_number(min, max)};
      for (;;)
      {
         string str_guess;
         cout << ">> Guess the number: ... ";
         cin >> str_guess;
         auto guess{atoi(str_guess.c_str())};

         if (str_guess.empty())
         {
            cout << endl;
            carry_on = false;
            break;
         }

         cout << ">> Your guess: " << guess << endl;
         if (guess == rn)
         {
            cout << ">> *** Congratulations *** You guessed the number ! ***" << endl;
            carry_on = true;
            break;
         }
         else
         {
            if (rn < guess)
            {
               cout << '(' << rn << ')' << " < " << guess << endl;
            }
            else
            {
               cout << guess << " < " << '(' << rn << ')' << endl;
            }
         }
      }
   }
}

int main(int argc, char const *argv[])
{
   guess_the_number();
   return 0;
}
