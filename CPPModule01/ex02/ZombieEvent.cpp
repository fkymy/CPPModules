#include "ZombieEvent.hpp"

#include "Zombie.hpp"

ZombieEvent::ZombieEvent() : type(0) {}

void ZombieEvent::setZombieType(int val) { type = val; }

Zombie* ZombieEvent::newZombie(std::string name) {
    Zombie* zombie = new (std::nothrow) Zombie;
    if (zombie == 0) return (0);
    zombie->setType(type);
    zombie->setName(name);
    return zombie;
}
