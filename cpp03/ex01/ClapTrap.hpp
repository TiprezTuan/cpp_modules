/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:52:32 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 13:40:40 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>

//class
class ClapTrap
{
	public:
		// Special Member Functions
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		// Operatos
		ClapTrap& operator=(const ClapTrap& other);
		
		// Getters / Setters
		std::string	getName(void);
		int			getHp(void);
		int			getEp(void);
		int			getAttack(void);
		void		setName(std::string name);
		void		setHp(int hp);
		void		setEp(int ep);
		void		setAttack(int attack);

		// Member Functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
	private :
		// Attributs
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_attack;


};

// Prototypes

#endif /* CLAPTRAP_H */