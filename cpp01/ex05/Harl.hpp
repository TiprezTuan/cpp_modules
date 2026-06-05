/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:46:38 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/05 15:01:22 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class	Harl
{
	public:
	// Special Members Functions
	Harl(void);
	~Harl(void);

	// Getters | Setters

	// Member functions
	void	complain(std::string level);

	private:
	// Member functions
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);

};

#endif	/* HARL_HPP */
