/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:49:11 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/20 15:55:44 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>

class Span
{
	public:
		// Special Member Functions
		Span(unsigned int N);
		Span(const Span& other);
		~Span();

		// Operator
		Span& operator=(const Span& other);

		// Member Functions
		template <typename It>
			void	addNumber(It start, It end); 
		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();

	private:
		// Special member Function
		Span();

		// Attributes
		std::vector<int>	_data;
		unsigned int		_maxSize;
};

template <typename It>
void	Span::addNumber(It begin, It end)
{
	if (static_cast<size_t>(std::distance(begin, end)) + _data.size() > _maxSize)
		throw(std::length_error("Span is full"));
	_data.insert(_data.end(), begin, end);
}

#endif /* SPAN_HPP */