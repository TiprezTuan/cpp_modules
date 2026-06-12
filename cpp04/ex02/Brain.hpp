/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:53:06 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/12 15:49:17 by ttiprez          ###   ########.fr       */
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

		// Getters / Setters
		std::string	getIdea(int idx);
		void		setIdea(int idx, std::string idea);

	private:
		std::string	_ideas[100];
};

#endif