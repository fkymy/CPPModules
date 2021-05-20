#include "ISquad.hpp"
#include "Squad.hpp"
#include <iostream>

int main()
{
    {
        Squad* s1 = new Squad;

        // test empty constructor
        std::cout << s1->getCount() << std::endl;
        std::cout << s1->getUnit(0) << std::endl;
        std::cout << s1->getUnit(-10) << std::endl;
        std::cout << s1->getUnit(100) << std::endl;

        // test copy constructor and assignment operator
        Squad s2 = *s1;
        Squad s3(s2);
        Squad *s4 = new Squad(s3);
        std::cout << s2.getCount() << std::endl;
        std::cout << s2.getUnit(0) << std::endl;
        std::cout << s3.getCount() << std::endl;
        std::cout << s3.getUnit(0) << std::endl;
        std::cout << s4->getCount() << std::endl;
        std::cout << s4->getUnit(0) << std::endl;
        delete s1;
        delete s4;
    }
    {
        Squad* s1 = new Squad;

        // test NULL push
        s1->push(NULL);

        // test same push
        ISpaceMarine* m1 = new TacticalMarine;
        s1->push(m1);
        s1->push(m1);

        ISpaceMarine* m2 = new AssaultTerminator;
        s1->push(m2);
        s1->push(m2);

    }


    // ISpaceMarine* m1

    // Squad* test2 = new Squad(*test1);

    // ISpaceMarine* bob = new TacticalMarine;
    // ISpaceMarine* jim = new AssaultTerminator;
    //
    // ISquad* vlc = new Squad;
    // vlc->push(bob);
    // vlc->push(jim);
    // for (int i = 0; i < vlc->getCount(); ++i)
    // {
    //     ISpaceMarine* cur = vlc->getUnit(i);
    //     cur->battleCry();
    //     cur->rangedAttack();
    //     cur->meleeAttack();
    // }
    //
    // delete vlc;

    return 0;
}
