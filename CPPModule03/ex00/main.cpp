#include "FragTrap.hpp"

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

    return 0;
}
