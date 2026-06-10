/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 19:40:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 18:56:58 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static bool	isValidInput(std::string &str)
{
	for (int i = 0; str[i]; i++)
		if (str[i] < 32 || str[i] > 126)
			return (false);
	return (true);
}

static bool	safeGateline(std::string &str)
{
	if (!std::getline(std::cin, str))
	{
		std::cout << std::endl;
		return (false);
	}
	return (true);
}

static int	strToInt(std::string str)
{
	for (int i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	std::istringstream	iss(str);
	int value;
	iss >> value;
	return (value);
}

int main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd = "";

	while (cmd.compare("EXIT"))
	{
		std::cout << "enter cmd (ADD, SEARCH, EXIT): ";
		if (!safeGateline(cmd))
			break;
		if (!cmd.compare("ADD"))
		{
			std::string	contactFirstName;
			while (!contactFirstName.compare("") || !isValidInput(contactFirstName))
			{
				std::cout << "FirstName: ";
				if (!safeGateline(contactFirstName))
					return (1);
			}

			std::string	contactLastName;
			while (!contactLastName.compare("") || !isValidInput(contactLastName))
			{
				std::cout << "Lastname: ";
				if (!safeGateline(contactLastName))
					return (1);
			}

			std::string	contactNickName;
			while (!contactNickName.compare("") || !isValidInput(contactNickName))
			{
				std::cout << "NickName: ";
				if (!safeGateline(contactNickName))
					return (1);
			}

			std::string	contactDarkestSecret;
			while (!contactDarkestSecret.compare("") || !isValidInput(contactDarkestSecret))
			{
				std::cout << "DarkestSecret: ";
				if (!safeGateline(contactDarkestSecret))
					return (1);
			}
			
			std::string	contactNum;
			while (!contactNum.compare("") || !isValidInput(contactNum))
			{
				std::cout << "Num of contact: ";
				if (!safeGateline(contactNum))
					return (1);
			}
			Contact contact(contactFirstName, contactLastName, contactNickName, contactNum, contactDarkestSecret);
			phoneBook.addContact(contact);
		}
		else if (!cmd.compare("SEARCH"))
		{
			int	i = -1;
			phoneBook.display();
			while (1)
			{
				std::string	s_value;
				std::cout << "Select (valid) ID: ";
				if (!safeGateline(s_value))
					return (1);
				i = strToInt(s_value);
				if (i >= 0 && phoneBook.getContact(i).getId() != -1)
				{
					phoneBook.getContact(i).display();
					break;
				}
			}
		}
	}
	return (0);
}
