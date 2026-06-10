/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:51:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 16:28:38 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
	// Special Members Functions
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	// Getters / Setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// Members functions

	private:
	// Attributs
	static const int	_fractionalBits = 8;
	int					_rawBits;

};

#endif /* FIXED_HPP */