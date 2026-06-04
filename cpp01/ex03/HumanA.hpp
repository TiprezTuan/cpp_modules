/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 02:34:38 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/04 02:51:28 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"

/************************************/
/*				Classes				*/
/************************************/
class	HumanA
{
	public:
		// Special Member Functions
		HumanA(void);
		HumanA(std::string name, Weapon weapon);
		~HumanA(void);

		// Getters | Setters

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

# endif /* HUMANA_H */