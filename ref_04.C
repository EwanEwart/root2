#include <iostream>
#include <string_view>
#include <vector>
#include <functional> // for reference_wrapper

using namespace std;

/*
use a reference_wrapper type/class, 
that mimics an reassignable reference
*/
class Base
{
protected:
    int m_value{};

public:
    Base(int value)
    : m_value{ value }
    {
    }
    virtual ~Base() = default;

    virtual string_view getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
    Derived(int value)
    : Base{ value }
    {
    }

    string_view getName() const override { return "Derived"; }
};

int ref_04()
{
   // a vector of reassignable references to Base
	vector<reference_wrapper<Base>> v{};

	Base b{ 5 }; // b and d can't be anonymous objects
	Derived d{ 6 };

	v.push_back(b); // add a Base object to our vector
	v.push_back(d); // add a Derived object to our vector

	// Print all of the elements of the vector
	// use the .get() method to retrieve the element of the reference_wrapper

   // an element has the type reference_wrapper<Base> const&
	for (auto const & element : v)
   {
		cout
      << "I am of type "
      << element.get().getName()
      << " holding value "
      << element.get().getValue()
      << endl
      ;
   }

	return 0;
}
