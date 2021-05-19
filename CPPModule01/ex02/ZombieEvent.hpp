#ifndef ZOMBIE_EVENT_H
#define ZOMBIE_EVENT_H

#include <new>
#include <string>

#include "Zombie.hpp"

class ZombieEvent {
public:
    ZombieEvent();

    void setZombieType(int val);
    Zombie* newZombie(std::string name);

private:
    int type;
};

#endif
