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
void get_int(int &val, string const &prompt)
{
   cout << ">> " << prompt;
   string str_val;
   cin >> str_val;
   if (str_val.empty())
   {
      cout << endl;
      exit(-1);
   }
   else
   {
      val = atoi(str_val.c_str());
   }
}
void guess_the_number()
{
   cout << ">> Press ctrl-d to terminate the program." << endl;

   int min;
   get_int(min, "Enter min ... ");

   int max;
   get_int(max, "Enter max ... ");

   auto carry_on{true};
   for (; carry_on;)
   {
      // random number
      auto rn{random_number(min, max)};
      for (;;)
      {
         int guess;
         get_int(guess, "Guess the number: ... ");

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
               cout << '(' << rn << ')' << " < " << guess << endl;
            else
               cout << guess << " < " << '(' << rn << ')' << endl;
         }
      }
   }
}

int main(int argc, char const *argv[])
{
   guess_the_number();
   return 0;
}
