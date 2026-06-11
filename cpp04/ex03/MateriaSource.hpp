/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:22:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 16:36:34 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

// Class
class MateriaSource: public IMateriaSource
{
	protected:
		AMateria*	stock[4];

	public:
		// Special Member Functions
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		// Operators
		MateriaSource& operator=(const MateriaSource& other);

		// Member functions
		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const &type);
};

#endif /* MATERIASOURCE_HPP */