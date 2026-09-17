/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:48:05 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/16 16:30:18 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

/****************************************/
/*		Exception Member Functions		*/
/****************************************/
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low !";
}

/************************************/
/*		Special Member Functions	*/
/************************************/
Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(100) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}
Bureaucrat::~Bureaucrat() {}

/************************************/
/*				Operator			*/
/************************************/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string	Bureaucrat::getName(void) const {return _name;}
int			Bureaucrat::getGrade(void) const {return _grade;}

/****************************/
/*		Member Functions	*/
/****************************/
void	Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}
void	Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}