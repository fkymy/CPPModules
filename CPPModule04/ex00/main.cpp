#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Servant.hpp"

int main()
{
    Sorcerer robert("Robert", "the Magnificent");

    Victim jim("Jimmy");
    Peon joe("Joe");

    std::cout << robert << jim << joe;

    robert.polymorph(jim);
    robert.polymorph(joe);

#ifdef TEST
    Servant s1("s1");
    Servant s2("s2");
    std::cout << s1 << s2 << std::endl;
    robert.polymorph(s1);

    Victim* victim = new Peon("p1");
    std::cout << *victim;
    robert.polymorph(*victim);
    delete victim;
#endif

    return 0;
}
