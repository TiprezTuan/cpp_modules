/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 02:33:20 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/04 02:57:46 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

/************************************/
/*				Classes				*/
/************************************/
class	Weapon
{
	public:
		// Special Member Functions
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		// Getters | Setters
		std::string	getType(void);
		void		setType(std::string type);

		// Methodes

	private:
		// Attributs
		std::string	_type;
};

/************************************/
/*			Prototypes				*/
/************************************/

# endif /* WEAPON_H */