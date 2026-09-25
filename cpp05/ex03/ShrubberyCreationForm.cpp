/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:19:51 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/22 15:59:45 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <stdexcept>

/************************************/
/*		Special Member Functions	*/
/************************************/
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137)
	{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
	{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
	{}

ShrubberyCreationForm::~ShrubberyCreationForm()
	{}

/************************************/
/*				Operator			*/
/************************************/
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

/************************************/
/*			Member Functions		*/
/************************************/
void	ShrubberyCreationForm::executeAction(Bureaucrat const & executor)	const
{
	(void) executor;

	std::ofstream	file((_target + "_shrubbery").c_str());

	if (!file.is_open())
		throw std::runtime_error(_target + "_shrubbery: failed to open !");

	file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\";
	file.close();
}