/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:20:21 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/28 20:05:43 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iterator>
#include <cstdlib>

/************************************/
/* 			Classic Functions		*/
/************************************/
static bool	isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

static bool	isValidDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	for (std::string::size_type i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return (false);
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || day < 1 || month > 12)
		return (false);

	static const int	daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int					maxDay = daysInMonth[month - 1];

	if (month == 2 && isLeapYear(year))
		maxDay = 29;

	return (day <= maxDay);
}

static std::string	trim(const std::string& s)
{
	std::string::size_type	start = s.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return ("");
	
	std::string::size_type	end = s.find_last_not_of(" \t\r\n");
	return (s.substr(start, end - start + 1));
}

/************************************/
/*		Special Member Functions	*/
/************************************/
BitcoinExchange::BitcoinExchange(const std::string& bitcoinRates_path)
{
	std::ifstream	file(bitcoinRates_path.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open file.");

	std::string		line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::string::size_type	pos = line.find(',');
		if (pos == std::string::npos)
			continue;	// Ligne mal faite

		std::string	date = line.substr(0, pos);
		std::string	sprice = line.substr(pos + 1);
		std::istringstream	iss(sprice);
		double				price;
		if (!(iss >> price))
			continue;	// prix invalide

		_bitcoinRates[date] = price;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _bitcoinRates(other._bitcoinRates)
	{}

BitcoinExchange::~BitcoinExchange() {}

/************************************/
/*				Operator			*/
/************************************/
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		{_bitcoinRates = other._bitcoinRates;}
	return (*this);
}

/****************************/
/*		Member Functions	*/
/****************************/
void	BitcoinExchange::displayBitcoinValues(const std::string& inputData_path)	const
{
	std::ifstream	file(inputData_path.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open file.");

	std::string		line;
	std::getline(file, line);	// en-tete

	while (std::getline(file, line))
	{
		if (trim(line).empty())
			continue;

		std::string::size_type	pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = trim(line.substr(0, pos));
		std::string	svalue = trim(line.substr(pos + 1));

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		std::istringstream	iss(svalue);
		double				value;
		char				extra;
		if (!(iss >> value) || (iss >> extra))
			{std::cerr << "Error: bad input => " << line << std::endl; continue;}
		if (value < 0)
			{std::cerr << "Error: not a positive number." << std::endl; continue;}
		else if (value > 1000)
			{std::cerr << "Error: too large a number." << std::endl; continue;}

		std::map<std::string, double>::const_iterator it = _bitcoinRates.lower_bound(date);
		if (it == _bitcoinRates.end() || it->first != date)
		{
			if (it == _bitcoinRates.begin())
				{std::cerr << "Error: no earlier date available => " << date << std::endl;continue;}
			--it;
		}
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
}