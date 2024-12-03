#include <iostream>
#include <iomanip>
#include <random>
#include <functional> // bind
#include <map>
#include <thread>
using namespace std;

auto const dip_size{6};
auto const no_of_dips{4};

#include "mt_randGen.H" // multithreading randGen()

/////////////////////
// #define ONE 1
// #define TWO 1
#define THREE 1
////////////////////
void lottery_gen()
{
#ifdef ONE
   // init
   random_device r; // Seed with a real random value, if available
   default_random_engine e(r());
   uniform_int_distribution d(1, 49);
   auto rn = bind(d, e);

   // apply
   for (auto l{1}; l <= no_of_dips; ++l)
   {
      for (auto k{1}; k <= dip_size; ++k)
         cout << rn() << ' ';
      cout << endl;
   }
#endif

#ifdef TWO
   // Seed with a real random value, if available
   random_device r;

   // Choose a random mean between 1 and 6
   default_random_engine e(r());
   uniform_int_distribution<int> d(1, 6);
   int mean = d(e);
   cout << "Randomly-chosen mean out of [1,6]: " << mean << '\n';

   // Generate a normal distribution around that mean
   seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()};
   mt19937 e2(seed2);
   normal_distribution<> normal_dist(mean, 2);

   map<int, int> hist;
   for (int n{}; n != 10000; ++n)
      ++hist[round(normal_dist(e2))];

   cout
       << "Normal distribution around "
       << mean
       << ":\n"
       << fixed << setprecision(1);
   for (auto [x, y] : hist)
      cout << setw(2) << x << ' ' << string(y / 200, '*') << '\n';
#endif

#ifdef THREE
   string line(20, '-');

#define NO_OF_LOTTERY_DIPS 12
#define SIZE_OF_A_DIP 6
#define RANGE_MIN 1
#define RANGE_MAX 49

   auto rg = bind(randGen, RANGE_MIN, RANGE_MAX);
   cout << line << endl;
   for (auto l{NO_OF_LOTTERY_DIPS}; l; --l)
   {
      for (auto k{SIZE_OF_A_DIP}; k; --k)
         cout << rg() << ' ';
      cout << endl;
   }
   cout << line << endl;
#endif
}
