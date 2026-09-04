/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:48:05 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/04 18:16:13 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

/************************************************/
/*		Exception Special Member Functions		*/
/************************************************/
Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooLowException::GradeTooLowException() {}

/****************************************/
/*		Exception Member Functions		*/
/****************************************/
const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade is too high !";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade is too low !";
}

/************************************/
/*		Special Member Functions	*/
/************************************/
Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	throw Bureaucrat::GradeTooLowException();
};
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {_grade = grade;}
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

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string	Bureaucrat::getName(void) const {return _name;}
int			Bureaucrat::getGrade(void) const {return _grade;}