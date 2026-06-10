/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:10:44 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 18:13:17 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

// Class
class Animal
{
	public:
		// Special Member Functions
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		virtual ~Animal();

		// Operator
		Animal&	operator=(const Animal& other);

		// Getters / Setters
		std::string	getType(void) const;

		// Member Functions
		virtual void makeSound(void) const;

	protected:
		// Attributes
		std::string	_type;
};

// Prototypes

# endif	/* ANIMAL_HPP */