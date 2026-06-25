/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:19:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/25 16:14:08 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

// class
class FragTrap: virtual public ClapTrap // Heritage
{
	public:
		// Special Member Functions
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap();

		// Operator
		FragTrap& operator=(const FragTrap& other);

		// Member Functions
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

// Prototypes

# endif /* FRAGTRAP_HPP */