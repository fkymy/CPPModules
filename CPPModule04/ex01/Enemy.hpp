#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy
{
    protected:
        int hp;
        std::string type;

        Enemy();

    public:
        Enemy(int hp, std::string const & type);
        Enemy(const Enemy& other);
        Enemy& operator=(const Enemy& other);
        virtual ~Enemy();

        std::string const & getType() const;
        int getHP() const;

        virtual void takeDamage(int);
};

#endif /* ENEMY_HPP */
