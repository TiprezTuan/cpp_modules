/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:33:50 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 16:15:57 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

// Class
class Character: public ICharacter
{
	protected :
		// Attributes
		const std::string	_name;
		AMateria*	_inventory[4];

	public:
		// Special Member Functions
		Character();
		Character(std::string name);
		Character(const Character& other);
		~Character();

		// Operator
		Character& operator=(const Character& other);

		// Getters / Setters
		const std::string&	getName(void) const;
	
		// Member Functions
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif /* CHARACTER_HPP */