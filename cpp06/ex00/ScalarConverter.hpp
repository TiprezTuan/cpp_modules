/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:26:26 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/01 13:24:17 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

// Class
class ScalarConverter
{
	public:
		// Member Functions
		static void	convert(const std::string& str);

	private:
		// Special Member Functions
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();

		// Operator
		ScalarConverter& operator=(const ScalarConverter& other);
};

#endif /* SCALARCONVERTER_HPP */