/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:59:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 12:51:27 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
Contact::Contact() 
	: firstName(""), lastName(""), nickName(""), num(""), darkestSecret("") {}
Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string num, std::string darkestSecret)
	: firstName(firstName), lastName(lastName), nickName(nickName), num(num), darkestSecret(darkestSecret) {}
Contact::~Contact() {}

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string Contact::getFirstName()		{return firstName;}
std::string Contact::getLastName()		{return lastName;}
std::string Contact::getNickName()		{return nickName;}
std::string	Contact::getNum()			{return num;}
std::string Contact::getDarkestSecret()	{return darkestSecret;}

/************************************/
/*				Methodes			*/
/************************************/
void Contact::display()
{
	std::cout << "FirstName: " << firstName << "\n";
	std::cout << "LastName: " << lastName << "\n";
	std::cout << "NickName: " << nickName << "\n";
	std::cout << "PhoneNumber: " << num << "\n";
	std::cout << "DarkestSecret: " << darkestSecret << "\n";
}

