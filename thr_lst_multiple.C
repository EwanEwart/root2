#include<iostream>
#include<thread>
using namespace std;

// run multiple threads

// worker 1
auto w1
{
	[](unsigned s,char c='.')
	{
		for(auto i{s};s;--s)
		{
			this_thread::sleep_for( chrono::seconds{1} );
			cout << c;
			cout.flush();
		}
	}
};

void threads_multiple() {

	unsigned s{20};

	thread t1(w1,s,'^');
	thread t2(w1,s,'-');
	thread t3(w1,s,'_');

	t1.join();
	t2.join();
	t3.join();	

	cout<<endl;
}
