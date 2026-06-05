/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:51:08 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/05 18:34:32 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
Fixed::Fixed()
	: _rawBits(0)
	{std::cout << "Default constructor called" << std::endl;}
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {_rawBits = other.getRawBits();}
	return (*this);
}
Fixed::Fixed(const Fixed& other)
	{std::cout << "Copy constructor called\n"; this->operator=(other);}
Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

/************************************/
/*			Getters / Setters		*/
/************************************/
int		Fixed::getRawBits(void) const
	{return (std::cout << "getRawBits member function called\n", _rawBits);}
void	Fixed::setRawBits(int const raw)	{_rawBits = raw;}

/************************************/
/*				Methodes			*/
/************************************/