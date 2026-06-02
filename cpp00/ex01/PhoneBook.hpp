/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 19:40:12 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/02 19:50:02 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		PhoneBook& operator=(const PhoneBook& other);
		~PhoneBook();

	private:
		int value;
};

#endif