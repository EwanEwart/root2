#include<random>
// multithreading randGen()
/*
   mt19937  - the classic Mersenne Twister 
            - employs a 32 bit Mersenne Twister algorithm 
               with a state size of 19937 bits 
            - a common and appropriate choice for most applications
   mt19937_64     - an alternative Mersenne Twister
   thread_local   - even though it is defined as a static variable, 
                     its scope will be limited to the thread using it.
                  - each thread will create its own generator instance, 
                    which is important 
                    when using the random number API in the STL
   hash - a hash of the internal thread identifier is used as a seed for the generator
            this ensures that each thread gets a fairly unique seed for its generator instance, 
            allowing for better random number sequences.
*/
int randGen(int const& min, int const& max) // range [min,max]
{
   static thread_local mt19937_64 generator(hash<thread::id>()(this_thread::get_id()));
   uniform_int_distribution distribution(min,max);
   return distribution(generator);
}
