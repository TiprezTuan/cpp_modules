/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:54:03 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 12:23:40 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

static Fixed	crossProduct(Point const a, Point const b, Point const point)
{
	return
	(
		(
			(b.getX() - a.getX()) * (point.getY() - a.getY())
			-
			(b.getY() - a.getY()) * (point.getX() - a.getX())
		)
	);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed sideA = crossProduct(a, b, point);
	Fixed sideB = crossProduct(b, c, point);
	Fixed sideC = crossProduct(c, a, point);

	return ((sideA > 0 && sideB > 0 && sideC > 0)
			||
			(sideA < 0 && sideB < 0 && sideC < 0));
}