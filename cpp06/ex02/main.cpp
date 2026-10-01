/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 13:28:51 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/01 15:19:58 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

/****************************/
/*			Functions		*/
/****************************/
Base* generate(void)
{
	int num = rand() % 3;

	return (num == 0
			? static_cast<Base*>(new A)
			: (num == 1 ? static_cast<Base*>(new B)
			: static_cast<Base*>(new C)));
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Other" << std::endl;
}

void	identify(Base& p)
{
	try {(void)dynamic_cast<A&>(p); std::cout << "A" << std::endl;}
	catch (const std::exception&)
	{
		try {(void)dynamic_cast<B&>(p); std::cout << "B" << std::endl;}
		catch (const std::exception&)
		{
			try {(void)dynamic_cast<C&>(p); std::cout << "C" << std::endl;}
			catch (const std::exception&)
			{
				std::cout << "other" << std::endl;
			}
		}
	}
}

/************************/
/*			Main		*/
/************************/
int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "===== TEST 1 : TYPES CONNUS (pointeur) =====" << std::endl;
	{
		A a;
		B b;
		C c;

		Base* pa = &a;
		Base* pb = &b;
		Base* pc = &c;

		std::cout << "attendu A -> "; identify(pa);
		std::cout << "attendu B -> "; identify(pb);
		std::cout << "attendu C -> "; identify(pc);
	}

	std::cout << "\n===== TEST 2 : TYPES CONNUS (reference) =====" << std::endl;
	{
		A a;
		B b;
		C c;

		std::cout << "attendu A -> "; identify(static_cast<Base&>(a));
		std::cout << "attendu B -> "; identify(static_cast<Base&>(b));
		std::cout << "attendu C -> "; identify(static_cast<Base&>(c));
	}

	std::cout << "\n===== TEST 3 : generateRandom() x20, pour voir si les 3 types sortent =====" << std::endl;
	{
		int countA = 0, countB = 0, countC = 0;

		for (int i = 0; i < 20; i++)
		{
			Base* random = generate();
			identify(random);
			identify(*random); // la reference doit donner le meme resultat que le pointeur

			// comptage manuel via dynamic_cast, pour verifier independamment ta fonction identify
			if (dynamic_cast<A*>(random)) countA++;
			else if (dynamic_cast<B*>(random)) countB++;
			else if (dynamic_cast<C*>(random)) countC++;

			delete random; // generateRandom() alloue dynamiquement -> penser a liberer
		}

		std::cout << "\nrepartition sur 20 tirages (controle independant) : "
				  << "A=" << countA << " B=" << countB << " C=" << countC << std::endl;
	}

	std::cout << "\n===== TEST 4 : COHERENCE POINTEUR / REFERENCE =====" << std::endl;
	{
		Base* random = generate();

		std::cout << "via pointeur : "; identify(random);
		std::cout << "via reference : "; identify(*random);
		std::cout << "-> les deux lignes ci-dessus doivent annoncer le MEME type" << std::endl;

		delete random;
	}

	return 0;
}
