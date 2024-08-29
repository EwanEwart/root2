// sum from to ...
template<typename T> T sft(T f, T t, T d=1) { T s{}; for(auto i{f}; i<=t; i+=d){s+=i;}return s;};

// test bed
void sum_from_to() {
   cout<<"sft(1,100)=   "<<sft(1,100  )<<endl;
   cout<<"sft(1,100,2)= "<<sft(1,100,2)<<endl;
   cout<<"sft(1,100,4)= "<<sft(1,100,4)<<endl;
   cout<<"sft(1,100,8)= "<<sft(1,100,8)<<endl;
}
