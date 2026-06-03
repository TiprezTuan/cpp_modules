/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 19:40:12 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 13:15:22 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		// Special Member Functions
		PhoneBook();
		~PhoneBook();

		// Methodes
		void	display();
		void	addContact(Contact contact);

	private:
		Contact contact_tab[8];
		std::string	intToString(int n);
		std::string	center(std::string str, int width);
};

#endif