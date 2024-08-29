// std::apply
//
list lst01 {1,2,3,4,5,6,7,8,9,10};
list lst02 {"Mater","Kate","Ann","Schnikellisl"};

// predicates
//
int add(int first, int second) { return first + second; }
template<typename T>
T add_generic(T first, T second) { return first + second; }
auto add_lambda = [](auto first, auto second) { return first + second; };
auto add_lambda3 = [](auto first, auto second, auto third) { return first + second + third; };

auto lstalst = [](auto const& lst){for(auto const& i:lst)cout<<i<<' ';cout<<endl;};
auto lstlsts = [](auto const& lst1, auto const& lst2){lstalst(lst1);lstalst(lst2);};

// test bed
//
void applies() 
{
   cout << apply(add, tuple(1, 2)) << endl;
   cout << apply(add_generic<float>, make_tuple(2.0f, 3.0f)) << endl;
   cout << apply(add_lambda, make_tuple(5.0f, 7.0f)) << endl;
   cout << apply(add_lambda3, make_tuple(11.0f, 13.0f, 17.0f)) << endl;
   cout << lstlsts(lst01,lst02);
   //cout << apply(lstlsts, make_tuple(lst01,lst02)) << endl;
}

