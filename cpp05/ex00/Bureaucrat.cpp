/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:48:05 by ttiprez           #+#    #+#             */
/*   Updated: 2026/07/30 18:31:43 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
Bureaucrat::Bureaucrat()
	: _name("Unknown"), _grade(150)
	{}
Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
	{_grade = grade;}
Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
	{}
Bureaucrat::~Bureaucrat()
	{}

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
