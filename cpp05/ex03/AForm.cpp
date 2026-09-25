/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:19:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/22 15:51:41 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <string>

/****************************************/
/*		Exception Member Functions		*/
/****************************************/
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high !";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low !";
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return "already signed !";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "not signed !";
}

/************************************/
/*		Special Member Functions	*/
/************************************/
AForm::AForm() :
	_name("Unknown"),
	_isSigned(false),
	_gradeToSign(checkGrade(1)),
	_gradeToExec(checkGrade(1))
	{}
AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExec) : 
	_name(name),
	_isSigned(false),
	_gradeToSign(checkGrade(gradeToSign)),
	_gradeToExec(checkGrade(gradeToExec))
	{}
AForm::AForm(const AForm &o) :	
	_name(o.getName()),
	_isSigned(o.getIsSigned()),
	_gradeToSign(o.getGradeToSign()),
	_gradeToExec(o.getGradeToExec())
	{}
AForm::~AForm() {}

/************************************/
/*				Operator			*/
/************************************/
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other.getIsSigned();
	return (*this);
}

std::ostream& operator<<(std::ostream& o, const AForm& f)
{
	o << f.getName() 
	<< ", AForm signed : " << f.getIsSigned() 
	<< ", grade required to sign it : " << f.getGradeToSign()
	<< ", grade required to execute it : " << f.getGradeToExec()
	<< ".";
	return (o);
}

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string	AForm::getName()			const {return _name;}
bool		AForm::getIsSigned()		const {return _isSigned;}
int			AForm::getGradeToSign()	const {return _gradeToSign;}
int			AForm::getGradeToExec()	const {return _gradeToExec;}

/************************************/
/*			Member Functions		*/
/************************************/
int		AForm::checkGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	return grade;
}

void	AForm::beSigned(Bureaucrat& b)
{	
	if (_isSigned)
		throw FormAlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor)	const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	executeAction(executor);
}