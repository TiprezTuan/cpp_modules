/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:37:38 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 16:44:54 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

// Class
class Cure: public AMateria
{
	public:
		// Special Member Functions
		Cure();
		Cure(const Cure& other);
		~Cure();

		// Operators
		Cure& operator=(const Cure&);

		// Member Functions
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif /* CURE_HPP */