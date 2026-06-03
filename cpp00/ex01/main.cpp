/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 19:40:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 16:05:25 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static int	strToInt(std::string str)
{
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
		std::getline(std::cin, cmd);
		if (!cmd.compare("ADD"))
		{
			std::string	contactFirstName;
			std::cout << "FirstName: ";
			std::getline(std::cin, contactFirstName);
			
			std::string	contactLastName;
			std::cout << "LastName: ";
			std::getline(std::cin, contactLastName);

			std::string	contactNickName;
			while (!contactNickName.compare(""))
			{
				std::cout << "NickName (can't be empty): ";
				std::getline(std::cin, contactNickName);
			}

			std::string	contactDarkestSecret;
			std::cout << "DarkestSecret: ";
			std::getline(std::cin, contactDarkestSecret);
			
			std::string	contactNum;
			while (!contactNum.compare(""))
			{
				std::cout << "Num of contact (can't be empty): ";
				std::getline(std::cin, contactNum);
			}
			Contact contact(contactFirstName, contactLastName, contactNickName, contactNum, contactDarkestSecret);
			phoneBook.addContact(contact);
		}
		else if (!cmd.compare("SEARCH"))
		{
			int	i = 0;
			phoneBook.display();
			do
			{
				std::string	s_value;
				std::cout << "Select (valid) ID: ";
				std::getline(std::cin, s_value);
				i = strToInt(s_value);
			} while(i < 0 || i > phoneBook.length());
			phoneBook.getContact(i).display();
		}
	}
	return (0);
}
