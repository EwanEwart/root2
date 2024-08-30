// sum of an arbitrary number of numbers :
//
template<typename T> T sum(T s){return s;};
template<typename T, typename... Args> T sum(T s, Args... args){return s + sum(args...);};
// test bed
void sums() {
	cout<<"sum(1) = "<<sum(1)<<endl;
	cout<<"sum(1,2,3,4,5,6,7,8,9,10) = "<<sum(1,2,3,4,5,6,7,8,9,10)<<endl;
}

