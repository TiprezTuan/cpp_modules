/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:35:54 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/12 16:09:17 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <exception>
#include <cstdlib>

/************************************/
/*		Special Member Functions	*/
/************************************/
template <typename T>
Array<T>::Array()
	: _data(NULL), _size(0)
	{}

template <typename T>
Array<T>::Array(unsigned int n)
	: _data(new T[n]()), _size(n)
	{}

template <typename T>
Array<T>::Array(const Array& other)
	: _data(NULL), _size(0)
	{*this = other;}

// TODO
template <typename T>
Array<T>::~Array()
	{delete[] _data;}

/************************************/
/*				Operator			*/
/************************************/
template <typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		T *tmp = new T[other._size]();
		for (unsigned int i = 0; i < other._size; i++)
			tmp[i] = other._data[i];
		delete[] _data;
		_data = tmp;
		_size = other._size;
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::exception();
	return (_data[i]);
}

template <typename T>
const T	&Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::exception();
	return (_data[i]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}


