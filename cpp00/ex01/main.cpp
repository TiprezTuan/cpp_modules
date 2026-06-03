/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 19:40:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 13:00:44 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (cmd.compare("EXIT"))
	{
		std::cout << "Contact List:\n";
		phoneBook.display();
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
			std::cout << "NickName: ";
			std::getline(std::cin, contactNickName);

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
			
		}
	}
	return (0);
}
