/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:20:04 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/22 16:00:31 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

/************************************/
/*		Special Member Functions	*/
/************************************/
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("Unknown")
	{}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
	{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
	{}

RobotomyRequestForm::~RobotomyRequestForm()
	{}

/************************************/
/*				Operator			*/
/************************************/
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
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
void	RobotomyRequestForm::executeAction(Bureaucrat const & executor)	const
{
	(void)	executor;
	std::cout << "*Some drilling noises*" << std::endl;

	if (std::rand() % 2)
		std::cout << _target << "has been robotomized" << std::endl ;
	else
		std::cout << _target << " robotomy failed" << std::endl;
}