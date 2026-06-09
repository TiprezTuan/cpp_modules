/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:53:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/09 20:06:13 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
Point::Point(void) : _x(0), _y(0) {}
Point::Point(int x, int y) : _x(x), _y(y) {}
Point::Point(const Point& other)
{
	this->_x = other._x;
	this->_y = other._y;
}
Point::~Point(void)	{}

/************************************/
/*			Getters / Setters		*/
/************************************/
int		Point::getX(void)	const	{return _x;}
int		Point::getY(void)	const	{return _y;}
void	Point::setX(int x) 			{_x = x;}
void	Point::setY(int y)			{_y = y;}

/************************************/
/*				Methodes			*/
/************************************/
Point&	Point::operator=(const Point& other)
{
	if (this != &other) {_x = other._x; _y = other._y;}
	return (*this);
}