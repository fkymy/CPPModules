#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

const std::string names[] = {"yufukuya", "fukuyama", "fukuyamay", "mayfukuya",
                             "fkymy",    "yuskef",   "yskf", "yf"};

void randomChump(ZombieEvent& event) {
    std::string name = names[rand() % 8];
    Zombie *zombie = event.newZombie(name);
    zombie->announce();
    delete zombie;
}

int main() {
    ZombieEvent event;

    srand(static_cast<unsigned>(time(NULL)));

    for (int i = 0; i < 10; ++i) {
        event.setZombieType(i);
        randomChump(event);
    }

    return 0;
}
