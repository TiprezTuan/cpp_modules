/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:51:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 11:32:10 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

// Class
class Fixed
{
	public:
		// Special Members Functions
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed();

		// Operators
		Fixed&	operator=(const Fixed& other);
		Fixed	operator+(const Fixed& other)	const;
		Fixed	operator-(const Fixed& other)	const;
		Fixed	operator*(const Fixed& other)	const;
		Fixed	operator/(const Fixed& other)	const;
		bool	operator>(const Fixed& other)	const;
		bool	operator<(const Fixed& other)	const;
		bool	operator>=(const Fixed& other)	const;
		bool	operator<=(const Fixed& other)	const;
		bool	operator==(const Fixed& other)	const;
		bool	operator!=(const Fixed& other)	const;
		Fixed&	operator--();
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed	operator--(int);

		// Getters / Setters
		int		getRawBits(void)	const;
		void	setRawBits(int const raw);

		// Members functions
		float	toFloat(void)				const;
		int		toInt(void)					const;
		static Fixed&		min(Fixed& o1, Fixed& o2);
		static Fixed&		max(Fixed& o1, Fixed& o2);
		static const Fixed&	min(const Fixed& o1, const Fixed& o2);
		static const Fixed&	max(const Fixed& o1, const Fixed& o2);

	private:
		// Attributs
		static const int	_fractionalBits = 8;
		int					_rawBits;

};

// Prototypes
std::ostream& operator << (std::ostream &out, const Fixed &fixed);

#endif /* FIXED_HPP */