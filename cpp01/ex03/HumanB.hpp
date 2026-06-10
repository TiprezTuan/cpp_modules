/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 02:35:35 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 16:28:38 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

/************************************/
/*				Classes				*/
/************************************/
class	HumanB
{
	public:
		// Special Member Functions
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);

		// Getters | Setters
		void	setWeapon(Weapon weapon);

		// Methodes
		void	attack(void);
	private:
		// Attributs
		std::string	_name;
		Weapon		_weapon;
};

/************************************/
/*			Prototypes				*/
/************************************/

# endif /* HUMANB_HPP */