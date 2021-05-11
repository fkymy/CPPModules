#include <string>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() {
    type = 0;
}

void ZombieEvent::setZombieType(int val) {
    type = val;
}

Zombie* ZombieEvent::newZombie(std::string name) {
    Zombie *zombie = new Zombie;
    if (!zombie)
        return (NULL);
    zombie->setType(type);
    zombie->setName(name);
    return zombie;
}

ZombieEvent::~ZombieEvent() {

}
