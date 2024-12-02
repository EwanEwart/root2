struct functor
{
	int& i;

	functor(int& i_) : i( i_ ) {};

	void operator()()
	{
		for(auto j{0}; j<100; ++j)
		{
			cout<<i<<'_';
		}
	};
};

// RAII
class thread_guard
{
	std::thread & t;
public:
	explicit thread_guard ( std::thread & t_ )
	: t(t_)
	{}
	~thread_guard()
	{
		if(t.joinable())
		{
			t.join();
			cout<<"the thread is joined";
		}
	}
	thread_guard ( thread_guard const& ) = delete; // copy ctor
	thread_guard & operator=( thread_guard const&) = delete; // copy assignment operator
};

// macro
void thread_ref_danger()
{
	cout << "joined"<<endl;
	{int z{ 7}; thread t (functor{z}); t.join()  ;if(t.joinable())cout<<"joinable"<<endl; else cout<<"not joinable anymore"<<endl;}
	cout << "detached"<<endl;
	{int z{-1}; thread t (functor{z}); t.detach();if(t.joinable())cout<<"joinable"<<endl; else cout<<"not joinable anymore"<<endl;}
	cout<<endl;

	// guard RAIA
	{int z( 9); thread t (functor{z}); thread_guard g {t}; cout<<"the thread is running"; };
	cout<<endl;
}
