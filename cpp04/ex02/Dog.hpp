/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:26:36 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 14:15:33 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <string>

// Class
class Dog: public AAnimal
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

	private:
		Brain*	_brain;
} ;

// Prototypes

#endif /* DOG_HPP */