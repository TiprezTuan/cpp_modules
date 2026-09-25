/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 15:54:45 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/25 14:46:53 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "===== TEST 1 : CREATION DES FORMS =====" << std::endl;
	try
	{
		ShrubberyCreationForm	sc("home");
		RobotomyRequestForm	rr("Bender");
		PresidentialPardonForm	pp("Fry");

		std::cout << sc << std::endl;
		std::cout << rr << std::endl;
		std::cout << pp << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 2 : EXECUTE SANS SIGNATURE =====" << std::endl;
	try
	{
		Bureaucrat				boss("Boss", 1);
		ShrubberyCreationForm	sc("garden");

		sc.execute(boss);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 3 : SIGNATURE PUIS GRADE INSUFFISANT POUR EXECUTER =====" << std::endl;
	try
	{
		Bureaucrat			intern("Intern", 150);
		RobotomyRequestForm	rr("Bender");

		intern.signForm(rr);
		std::cout << rr << std::endl;
		rr.execute(intern);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 4 : SIGNATURE + EXECUTION REUSSIE (SHRUBBERY) =====" << std::endl;
	try
	{
		Bureaucrat				boss("Boss", 1);
		ShrubberyCreationForm	sc("backyard");

		boss.signForm(sc);
		std::cout << sc << std::endl;
		sc.execute(boss);
		std::cout << "-> fichier backyard_shrubbery cree, va verifier son contenu" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 5 : SIGNATURE + EXECUTION REUSSIE (ROBOTOMY, x5 pour voir le random) =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);

		for (int i = 0; i < 5; i++)
		{
			RobotomyRequestForm rr("Bender");
			boss.signForm(rr);
			rr.execute(boss);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 6 : SIGNATURE + EXECUTION REUSSIE (PRESIDENTIAL PARDON) =====" << std::endl;
	try
	{
		Bureaucrat				boss("Boss", 1);
		PresidentialPardonForm	pp("Fry");

		boss.signForm(pp);
		std::cout << pp << std::endl;
		pp.execute(boss);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 7 : DOUBLE SIGNATURE =====" << std::endl;
	try
	{
		Bureaucrat				boss("Boss", 1);
		ShrubberyCreationForm	sc("park");

		boss.signForm(sc);
		boss.signForm(sc);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 8 : GRADE INVALIDE A LA CREATION D'UN FORM =====" << std::endl;
	try
	{
		Bureaucrat				weakBoss("WeakBoss", 100);
		PresidentialPardonForm	pp("Leela");

		weakBoss.signForm(pp); // grade 100 < requis 25 pour signer -> doit throw dans beSigned
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 9 : COPIE ET ASSIGNATION =====" << std::endl;
	try
	{
		Bureaucrat				boss("Boss", 1);
		ShrubberyCreationForm	sc1("original");
		boss.signForm(sc1);

		ShrubberyCreationForm	sc2(sc1); // copy constructor : doit garder isSigned = true
		std::cout << "sc2 (copie de sc1 signee) : " << sc2 << std::endl;

		ShrubberyCreationForm	sc3("unsigned_target");
		sc3 = sc1; // operator= : doit copier isSigned, mais PAS target/name si bien fait
		std::cout << "sc3 (apres = sc1) : " << sc3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 10 : SIGNATURE + EXECUTION REUSSIE (Bureaucrat) =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pp("Leela");
		boss.signForm(pp);
		boss.executeForm(pp);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}