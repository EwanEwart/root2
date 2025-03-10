/*
std::apply(f,t) :

Invokes the Callable object f
with the elements of t,
a tuple, delivering the arguments.

Returns : The value returned by f

Usage as a macro ...add_lambda3
$ .L applies.C
$ applies()
$
*/
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <tuple>
using std::apply;
using std::make_tuple;
using std::tuple;

#include <list>
using std::list;

#include <cstdint> // uint8_t, uint16_t, uint32_t
#include <math.h> // M_E, M_PI

list lst01{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
list lst02{"Mater", "Kate", "Ann", "Schnikellisl"};

// predicates
//
int add(int first, int second) { return first + second; }
template <typename T>
T add_generic(T first, T second) { return first + second; }
auto add_lambda = [](auto first, auto second)
{ return first + second; };
auto add_lambda3 = [](auto first, auto second, auto third)
{ return first + second + third; };

auto lstalst = [](auto const &lst)
{for(auto const& i:lst)cout<<i<<' ';cout<<endl; };
auto lstlsts = [](auto const &lst1, auto const &lst2)
{lstalst(lst1);lstalst(lst2); };

// pass tuple holding different types to inserter
//
template <typename... Ts>
ostream &operator<<(ostream &os, tuple<Ts...> const &theTuple)
{
   apply(
       [&os](Ts const &...tupleArgs)
       {
          os << '[';
          size_t n{0};
          // fold expression; refer to https://en.cppreference.com/w/cpp/language/fold
          // ( parameter_pack operator ... ) <- unary right fold
          // ( expression , ... )
          ((os << tupleArgs << (++n != sizeof...(Ts) ? ", " : "")), ...); // comma operator !
          os << ']';
       },
       theTuple);
   return os;
}

// fold examples
//

// Basic usage, folding variadic arguments over "operator<<"
template <typename... Args>
void printer(Args &&...args)
{
   (cout << ... << args) << endl; // binary left fold : (init op ... op pp)
}

// Folding an expression that uses the parameter pack directly over "operator,"
// Call, e.g. : print_limits < int, unsigned, char et cetera > ()
template <typename... Ts>
void print_limits() // print the maximum of a type
{
   size_t n{0};
   //          v--- make,e.g. char, numerical
   ((cout << +numeric_limits<Ts>::max() << (++n != sizeof...(Ts) ? " /  " : "")), ...) // urf : ( pp op ...)  comma operator
       << endl;
}

// test bed
//
void applies()
{
   cout << "1 + 2 = " << apply(add, tuple(1, 2)) << endl;
   cout << "2.0f + 3.0f = " << apply(add_generic<float>, make_tuple(2.0f, 3.0f)) << endl;
   cout << "5.0f + 7.0f = " << apply(add_lambda, make_tuple(5.0f, 7.0f)) << endl;
   cout << "11.0f + 13.0f + 17.0f = " << apply(add_lambda3, make_tuple(11.0f, 13.0f, 17.0f)) << endl;
   // lstlsts(lst01,lst02); // outputs to console
   apply(lstlsts, make_tuple(lst01, lst02)); // outputs to console

   // << tuple
   auto db_record{make_tuple(1, "Rachel", "Ewart", 91154, 2.347f, M_E, M_PI, 'a', 'b', 'c', false, 1E3)};
   cout << "db_record = " << db_record << endl;
   tuple aTuple{25, "a useful tuple", 9.31f, 'c'};
   cout << "aTuple = " << aTuple << '\n';

   // binary left fold : (initial op ... op pp)
   printer("printer(...) => ", 'A', 1, ' ', "B1", ' ', "Pi = ", M_PI);
   //
   print_limits<char, unsigned, uint8_t, uint16_t, uint32_t>();
}