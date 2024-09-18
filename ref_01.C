#include <iostream>
#include <string_view>
#include <string>
#include <array>

using namespace std;

// base class
class Animal
{
protected:
    string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(string_view name)
        : m_name{name}
    {
    }

    // To prevent slicing (covered later)
    Animal(Animal const &) = default;
    Animal &operator=(Animal const &) = default;

public:
    string_view getName() const { return m_name; }
    // string_view speak() const { return "???"; }
    virtual string_view speak() const { return "???"; }
};

class Cat : public Animal
{
public:
    Cat(string_view name)
        : Animal{name}
    {
    }

    string_view speak() const { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(string_view name)
        : Animal{name}
    {
    }

    string_view speak() const { return "Woof"; }
};

// overloads
// void report(Cat const &cat)
// {
//     cout << cat.getName() << " says " << cat.speak() << endl;
// }
// void report(Dog const &dog)
// {
//     cout << dog.getName() << " says " << dog.speak() << endl;
// }

void report(Animal const &refAnimal)
{
    cout << refAnimal.getName() << " says " << refAnimal.speak() << endl;
}

// int ref_01()
int main()
{
    const Cat cat{"Fred"};
    cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << endl;

    const Dog dog{"Garbo"};
    cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << endl;

    const Animal *pAnimal{&cat};
    cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << endl;

    pAnimal = &dog;
    cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << endl;

    Dog kitty{"Kitty"};

    Dog &rDog{kitty};
    cout << "rDog is named " << rDog.getName() << ", and it says " << rDog.speak() << endl;

    // overloads
    report(cat);
    report(dog);
    cout << endl;

    // C++20
    // auto const &cats{std::to_array<Cat>({{"Fred"}, {"Misty"}, {"Zeke"}})};
    // auto const &dogs{std::to_array<Dog>({{"Garbo"}, {"Pooky"}, {"Truffle"}})};

    // Before C++20
    array<Cat, 3> const cats{{{"Fred"}, {"Misty"}, {"Zeke"}}};
    array<Dog, 3> const dogs{{{"Garbo"}, {"Pooky"}, {"Truffle"}}};

    for (const auto &cat : cats)
    {
        cout << cat.getName() << " says " << cat.speak() << endl;
    }
    cout << endl;

    for (const auto &dog : dogs)
    {
        cout << dog.getName() << " says " << dog.speak() << endl;
    }
    cout << endl;

    Cat const fred{"Fred"};
    auto & rFred{fred};
    Cat const misty{"Misty"};
    auto &rMisty{misty};
    Cat const zeke{"Zeke"};
    auto &rZeke{zeke};
    Dog const garbo{"Garbo"};
    auto &rGarbo{garbo};
    Dog const pooky{"Pooky"};
    auto &rPooky{pooky};
    Dog const truffle{"Truffle"};
    auto &rTruffle{truffle};

    cout << endl;

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    // const auto animals{ std::to_array<const Animal*>({&fred, &garbo, &misty, &pooky, &truffle, &zeke }) };

    // Before C++20, with the array size being explicitly specified
    array<Animal const *, 6> const pAnimals{&fred, &garbo, &misty, &pooky, &truffle, &zeke};
    for (auto const animal : pAnimals)
    {
        cout << animal->getName() << " says " << animal->speak() << '\n';
    }

    cout << endl;

// https://www.learncpp.com/cpp-tutorial/virtual-functions/

    return 0;
}
