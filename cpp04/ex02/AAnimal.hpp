/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:10:44 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 14:12:38 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <string>

// Class
class AAnimal
{
	public:
		// Special Member Functions
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& other);
		virtual ~AAnimal();

		// Operator
		AAnimal&	operator=(const AAnimal& other);

		// Getters / Setters
		std::string	getType(void) const;

		// Member Functions
		virtual void makeSound(void) const = 0;

	protected:
		// Attributes
		std::string	_type;
};

// Prototypes

# endif	/* AAnimal_HPP */