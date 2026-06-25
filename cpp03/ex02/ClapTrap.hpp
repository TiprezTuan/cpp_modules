/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:52:32 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/25 16:11:10 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

//class
class ClapTrap
{
	public:
		// Special Member Functions
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		virtual ~ClapTrap();

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
		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
	protected :
		// Attributs
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_attack;


};

// Prototypes

#endif /* CLAPTRAP_HPP */