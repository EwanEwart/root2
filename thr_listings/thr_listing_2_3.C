#include <thread>

class thread_guard
{
    std::thread& t;

public:
    explicit thread_guard(std::thread& t_)
    : t(t_)
    {}

    ~thread_guard() // dtor
    {
        if(t.joinable())
        {
            t.join();
        }
    }
    /*
    The 
    copy constructor and 
    copy-assignment operator 
    are marked =delete  
    to ensure that they’re not automatically provided by the compiler. 
    Copying or assigning such an object would be dangerous, 
    because it might then outlive the scope of the thread it was joining. 
    By declaring them as deleted, 
    any attempt to copy a thread_ guard object 
    will generate a compilation error.
    */
    // copy ctor
    thread_guard(thread_guard const&)=delete; 
    // copy assignment ctor
    thread_guard& operator=(thread_guard const&)=delete; 
};

void do_something(int& i)
{
    ++i;
}

struct functor
{
    int& i; // ref

    functor(int& i_) // ref
    :i(i_)
    {}

    void operator()()
    {
        for(unsigned j{};j<1000000;++j)
        {
            do_something(i);
        }
    }
};

void do_something_in_current_thread()
{}


void f()
{
    int some_local_state;
    functor a_functor(some_local_state);

    std::thread t1(a_functor); // thread t1
    
    // let's say have wait for t1 to finish: need thread_guard
    // otherwise detach t1 
    thread_guard g(t1); 
        
    do_something_in_current_thread();
}

int thr_listing_2_3()
{
    f();
}
