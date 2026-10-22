/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:49:09 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/22 15:46:56 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>

#include "Span.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
Span::Span()
	: _maxSize(0)
	{}
Span::Span(unsigned int N)
	: _data(std::vector<int>()), _maxSize(N)
	{}
Span::Span(const Span& other)
	{_maxSize = other._maxSize; _data = other._data;}
Span::~Span() {}

/************************************/
/*				Operator			*/
/************************************/
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_data = other._data;
		_maxSize = other._maxSize;
	}

	return (*this);
}

/************************************/
/*			Member Functions		*/
/************************************/
void	Span::addNumber(int n)
{
	if (_data.size() >= _maxSize)
		throw(std::length_error("Span is full"));
	_data.push_back(n);
}

long		Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw (std::logic_error("Not enough elements to find a span"));

	long shortest = -1;
	std::vector<int> tmp = _data;

	std::sort(tmp.begin(), tmp.end());

	for (size_t i = 1; i < tmp.size(); i++)
	{
		long	diff = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
		if (diff < shortest || shortest == -1)
			shortest = diff;
	}

	return (shortest);
}

long		Span::longestSpan() const
{
	if (_data.size() < 2)
		throw (std::logic_error("Not enough elements to find a span"));
	
	return (static_cast<long>(*std::max_element(_data.begin(), _data.end()))
			-
			static_cast<long>(*std::min_element(_data.begin(), _data.end())));
}

