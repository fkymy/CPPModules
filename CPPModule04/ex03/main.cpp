#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

#ifdef TEST

	{
		IMateriaSource *source = new MateriaSource();
		source->learnMateria(new Ice());
		source->learnMateria(new Cure());
		std::cout << "unknown type: " << source->createMateria("WHAT") << std::endl << std::endl;
	}

	{
		IMateriaSource *source = new MateriaSource();
		source->learnMateria(new Ice());
		source->learnMateria(new Cure());

		Character *a = new Character("A");
		Character *b = new Character("B");
		Character *enemy = new Character("bob");

		a->equip(source->createMateria("ice"));
		a->equip(source->createMateria("cure"));

		*b = *a;
		delete a;

		b->use(0, *enemy);
		b->use(1, *enemy);

		delete source;
		delete b;
		delete enemy;
	}

	{
		AMateria *a = new Ice();
		AMateria *b = new Ice();

		Character c("c");

		a->use(c);
		a->use(c);
		a->use(c);

		*b = *a;

		std::cout << "a XP: " << a->getXP() << std::endl;
		std::cout << "b XP: " << b->getXP() << std::endl;

		delete a;
		delete b;
	}

	{
		Ice *ice = new Ice();
		Character *a = new Character("A");

		a->equip(ice);
		a->unequip(0);

		std::cout << "use unequip materia" << std::endl;
		a->use(0, *a);

		delete ice;
		delete a;
	}
#endif

    return 0;
}
