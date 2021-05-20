#include <string>
#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Alien.hpp"
#include "Sword.hpp"

int main()
{
    Character* me = new Character("me");

    std::cout << *me;

    Enemy* b = new RadScorpion();

    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();

    me->equip(pr);
    std::cout << *me;
    me->equip(pf);

    me->attack(b);
    std::cout << *me;
    me->equip(pr);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;

#ifdef TEST

    Enemy *enemy = new Alien();
    AWeapon *weapon = new Sword();

    me->equip(weapon);
    std::cout << *me;

    me->attack(NULL);

    me->equip(NULL);

    me->attack(enemy);

    me->equip(weapon);
    me->attack(enemy);

    std::cout << *me << *me;

#endif

    return 0;
}
