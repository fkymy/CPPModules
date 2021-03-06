#include "Enemy.hpp"

Enemy::Enemy() {}

Enemy::Enemy(int hp, std::string const& type) : hp(hp), type(type) {}

Enemy::Enemy(const Enemy& other) {
    type = other.type;
    hp = other.hp;
}

Enemy& Enemy::operator=(const Enemy& other) {
    if (this != &other) {
        type = other.type;
        hp = other.hp;
    }
    return *this;
}

Enemy::~Enemy() {}

void Enemy::takeDamage(int amount) {
    if (amount > 0) {
        hp -= amount;
        if (hp < 0) hp = 0;
    }
}

std::string const& Enemy::getType() const { return type; }

int Enemy::getHP() const { return hp; }
