/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:26:35 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/12 15:47:34 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

// Class
class Cat: public Animal
{
	public:
		// Special Member Functions
		Cat();
		Cat(const Cat& other);
		~Cat();

		// Operators
		Cat&	operator=(const Cat& other);

		// Getters / Setters
		Brain*	getBrain(void);

		// Member Functions
		void	makeSound(void) const;

	private:
		Brain*	_brain;
} ;

// Prototypes

#endif /* CAT_HPP */