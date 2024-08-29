template<typename T> T sum(T num) { return num; };
template<typename T, typename... Args>T sum(T num, Args... args) { return num + sum(args...);};

void sums() {
   // e.g. ...
   cout<<"sum(1) = "<<sum(1)<<endl;
   cout<<"sum(10) = "<<sum(1,2,3,4,5,6,7,8,9,10)<<endl;
}
