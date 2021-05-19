#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    FragTrap f1("f1");
    FragTrap f2("f2");

    f1.rangedAttack("some target");
    f1.meleeAttack("some target");
    f2.rangedAttack("some target");

    f1.takeDamage(42);
    f2.takeDamage(1000);

    f1.beRepaired(10000);
    f2.beRepaired(1);

    f1.vaulthunter_dot_exe("some target");
    f1.vaulthunter_dot_exe("some target");
    f1.vaulthunter_dot_exe("some target");
    f1.vaulthunter_dot_exe("some target");
    f1.vaulthunter_dot_exe("some target");

    ScavTrap s1("s1");
    ScavTrap s2("s2");

    s1.rangedAttack("some target");
    s1.meleeAttack("some target");
    s2.rangedAttack("some target");

    s1.takeDamage(42);
    s2.takeDamage(1000);

    s1.beRepaired(10000);
    s2.beRepaired(1);

    s1.challengeNewcomer("some target");
    s1.challengeNewcomer("some target");
    s1.challengeNewcomer("some target");
    s1.challengeNewcomer("some target");
    s1.challengeNewcomer("some target");

    return 0;
}
