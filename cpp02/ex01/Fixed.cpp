/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:51:08 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/07 17:53:56 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>
#include "Fixed.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
// Defaults constructor
Fixed::Fixed()
	: _rawBits(0)
	{std::cout << "Default constructor called" << std::endl;}

// int -> fixed-point
Fixed::Fixed(const int value)
	: _rawBits(value << _fractionalBits)
	{std::cout << "Int constructor called" << std::endl;}

// float -> fixed-point
Fixed::Fixed(const float value)
	: _rawBits(roundf(value * pow(2, _fractionalBits)))
	{std::cout << "Float constructor called" << std::endl;}

// Copy assigment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {_rawBits = other._rawBits;}
	return (*this);
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
	{std::cout << "Copy constructor called\n"; this->operator=(other);}

// Destructor
Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

/************************************/
/*			Getters / Setters		*/
/************************************/
// Getters
int		Fixed::getRawBits(void) const
	{return (std::cout << "getRawBits member function called\n", _rawBits);}

// Setters
void	Fixed::setRawBits(int const raw)	{_rawBits = raw;}

/************************************/
/*				Methodes			*/
/************************************/
float	Fixed::toFloat(void)	const
{
	return (_rawBits / (1.0f * pow(2, _fractionalBits)));
}

int		Fixed::toInt(void)		const
{
	return (_rawBits >> _fractionalBits);
}

std::ostream &operator<< (std::ostream &out, const Fixed &fixed)
{
	return (out << fixed.toFloat());
}
