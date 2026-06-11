/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:19:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 16:43:24 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

// Forward declaration
class ICharacter;

class AMateria
{
	protected:
		const std::string	type;

	public:
		// Special Member Functions
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& other);
		virtual ~AMateria();

		// Operators
		AMateria& operator=(const AMateria& other);

		// Getters / Setters
		const std::string& getType(void)	const;

		// Member Functions
		virtual	AMateria*	clone() const = 0;
		virtual	void		use(ICharacter& target);
};


#endif /* AMATERIA_HPP */