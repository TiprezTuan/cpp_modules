/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:37:21 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 16:44:50 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

// Class
class Ice: public AMateria
{
	public:
		// Special Member Functions
		Ice();
		Ice(const Ice& other);
		~Ice();

		// Operators
		Ice& operator=(const Ice&);

		// Member Functions
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif /* ICE_HPP */