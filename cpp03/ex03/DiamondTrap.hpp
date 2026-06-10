/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:29:05 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 14:30:34 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

// class
class DiamondTrap: public ScavTrap, public FragTrap // Double heritage
{
	public:
		// Special Member Functions
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();

		// Operator
		DiamondTrap&	operator=(const DiamondTrap& other);

		// Getters / Setters
		std::string		getName(void);

		// Member Functions
		void	attack(const std::string& target);
		void	whoAmI(void);

	private :
		// Attributes
		std::string	_name;
};

// Prototypes

# endif /* DIAMONDTRAP_H */