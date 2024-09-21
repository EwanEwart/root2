#include <iostream>
#include <string_view>

using namespace std;

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

    virtual string_view getName () const { return "Base"; }
    int                 getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

   string_view getName() const override { return "Derived"; }
};

void ref_03()
{
    Derived derived{ 5 };

    Base base{ derived }; // what happens here? will be sliced
    
    cout << "base is of type " << base.getName() << " (sliced) and has value " << base.getValue() << endl;
}

/*
base is a Base and has value 5 <= sliced
*/
