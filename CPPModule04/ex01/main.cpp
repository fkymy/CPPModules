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
    Character c("fuku");
    PlasmaRifle rifle = PlasmaRifle();
    AWeapon *weapon = new Sword();

    Enemy *mutant = new SuperMutant();

    c.equip(&rifle);
    std::cout << c;

    std::cout << "TEST DAMEGE" << std::endl;

    std::cout << "weapon damage: " << rifle.getDamage() << std::endl;
    std::cout << "enemy hp: " << mutant->getHP() << std::endl;
    c.attack(mutant);
    std::cout << "enemy hp: " << mutant->getHP() << std::endl;

    c.equip(weapon);
    std::cout << c;
    std::cout << "weapon damage: " << weapon->getDamage() << std::endl;
    std::cout << "enemy hp: " << mutant->getHP() << std::endl;
    c.attack(mutant);
    std::cout << "enemy hp: " << mutant->getHP() << std::endl;

    std::cout << "TEST AP" << std::endl;

    c.attack(mutant);
    std::cout << c;
    c.attack(mutant);
    std::cout << c;
    c.attack(mutant);
    std::cout << c;
    c.attack(mutant);
    std::cout << c;
    c.attack(mutant);
    std::cout << c;

    std::cout << "TEST RECOVERY" << std::endl;
    c.recoverAP();
    std::cout << c;
    c.recoverAP();
    std::cout << c;
    c.recoverAP();
#endif

    return 0;
}
