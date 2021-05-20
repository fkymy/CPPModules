#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class AssaultTerminator: public ISpaceMarine {
public:
    AssaultTerminator();
    AssaultTerminator(const AssaultTerminator& other);
    AssaultTerminator& operator=(const AssaultTerminator& other);
    ~AssaultTerminator();

    virtual ISpaceMarine* clone() const;
    virtual void battleCry() const;
    virtual void rangedAttack() const;
    virtual void meleeAttack() const;
};

#endif /* ASSAULTTERMINATOR_HPP */
