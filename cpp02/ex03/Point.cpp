/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:53:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 12:33:28 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
Point::Point(void)								: _x(0), _y(0)			{}
Point::Point(float const x, float const y)		: _x(x), _y(y)			{}
Point::Point(const Point& o)					: _x(o._x), _y(o._y)	{}
Point::~Point(void)	{}

/************************************/
/*				Operators			*/
/************************************/
Point&	Point::operator=(const Point&)	{return *this;}

/************************************/
/*			Getters / Setters		*/
/************************************/
Fixed		Point::getX(void)	const	{return _x;}
Fixed		Point::getY(void)	const	{return _y;}