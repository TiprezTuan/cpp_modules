/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:49:09 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/20 15:56:22 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>

#include "Span.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
Span::Span() {};
Span::Span(unsigned int N)
	: _data(std::vector<int>()), _maxSize(N)
	{}
Span::Span(const Span& other)
	{_maxSize = other._maxSize; _data = other._data;}
Span::~Span() {};

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

int		Span::shortestSpan()
{
	if (_data.size() < 2)
		throw (std::logic_error("Not enough elements to find a span"));

	int shortest = -1;
	std::vector<int> tmp = _data;

	std::sort(tmp.begin(), tmp.end());

	for (size_t i = 1; i < tmp.size(); i++)
		if (tmp[i] - tmp[i - 1] < shortest || shortest == -1)
			shortest = tmp[i] - tmp[i - 1];

	return (shortest);
}

int		Span::longestSpan()
{
	if (_data.size() < 2)
		throw (std::logic_error("Not enough elements to find a span"));
	
	return (*std::max_element(_data.begin(), _data.end())
			-
			*std::min_element(_data.begin(), _data.end()));
}

