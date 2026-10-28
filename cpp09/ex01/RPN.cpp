/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:09:07 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/28 21:31:04 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

/************************************/
/*			Classic Functions		*/
/************************************/
static bool	isOperator(const std::string& token)
	{return (token.size() == 1 && std::string("-+/*").find(token[0]) != std::string::npos);}

static bool	isDigit(const std::string& token)
	{return (token.length() == 1 && token[0] >= '0' && token[0] <= '9');}

/************************************/
/*		Special Member Functions	*/
/************************************/
RPN::RPN(const std::string& expression)
	: _expression(expression)
	{}

RPN::RPN(const RPN& other)
	: _expression(other._expression)
	{}

RPN::~RPN()	{}

/************************************/
/*				Operator			*/
/************************************/
RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
		{_expression = other._expression;}
	return (*this);
}

/************************************/
/*			Member Functions		*/
/************************************/
int	RPN::calculate()	const
{
	std::stack<int>		expressionStack;
	std::istringstream	iss(_expression);
	std::string			token;

	while (iss >> token)
	{
		if (isDigit(token))
			expressionStack.push(token[0] - '0');
		else if (isOperator(token) && expressionStack.size() >= 2)
		{
			int	right = expressionStack.top();
			expressionStack.pop();
			int	left = expressionStack.top();
			expressionStack.pop();
			expressionStack.push(_operation(left, right, token[0]));
		}
		else
			throw std::runtime_error("Error");
	}

	if (expressionStack.size() != 1)
		throw std::runtime_error("Error");

	return (expressionStack.top());
}

int	RPN::_operation(int left, int right, char op)	const
{
	switch (op)
	{
		case '+': return (left + right);
		case '-': return (left - right);
		case '*': return (left * right);
		case '/':
			if (right == 0) throw std::runtime_error("Error");
			return (left / right);
	}
	throw std::runtime_error("Error");
}

