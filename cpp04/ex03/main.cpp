/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:17:04 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 17:02:36 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	std::cout << "\n=== Test du sujet ===" << std::endl;
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
	}

	std::cout << "\n=== Test inventaire plein ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));
		me->equip(src->createMateria("cure"));
		// inventaire plein, cette materia doit etre ignoree
		AMateria* extra = src->createMateria("ice");
		me->equip(extra);
		std::cout << "(materia ignoree car inventaire plein, delete manuel)" << std::endl;
		delete extra;

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n=== Test unequip ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		ICharacter* me = new Character("me");
		AMateria* ice = src->createMateria("ice");
		me->equip(ice);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);

		me->unequip(0); // retire sans delete
		std::cout << "(slot 0 vide, use ne doit rien faire)" << std::endl;
		me->use(0, *bob); // ne doit rien faire

		delete ice; // on doit delete manuellement apres unequip
		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n=== Test deep copy Character ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character* me = new Character("me");
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));

		Character* copy = new Character(*me); // copy constructor
		ICharacter* bob = new Character("bob");

		std::cout << "--- me use ---" << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << "--- copy use ---" << std::endl;
		copy->use(0, *bob);
		copy->use(1, *bob);

		delete me;   // ne doit pas corrompre copy
		std::cout << "--- copy use apres delete me ---" << std::endl;
		copy->use(0, *bob);

		delete bob;
		delete copy;
		delete src;
	}

	std::cout << "\n=== Test type inconnu ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		AMateria* unknown = src->createMateria("fire");
		if (!unknown)
			std::cout << "createMateria(\"fire\") retourne NULL : OK" << std::endl;
		else
		{
			std::cout << "createMateria(\"fire\") ne retourne pas NULL : KO" << std::endl;
			delete unknown;
		}

		delete src;
	}

	std::cout << "\n=== Fin des tests ===" << std::endl;
	return 0;
}