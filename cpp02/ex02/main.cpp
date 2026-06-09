/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:51:11 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/09 19:50:39 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed const c( Fixed( 10.1016f ) / Fixed( 2 ) );

	std::cout << "1. a = " << a << std::endl;
	std::cout << "2. ++a = " << ++a << std::endl;
	std::cout << "3. a = " << a << std::endl;
	std::cout << "4. a++ = " << a++ << std::endl;
	std::cout << "5. a = " << a << std::endl;

	std::cout << b << std::endl;
	// std::cout << c << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return (0);
}
