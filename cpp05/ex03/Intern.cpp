/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:12:33 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/25 14:56:53 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/****************************/
/*		Type Definition		*/
/****************************/
typedef AForm* (*FormCreator)(std::string);

/****************************************/
/*		Exception Member Functions		*/
/****************************************/
const char* Intern::FormNameDoesNotExist::what() const throw()
{
	return "Form name does not exist !";
}

/************************************/
/*		Special Member Functions	*/
/************************************/
Intern::Intern()
	{}

Intern::Intern(const Intern& other)
	{(void) other;}

Intern::~Intern()
	{}

/************************************/
/*				Operator			*/
/************************************/
Intern&	Intern::operator=(const Intern& other)
	{(void) other; return	(*this);}

/************************************/
/*			Member Functions		*/
/************************************/
static AForm*	_createShrubbery(std::string target)
	{return (new ShrubberyCreationForm(target));}

static AForm*	_createRobotomy(std::string target)
	{return (new RobotomyRequestForm(target));}

static AForm*	_createPardon(std::string target)
	{return (new PresidentialPardonForm(target));}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	// Tout les form possibles
	static const std::string  formNames[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// Pointeurs sur fonction
	static FormCreator formCreators[] =
	{
		&_createShrubbery,
		&_createRobotomy,
		&_createPardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formCreators[i](target));
		}
	}

	throw FormNameDoesNotExist();
}