/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:20:53 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/04 02:11:38 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

/************************************/
/*				Classes				*/
/************************************/
class	Zombie
{
	public:
		// Special Member Functions
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		// Getters | Setters
		std::string	getName(void);
		void		setName(std::string name);

		// Methodes
		void	announce(void);
	private:
		// Attributs
		std::string	_name;
};

/************************************/
/*			Prototypes				*/
/************************************/
Zombie*	zombieHorde(int N, std::string name);

#endif	/* ZOMBIE_HPP */