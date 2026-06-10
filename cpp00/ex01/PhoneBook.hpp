/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 19:40:12 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 16:28:38 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		// Special Member Functions
		PhoneBook(void);
		~PhoneBook(void);

		// Getters / Setters
		Contact getContact(int i);

		// Methodes
		void	display(void);
		int		length(void);
		void	addContact(Contact contact);
		
	private:
		Contact _contact_tab[8];
		std::string	_formatField(std::string str, int width);
};

#endif