/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:25:03 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 16:17:37 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

// class
class ScavTrap: virtual public ClapTrap // Heritage
{
	public:
		// Special Member Functions
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();

		// Operator
		ScavTrap& operator=(const ScavTrap& other);

		// Member Functions
		void	attack(const std::string& target);
		void	guardGate(void);
	private :
};

// Prototypes

#endif /* SCAVTRAP_H */