template<typename T> T prd(T num) { return num; };
template<typename T, typename... Args>T prd(T num, Args... args) { return num * prd(args...);};
void prds() {
   // e.g. ...
   cout<<"prd(1) = "<<prd(1)<<endl;
   cout<<"prd(5) = "<<prd(1,2,3,4,5)<<endl;
}

