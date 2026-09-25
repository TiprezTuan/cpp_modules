#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Intern intern;

	std::cout << "===== TEST 1 : CREATION DES 3 FORMS VALIDES =====" << std::endl;
	{
		AForm* forms[3] = { NULL, NULL, NULL };

		try
		{
			forms[0] = intern.makeForm("shrubbery creation", "home");
			forms[1] = intern.makeForm("robotomy request", "Bender");
			forms[2] = intern.makeForm("presidential pardon", "Fry");

			for (int i = 0; i < 3; i++)
			{
				if (forms[i])
					std::cout << *forms[i] << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		for (int i = 0; i < 3; i++)
			delete forms[i];
	}

	std::cout << "\n===== TEST 2 : NOM DE FORM INCONNU =====" << std::endl;
	{
		AForm* bad = NULL;
		try
		{
			bad = intern.makeForm("time travel request", "Fry");
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "pointeur retourne : " << bad << std::endl;
		delete bad;
	}

	std::cout << "\n===== TEST 3 : CYCLE COMPLET (CREATION -> SIGNATURE -> EXECUTION) =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		AForm*     form = intern.makeForm("robotomy request", "Bender");

		if (form)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 4 : VERIFIER QUE LE TARGET EST BIEN CELUI PASSE =====" << std::endl;
	try
	{
		AForm* form = intern.makeForm("shrubbery creation", "test_target");

		if (form)
		{
			Bureaucrat boss("Boss", 1);
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 5 : PLUSIEURS FORMS DU MEME TYPE (VERIFIER QU'ON A BIEN DES OBJETS DISTINCTS) =====" << std::endl;
	try
	{
		AForm* f1 = intern.makeForm("presidential pardon", "Leela");
		AForm* f2 = intern.makeForm("presidential pardon", "Zoidberg");

		if (f1 && f2)
		{
			std::cout << *f1 << std::endl;
			std::cout << *f2 << std::endl;
			std::cout << "adresses differentes : " << (f1 != f2 ? "oui" : "NON -- BUG") << std::endl;
		}
		delete f1;
		delete f2;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}