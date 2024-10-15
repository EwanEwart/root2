// sum of an arbitrary number of numbers :
//
template<typename T>
T sum(T s){return s;};

template<typename T, typename... Args>
T sum(T s, Args... args)
{
	return s + sum(args...);
};

// C++17 unfold expression
// Refer to : https://en.cppreference.com/w/cpp/language/fold
/* 
In this example the *Unary Right Fold*,

(args + ...)

is the fold expression that expands to

(1 + (2 + (3 + (4 + (5 + (6 + (7 + (8 + (9 + (10)))))))))),

resulting in a sum of all elements in the parameter pack.
*/
// The sum of all elements in a parameter pack using the addition operator:
template<typename... Args>
auto sumCpp17(Args... args)
{
    return (args + ...); // fold expression Unary right Fold : (parameter pack op ...)
}

template<typename... Args>
auto mul_unary_right_fold(Args... args)
{
	return (args * ...);
}

template<typename... Args>
auto mul_unary_left_fold(Args... args)
{
	return (... * args);
}

template<typename... Args>
auto min_unary_right_fold(Args... args)
{
	return (args - ...);
}

template<typename... Args>
auto min_unary_left_fold(Args... args)
{
	return (... - args);
}

// Both a fold over operator&& using the parameter pack
// and over operator, using the variadic arguments
// append several elements to the given vector
template<typename T, typename... Args>
void push_back_vec(std::vector<T>& v, Args&&... args)
{
    static_assert((std::is_constructible_v<T, Args&&> && ...)); // unary right fold expression, urf: (parameter_pack operator ...) / operator&&
    (v.push_back(std::forward<Args>(args)), ...);					// unary right fold expression, urf: (parameter_pack operator ...) / operator,
}

// test bed
void sums() {
	cout<<"sum(1) = "<<sum(1)<<endl;
	cout<<"sum(1,2,3,4,5,6,7,8,9,10) = "<<sum(1,2,3,4,5,6,7,8,9,10)<<endl;
	// C++17
	cout << "sum(1,10) = " << sumCpp17(1,2,3,4,5,6,7,8,9,10) << endl;

	cout << "mul_unary_right_fold(1,5) = " << mul_unary_right_fold(1,2,3,4,5) << endl;
	cout << "mul_unary_left_fold(1,5) = " << mul_unary_left_fold(1,2,3,4,5) << endl;

	vector<int> v1;
	push_back_vec(v1,1,2,3);
	for(auto i:v1)cout<<i<<' ';cout<<endl;
	push_back_vec(v1,4,5,6);
	for(auto i:v1)cout<<i<<' ';cout<<endl;
	
}
