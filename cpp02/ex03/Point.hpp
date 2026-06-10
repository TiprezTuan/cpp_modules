/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:53:44 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 12:43:35 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	public:
		// Special Member Functions
		Point(void);
		Point(float const x, float const y);
		Point(const Point& other);
		~Point(void);

		
		// Getters / Setters
		Fixed		getX(void)	const;
		Fixed		getY(void)	const;
		
		private:
		// Private Member Functions
		Fixed const	_x;
		Fixed const	_y;

		// Operators
		Point&	operator=(const Point& other);

};

// Prototypes
bool	bsp(Point const a, Point const b, Point const c, Point const point);

# endif /* POINT_HPP */