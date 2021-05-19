#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    std::cout << "Horde 1" << std::endl;
    ZombieHorde horde1(0);
    horde1.announce();

    std::cout << "Horde 2" << std::endl;
    ZombieHorde horde2(-1);
    horde2.announce();

    std::cout << "Horde 3" << std::endl;
    ZombieHorde horde3(10);
    horde3.announce();

    system("leaks a.out");

    return 0;
}
