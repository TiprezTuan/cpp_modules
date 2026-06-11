/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:26:35 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 14:15:35 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <string>

// Class
class Cat: public AAnimal
{
	public:
		// Special Member Functions
		Cat();
		Cat(const Cat& other);
		~Cat();

		// Operators
		Cat&	operator=(const Cat& other);

		// Member Functions
		void	makeSound(void) const;

	private:
		Brain*	_brain;
} ;

// Prototypes

#endif /* CAT_HPP */