/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 02:35:35 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/04 02:55:12 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

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

# endif /* HUMANB_H */