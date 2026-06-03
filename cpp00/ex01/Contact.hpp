/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:59:34 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 18:53:17 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "string"

class Contact
{
	public:
		// Special Member Functions
		Contact(void);
		Contact(std::string firstName, std::string lastName, std::string nickName, std::string num, std::string darkestSecret);
		~Contact(void);

		// Getter / Setter
		static int	getNbContact(void);

		int			getId(void);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string	getNum(void);
		std::string getDarkestSecret(void);

		// Methodes
		void display(void);

	private:
		static int	_nbContact;

		int			_contactId;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_num;
		std::string	_darkestSecret;
};

#endif