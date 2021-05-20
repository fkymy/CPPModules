#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine {
public:
    TacticalMarine();
    TacticalMarine(const TacticalMarine& other);
    TacticalMarine& operator=(const TacticalMarine& other);
    virtual ~TacticalMarine();

    virtual ISpaceMarine* clone() const;
    virtual void battleCry() const;
    virtual void rangedAttack() const;
    virtual void meleeAttack() const;
};

#endif /* TACTICALMARINE_HPP */
