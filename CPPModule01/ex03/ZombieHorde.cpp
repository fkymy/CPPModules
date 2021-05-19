#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) {
    const std::string names[] = {"yufukuya",  "fukuyama", "fukuyamay",
                                 "mayfukuya", "fkymy",    "yuskef",
                                 "yskf",      "yf"};

    if (N <= 0) {
        numZombies = 0;
        return;
    }

    zombies = new Zombie[N];
    for (int i = 0; i < N; ++i) {
        zombies[i].setType(i);
        zombies[i].setName(names[rand() % 8]);
    }
    numZombies = N;
}

ZombieHorde::~ZombieHorde() {
    if (numZombies <= 0) return;
    delete[] zombies;
}

void ZombieHorde::announce() const {
    for (int i = 0; i < numZombies; ++i)
        zombies[i].announce();
}
