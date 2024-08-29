// predicates
//
// prime attribute from ...
// https://www.geeksforgeeks.org/cpp-program-to-print-prime-numbers-from-1-to-n
// a number is prime if it is not divisible by any number from 2 to n-1.
// Time Complexity: O(N^2), Space Complexity: O(1)
auto prime = [](auto n)
{
   if(n<2)
      return false;
   for(int i = 2; i < n; ++i)
      if(n % i == 0)
         return false;
   return true;
};
// Time Complexity: O(N^2), Space Complexity: O(1)
auto prime2 = [](auto n)
{
   if(n<2)
      return false;
   for(int i = 2; i <= n/2; ++i)
      if(n % i == 0)
         return false;
   return true;
};
/* Approach 3:
If a number ‘n’ is not divided by any number 
less than or equals to the square root of n,
then it will not be divided by any other number
greater than the square root of n.
So, we only need to check up to the square root of n.

Time Complexity: O(N^(3/2)), Space Complexity: O(1)
*/
auto prime3 = [](auto n)
{
   if(n<2)
      return false;
   for(int i = 2; i*i <= n; ++i)
      if(n % i == 0)
         return false;   
   return true;
};
/*
Approach 4
Sieve of Eratosthenes Algorithm
-------------------------------
Create a boolean array is_prime of size (N+1),
initialised with true values for all elements.

Loop through the array is_prime from 2 to the square root of N (inclusive),
and for each prime number p found in the loop:

If is_prime[p] is true,
loop through the multiples of p from p*p up to N,
and mark them as false in the is_prime array.

Loop through the array is_prime from 2 to N (inclusive),
and for each index i where is_prime[i] is true,
print i as a prime number.

*/
//void sieve_of_eratosthenes(unsigned long long n)
void soe(unsigned long long n)
{
   bool is_prime[n + 1];
   memset(is_prime, true, sizeof(is_prime));
   is_prime[0] = is_prime[1] = false;
   for (unsigned long long p = 2; p * p <= n; ++p)
       if (is_prime[p])
           for (unsigned long long i = p * p; i <= n; i += p)
               is_prime[i] = false;
   for (long long i = 2; i <= n; ++i)
       if (is_prime[i])
           cout << i << " ";
   cout<<endl;
}

auto even = [](auto number){if(number%2)return false;return true;};
auto odd = [](auto number){if(number%2)return true;return false;};
auto everything = [](auto n){return true;};

// list numbers from 2 up to inclusive n, respecting a certain predicate
//
void lst(bool(*predicate)(int)=prime3,int n=100) {
   int c{n};
   if(n<2) c=2;
   for(auto i{2};i<=c;++i)
      if(predicate(i))
         cout<<i<<' ';
   cout<<endl;
}
// test bed
void list_numbers() {
   lst(); // defaults to lst(prim,100)
}

