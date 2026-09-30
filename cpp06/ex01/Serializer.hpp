/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:28:13 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/30 15:45:02 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>

// Structure
struct Data
{
	unsigned int	id;
	std::string		message;
};

// Class
class Serializer
{
	public:
		// Member Functions
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	
	private:
		// Special Member Functions
		Serializer();
		Serializer(const Serializer& other);
		~Serializer();

		// Operators
		Serializer& operator=(const Serializer& other);
};

#endif /* SERIALIZER_HPP */