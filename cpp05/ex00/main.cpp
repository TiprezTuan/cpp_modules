/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 17:23:00 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/11 17:24:02 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--- TEST 1 : Bureaucrate valide et operateur << ---" << std::endl;
	try
	{
		Bureaucrat hercules("Hercules", 2);
		std::cout << hercules << std::endl;
		
		hercules.incrementGrade();
		std::cout << "Apres incrementation : " << hercules << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception attrapee : " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2 : Grade trop haut au constructeur (0) ---" << std::endl;
	try
	{
		Bureaucrat boss("The Boss", 0);
		std::cout << boss << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception attrapee : " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 3 : Grade trop bas au constructeur (151) ---" << std::endl;
	try
	{
		Bureaucrat stagiaire("Stagiaire", 151);
		std::cout << stagiaire << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception attrapee : " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 4 : Depassement de limite haute (Incrementation de 1) ---" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		std::cout << president << std::endl;
		president.incrementGrade();
		std::cout << "Ce message ne doit pas s'afficher !" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception attrapee : " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 5 : Depassement de limite basse (Decrementation de 150) ---" << std::endl;
	try
	{
		Bureaucrat esclave("Esclave", 150);
		std::cout << esclave << std::endl;
		esclave.decrementGrade();
		std::cout << "Ce message ne doit pas s'afficher !" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception attrapee : " << e.what() << std::endl;
	}

	return (0);
}
