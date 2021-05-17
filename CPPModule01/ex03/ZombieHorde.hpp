#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {
public:
    explicit ZombieHorde(int N);
    ~ZombieHorde();

    void announce() const;

private:
    Zombie* zombies;
    int numZombies;
};

#endif /* ZOMBIEHORDE_HPP */
