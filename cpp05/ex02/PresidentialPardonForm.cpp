/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:20:20 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/22 16:00:03 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

/************************************/
/*		Special Member Functions	*/
/************************************/
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("Unknown")
	{}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
	{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target)
	{}

PresidentialPardonForm::~PresidentialPardonForm()
	{}

/************************************/
/*				Operator			*/
/************************************/
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
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
void	PresidentialPardonForm::executeAction(Bureaucrat const & executor)	const
{
	(void)	executor;
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}