/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:26:36 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/25 16:23:58 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>

// Class
class Dog: public Animal
{
	public:
		// Special Member Functions
		Dog();
		Dog(const Dog& other);
		~Dog();

		// Operators
		Dog&	operator=(const Dog& other);

		// Member Functions
		void	makeSound(void) const;
} ;

// Prototypes

#endif /* DOG_HPP */