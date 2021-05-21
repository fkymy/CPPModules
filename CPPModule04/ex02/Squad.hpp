#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <iostream>

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad: public ISquad
{
    public:
        Squad();
        virtual ~Squad();

        Squad(const Squad& other);
        Squad& operator=(const Squad& other);

        virtual int getCount() const;
        virtual ISpaceMarine* getUnit(int) const;
        virtual int push(ISpaceMarine*);

    private:
        int count;
        ISpaceMarine** marines;
        void copyOther(const Squad& other);
        void clear();
};

#endif /* SQUAD_HPP */
