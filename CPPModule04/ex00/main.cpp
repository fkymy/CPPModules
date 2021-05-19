#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "TestDerived.hpp"

int main()
{
    Sorcerer robert("Robert", "the Magnificent");

    Victim jim("Jimmy");
    Peon joe("Joe");

    std::cout << robert << jim << joe;

    robert.polymorph(jim);
    robert.polymorph(joe);

#ifdef TEST
    TestDerived test1("test1");
    TestDerived test2("test2");
    std::cout << test1 << test2 << std::endl;
    robert.polymorph(test1);

    Victim* test3 = new Peon("test3");
    std::cout << *test3;
    robert.polymorph(*test3);
    delete test3;
#endif

    return 0;
}
