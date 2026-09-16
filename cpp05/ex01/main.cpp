/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:07:44 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/16 16:30:43 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "===== TEST 1 : CREATION =====" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 50);
		Form form("Form", 75, 50);

		std::cout << bob << std::endl;
		std::cout << form << std::endl;

		std::cout << "\n===== TEST 2 : SIGNATURE =====" << std::endl;

		bob.signForm(form);
		std::cout << form << std::endl;
		
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 3 : GRADE INSUFFISANT =====" << std::endl;

	try
	{
		Bureaucrat intern("Intern", 100);
		Form form("ImportantForm", 50, 50);

		std::cout << intern << std::endl;
		std::cout << form << std::endl;
		intern.signForm(form);

	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 4 : FORM DEJA SIGNE =====" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		Form form("Form", 50, 50);

		boss.signForm(form);
		boss.signForm(form);

		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 5 : GRADE INVALIDE DU FORM =====" << std::endl;

	try
	{
		Form formTooLow("TooLow", 151, 50);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form formTooHigh("TooHigh", 0, 50);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 6 : GRADE INVALIDE DU BUREAUCRAT =====" << std::endl;

	try
	{
		Bureaucrat tooLow("TooLow", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}