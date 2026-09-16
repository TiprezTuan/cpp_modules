/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:17:54 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/16 16:26:20 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <string>

/****************************************/
/*		Exception Member Functions		*/
/****************************************/
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high !";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low !";
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return "already signed !";
}

/************************************/
/*		Special Member Functions	*/
/************************************/
Form::Form() :
	_name("Unknown"),
	_isSigned(false),
	_gradeToSign(checkGrade(1)),
	_gradeToExec(checkGrade(1))
	{}
Form::Form(std::string const name, int const gradeToSign, int const gradeToExec) : 
	_name(name),
	_isSigned(false),
	_gradeToSign(checkGrade(gradeToSign)),
	_gradeToExec(checkGrade(gradeToExec))
	{}
Form::Form(const Form &o) :	
	_name(o.getName()),
	_isSigned(o.getIsSigned()),
	_gradeToSign(o.getGradeToSign()),
	_gradeToExec(o.getGradeToExec())
	{}
Form::~Form() {}

/************************************/
/*				Operator			*/
/************************************/
Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other.getIsSigned();
	return (*this);
}

std::ostream& operator<<(std::ostream& o, const Form& f)
{
	o << f.getName() 
	<< ", form signed : " << f.getIsSigned() 
	<< ", grade required to sign it : " << f.getGradeToSign()
	<< ", grade required to execute it : " << f.getGradeToExec()
	<< ".";
	return (o);
}

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string	Form::getName()			const {return _name;}
bool		Form::getIsSigned()		const {return _isSigned;}
int			Form::getGradeToSign()	const {return _gradeToSign;}
int			Form::getGradeToExec()	const {return _gradeToExec;}

/************************************/
/*			Member Functions		*/
/************************************/
int		Form::checkGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	return grade;
}

void	Form::beSigned(Bureaucrat& b)
{	
	if (_isSigned)
		throw FormAlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}