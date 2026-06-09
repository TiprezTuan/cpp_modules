/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:53:44 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/09 20:06:12 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

class	Point
{
	public:
		// Special Member Functions
		Point(void);
		Point(int x, int y);
		Point(const Point& other);
		~Point(void);

		// Getters / Setters
		int		getX(void)	const;
		int		getY(void)	const;
		void	setX(int x);
		void	setY(int y);

		// Public Member Functions
		Point&	Point::operator=(const Point& other);

	private:
		// Private Member Functions
		int	_x;
		int	_y;

};

# endif /* POINT_HPP */