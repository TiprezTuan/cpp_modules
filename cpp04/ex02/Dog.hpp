/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:26:36 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/12 15:49:00 by ttiprez          ###   ########.fr       */
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

		// Getters / Setters
		Brain*	getBrain(void);

		// Member Functions
		void	makeSound(void) const;

	private:
		Brain*	_brain;
} ;

// Prototypes

#endif /* DOG_HPP */