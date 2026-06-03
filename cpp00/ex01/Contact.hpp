/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:59:34 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 13:09:07 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "string"

class Contact
{
	public:
		// Special Member Functions
		Contact();
		Contact(std::string firstName, std::string lastName, std::string nickName, std::string num, std::string darkestSecret);
		~Contact();

		// Getter / Setter
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string	getNum();
		std::string getDarkestSecret();

		// Methodes
		void display();

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	num;
		std::string	darkestSecret;
};

#endif