/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:26:27 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/28 15:47:02 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <limits>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>

/****************************/
/*		Type Definition		*/
/****************************/
typedef bool (*TypeChecker)(const std::string& str);

/************************************/
/*		Special Member Functions	*/
/************************************/
ScalarConverter::ScalarConverter()	{}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
	{(void) other;}
ScalarConverter::~ScalarConverter()	{}

/************************************/
/*				Operator			*/
/************************************/
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
	{(void) other; return (*this);}

/********************************/
/*		Member Functions		*/
/********************************/
static bool isChar(const std::string& str)
{
	return 
	(
		str.length() == 1 &&
		str[0] >= 32 && str[0] <= 126 &&	// displayable
		(str[0] < 48 || str[0] > 57)		// not a digit
	);
}

static bool isInt(const std::string& str)
{
	if (str[0] != '-' && str[0] != '+' && (str[0] < 48 || str[0] > 57))
		return (false);
	for (int i = 1; str[i]; i++)
		if (str[i] < 48 || str[i] > 57)
			return (false);
	return (true);
}
static bool isFloat(const std::string& str)
{
	bool havePoint = false;
	if (str[0] != '-' && str[0] != '+' && (str[0] < 48 || str[0] > 57))
		return (false);
	for (int i = 1; str[i]; i++)
	{
		if (!str[i + 1])
		{
			if (str[i] != 'f')
				return (false);
			break;
		}
		if (str[i] == '.')
		{
			if (havePoint)
				return (false);
			havePoint = true;
		}
		else if (str[i] < 47 || str[i] > 57)
			return (false);
	}
	return (havePoint);
}
static bool isDouble(const std::string& str)
{
	bool havePoint = false;
	if (str[0] != '-' && str[0] != '+' && (str[0] < 48 || str[0] > 57))
		return (false);
	for (int i = 1; str[i]; i++)
		if (str[i] == '.')
		{
			if (havePoint)
				return (false);
			havePoint = true;
		}
		else if (str[i] < 47 || str[i] > 57)
			return (false);
	return (havePoint);
}


void		ScalarConverter::convert(const std::string& str)
{
	// Tout les types possibles
	static const std::string	typesAccepted[] =
	{
		"Char",
		"Int",
		"Float",
		"Double"
	};

	// Pointeurs sur fonctions
	static TypeChecker checkers[] =
	{
		&isChar,
		&isInt,
		&isFloat,
		&isDouble
	};

	for (int i = 0; i < 4; i++)
	{
		if (checkers[i](str))
			std::cout << str << " is a " << typesAccepted[i] << std::endl;
	}

	std::cout << std::endl;

	// Int
	bool	intSucceed = false;
	int		intValue;
	char*	endPtr;
	long	tmp_intValue;
	if (isInt(str))
	{
		tmp_intValue = std::strtol(str.c_str(), &endPtr, 10);
		if (*endPtr == '\0' && endPtr != str.c_str())
		{
			intValue = static_cast<int>(tmp_intValue);
			intSucceed = true;
		}
	}
	std::cout << "intValue = " << intValue << std::endl;
	
	// Char
	char	charValue;
	if (isChar(str))
		charValue = str[0];
	else if (intSucceed && intValue >= 32 && intValue <= 126)
		charValue = static_cast<char>(intValue);
	std::cout << "charValue = " << charValue << std::endl;

	// Float
	float	floatValue;
	float	tmp_floatValue;
	if (isFloat(str))
	{
		
		tmp_floatValue = std::strtof(str.c_str(), &endPtr);
		if (endPtr != str.c_str())
		{
			floatValue = tmp_floatValue;
		}
	}
	std::cout << std::fixed << std::setprecision(1) << "floatValue = " << floatValue << "f" << std::endl;
	
}
