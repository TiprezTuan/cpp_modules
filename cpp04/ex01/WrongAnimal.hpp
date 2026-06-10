/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:10:44 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 17:05:38 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

// Class
class WrongAnimal
{
	public:
		// Special Member Functions
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal();

		// Operator
		WrongAnimal&	operator=(const WrongAnimal& other);

		// Getters / Setters
		std::string	getType(void) const;

		// Member Functions
		void makeSound(void) const;

	protected:
		// Attributes
		std::string	_type;
};

// Prototypes

# endif	/* WRONGANIMAL_HPP */