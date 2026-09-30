/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:10:11 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/30 15:34:10 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <climits>
#include <math.h>
#include <iostream>
#include <cfloat>
#include <iomanip>
#include <cstdlib>
#include <sstream>

/*********************************/
/*      Classic Functions        */
/*********************************/
static std::string	formatFloating(double value, bool isFloatType)
{
	std::ostringstream	oss;

	oss << value;
	std::string	s = oss.str();

	if (std::isinf(value) && value > 0 && s[0] != '+')
		s = "+" + s;
	if (s.find('.') == std::string::npos
		&& s.find("inf") == std::string::npos
		&& s.find("nan") == std::string::npos)
		s += ".0";
	if (isFloatType)
		s += "f";
	return (s);
}

/************************************/
/*      Special Member Functions    */
/************************************/
ScalarConverter::ScalarConverter()  {}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
	{(void) other;}
ScalarConverter::~ScalarConverter() {}

/************************************/
/*              Operator            */
/************************************/
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
	{(void) other; return (*this);}

/********************************/
/*      Member Functions        */
/********************************/
void		ScalarConverter::convert(const std::string& str)
{
	int		intValue = 0;
	float	floatValue = 0.0f;
	char	charValue = 0;
	double	doubleValue = 0.0;

	bool	doubleSucceed = false;
	bool	intSucceed = false;
	bool	floatSucceed = false;
	bool	charSucceed = false;
	bool	charIsPrintable = false;

	bool	isQuotedChar = (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
	bool	isBareChar = (str.length() == 1 && (str[0] < '0' || str[0] > '9'));


	/* ---- CONVERTION ---- */
	if (isQuotedChar || isBareChar)
	{
		charValue = isQuotedChar ? str[1] : str[0];
		charSucceed = true;
		if (charValue >= 32 && charValue <= 126)
			charIsPrintable = true;

		doubleValue = static_cast<double>(static_cast<unsigned char>(charValue));
		doubleSucceed = true;
		intValue = static_cast<int>(doubleValue);
		intSucceed = true;
		floatValue = static_cast<float>(doubleValue);
		floatSucceed = true;
	}
	else
	{
		char*	ptr;
		doubleValue = std::strtod(str.c_str(), &ptr);

		bool	isDouble = (*ptr == '\0' && ptr != str.c_str());
		bool	isFloat = (*ptr == 'f' && *(ptr + 1) == '\0' && ptr != str.c_str());

		if (isDouble || isFloat)
		{
			doubleSucceed = true;

			bool	special = std::isnan(doubleValue) || std::isinf(doubleValue);

			// Int
			if (!special && doubleValue <= INT_MAX && doubleValue >= INT_MIN)
			{
				intValue = static_cast<int>(doubleValue);
				intSucceed = true;
			}

			// Float
			if (special || (doubleValue <= FLT_MAX && doubleValue >= -FLT_MAX))
			{
				floatValue = static_cast<float>(doubleValue);
				floatSucceed = true;
			}

			// Char
			if (!special && doubleValue >= 0 && doubleValue <= 127)
			{
				charValue = static_cast<char>(doubleValue);
				charSucceed = true;
				if (charValue >= 32 && charValue <= 126)
					charIsPrintable = true;
			}
		}
	}

	/* ---- AFFICHAGE ---- */

	// Char
	if (charSucceed && charIsPrintable)
		std::cout << "char: '" << charValue << "'" << std::endl;
	else if (charSucceed && !charIsPrintable)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	// Int
	if (intSucceed)
		std::cout << "int: " << intValue << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	// Float
	if (floatSucceed)
		std::cout << "float: " << formatFloating(static_cast<double>(floatValue), true) << std::endl;
	else
		std::cout << "float: impossible" << std::endl;

	// Double
	if (doubleSucceed)
		std::cout << "double: " << formatFloating(doubleValue, false) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}