#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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

    NinjaTrap n1("n1");
    NinjaTrap n2("n2");

    n1.ninjaShoebox(f1);
    n1.ninjaShoebox(s1);
    n1.ninjaShoebox(n1);
    n1.ninjaShoebox(n2);

    SuperTrap super("super");
    super.takeDamage(66);
    super.beRepaired(12);
    super.rangedAttack("some target");
    super.meleeAttack("some target");
    super.vaulthunter_dot_exe("some target");
    super.ninjaShoebox(f1);
    super.ninjaShoebox(n1);
    super.ninjaShoebox(s1);

    return 0;
}
