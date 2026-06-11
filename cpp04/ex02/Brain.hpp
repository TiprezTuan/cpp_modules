/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:53:06 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 14:06:33 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

// Class
class Brain
{
	public:
		// Special Member Functions
		Brain(void);
		Brain(const Brain& other);
		~Brain(void);

		// Operators
		Brain& operator=(const Brain& other);

	private:
		std::string	_ideas[100];
};

#endif