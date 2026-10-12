/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:35:56 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/12 15:56:23 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	private:
		// Attributes
		T				*_data;
		unsigned int	_size;

	public:
		// Special Member Functions
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();

		// Operator
		Array			&operator=(const Array &other);
		T				&operator[](unsigned int i);
		const T			&operator[](unsigned int i) const;

		// Member Functions
		unsigned int	size() const;
};

# include "Array.tpp"

#endif /* ARRAY_HPP */