/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:54:21 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 17:04:19 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <string>

// Class
class WrongCat: public WrongAnimal
{
	public:
		// Special Member Functions
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();

		// Operators
		WrongCat&	operator=(const WrongCat& other);

		// Member Functions
		void	makeSound(void) const;
} ;

// Prototypes

#endif /* WRONGCAT_HPP */