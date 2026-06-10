/* ************************************************************************** */
/*																														      */
/*																								:::      ::::::::   */
/*   main.cpp																		 :+:      :+:    :+:   */
/*																					   +:+ +:+			  +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>			     +#+  +:+			+#+			 */
/*																		      +#+#+#+#+#+   +#+			    */
/*   Created: 2026/06/05 17:51:11 by ttiprez			    #+#    #+#			      */
/*   Updated: 2026/06/10 12:43:26 by ttiprez			   ###   ########.fr			*/
/*																														      */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {

	// ----------------------------------------------------------------
	std::cout << "------------- Triangle de base -------------"				<< std::endl;
	// ----------------------------------------------------------------
	Point	a1(0, 0);
	Point	b1(10, 0);
	Point	c1(0, 10);

	std::cout << "Point interieur (attendu: 1) :"							<< std::endl;
	std::cout << "\tP(1, 1)   = " << bsp(a1, b1, c1, Point(1, 1))			<< std::endl;
	std::cout << "\tP(2, 2)   = " << bsp(a1, b1, c1, Point(2, 2))			<< std::endl;
	std::cout << "\tP(3, 1)   = " << bsp(a1, b1, c1, Point(3, 1))			<< std::endl;
	std::cout << "\tP(1, 7)   = " << bsp(a1, b1, c1, Point(1, 7))			<< std::endl;

	std::cout << "Point exterieur (attendu: 0) :"							<< std::endl;
	std::cout << "\tP(10, 10) = " << bsp(a1, b1, c1, Point(10, 10))			<< std::endl;
	std::cout << "\tP(-1, 1)  = " << bsp(a1, b1, c1, Point(-1, 1))			<< std::endl;
	std::cout << "\tP(5, 6)   = " << bsp(a1, b1, c1, Point(5, 6))			<< std::endl;
	std::cout << "\tP(7, 7)   = " << bsp(a1, b1, c1, Point(7, 7))			<< std::endl;
	std::cout << "\tP(20, 0)  = " << bsp(a1, b1, c1, Point(20, 0))			<< std::endl;

	std::cout << "Sur les aretes/sommets (attendu: 0) :"					<< std::endl;
	std::cout << "\tP(0, 0)   = " << bsp(a1, b1, c1, Point(0, 0))			<< std::endl;
	std::cout << "\tP(10, 0)  = " << bsp(a1, b1, c1, Point(10, 0))			<< std::endl;
	std::cout << "\tP(0, 10)  = " << bsp(a1, b1, c1, Point(0, 10))			<< std::endl;
	std::cout << "\tP(5, 0)   = " << bsp(a1, b1, c1, Point(5, 0))			<< std::endl;
	std::cout << "\tP(0, 5)   = " << bsp(a1, b1, c1, Point(0, 5))			<< std::endl;
	std::cout << "\tP(5, 5)   = " << bsp(a1, b1, c1, Point(5, 5))			<< std::endl;

	// ----------------------------------------------------------------
	std::cout << "\n------------- Triangle non symetrique -------------"	<< std::endl;
	// ----------------------------------------------------------------
	Point	a2(1, 1);
	Point	b2(4, 2);
	Point	c2(2, 5);

	std::cout << "Point interieur (attendu: 1) :"							<< std::endl;
	std::cout << "\tP(2, 3)     = " << bsp(a2, b2, c2, Point(2, 3))			<< std::endl;
	std::cout << "\tP(2.5, 2.5) = " << bsp(a2, b2, c2, Point(2.5f, 2.5f))	<< std::endl;
	std::cout << "\tP(2, 2)     = " << bsp(a2, b2, c2, Point(2, 2))			<< std::endl;

	std::cout << "Point exterieur (attendu: 0) :"							<< std::endl;
	std::cout << "\tP(0, 0)     = " << bsp(a2, b2, c2, Point(0, 0))			<< std::endl;
	std::cout << "\tP(5, 5)     = " << bsp(a2, b2, c2, Point(5, 5))			<< std::endl;
	std::cout << "\tP(3, 4.5)   = " << bsp(a2, b2, c2, Point(3, 4.5f))		<< std::endl;

	std::cout << "Sur les aretes/sommets (attendu: 0) :"					<< std::endl;
	std::cout << "\tP(1, 1)     = " << bsp(a2, b2, c2, Point(1, 1))			<< std::endl;
	std::cout << "\tP(4, 2)     = " << bsp(a2, b2, c2, Point(4, 2))			<< std::endl;
	std::cout << "\tP(2, 5)     = " << bsp(a2, b2, c2, Point(2, 5))			<< std::endl;
	std::cout << "\tP(2.5, 1.5) = " << bsp(a2, b2, c2, Point(2.5f, 1.5f))	<< std::endl;

	// ----------------------------------------------------------------
	std::cout << "\n------------- Triangle presque plat -------------"		<< std::endl;
	// ----------------------------------------------------------------
	Point	a3(0, 0);
	Point	b3(100, 0);
	Point	c3(50, 1);

	std::cout << "Point interieur (attendu: 1) :"							<< std::endl;
	std::cout << "\tP(50, 0.5)  = " << bsp(a3, b3, c3, Point(50, 0.5f))		<< std::endl;
	std::cout << "\tP(25, 0.4)  = " << bsp(a3, b3, c3, Point(25, 0.4f))		<< std::endl;

	std::cout << "Point exterieur (attendu: 0) :"							<< std::endl;
	std::cout << "\tP(50, 2)    = " << bsp(a3, b3, c3, Point(50, 2))		<< std::endl;
	std::cout << "\tP(-1, 0)    = " << bsp(a3, b3, c3, Point(-1, 0))		<< std::endl;

	std::cout << "Sur les aretes/sommets (attendu: 0) :"					<< std::endl;
	std::cout << "\tP(0, 0)     = " << bsp(a3, b3, c3, Point(0, 0))			<< std::endl;
	std::cout << "\tP(50, 0)    = " << bsp(a3, b3, c3, Point(50, 0))		<< std::endl;
	std::cout << "\tP(100, 0)   = " << bsp(a3, b3, c3, Point(100, 0))		<< std::endl;

	// ----------------------------------------------------------------
	std::cout << "\n------------- Cas degénérés -------------"				<< std::endl;
	// ----------------------------------------------------------------

	Point	ad(0, 0);
	Point	bd(5, 0);
	Point	cd(10, 0);

	std::cout << "Triangle plat (tous alignes, attendu: 0) :"				<< std::endl;
	std::cout << "\tP(5, 0)   = " << bsp(ad, bd, cd, Point(5, 0))			<< std::endl;
	std::cout << "\tP(3, 0)   = " << bsp(ad, bd, cd, Point(3, 0))			<< std::endl;
	std::cout << "\tP(5, 1)   = " << bsp(ad, bd, cd, Point(5, 1))			<< std::endl;

	Point	ap(1, 1);
	Point	bp(1, 1);
	Point	cp(1, 1);
 
	std::cout << "Triangle point (sommets identiques, attendu: 0) :"		<< std::endl;
	std::cout << "\tP(1, 1)   = " << bsp(ap, bp, cp, Point(1, 1))			<< std::endl;
	std::cout << "\tP(0, 0)   = " << bsp(ap, bp, cp, Point(0, 0))			<< std::endl;

	Point	an(-5, -5);
	Point	bn(5, -5);
	Point	cn(0, 5);

	std::cout << "Triangle avec coords negatives :" << std::endl;
	std::cout << "Point interieur (attendu: 1) :" << std::endl;
	std::cout << "\tP(0, 0)   = " << bsp(an, bn, cn, Point(0, 0))			<< std::endl;
	std::cout << "\tP(-1, -1) = " << bsp(an, bn, cn, Point(-1, -1))			<< std::endl;
	std::cout << "Point exterieur (attendu: 0) :" << std::endl;
	std::cout << "\tP(5, 5)   = " << bsp(an, bn, cn, Point(5, 5))			<< std::endl;
	std::cout << "\tP(-6, 0)  = " << bsp(an, bn, cn, Point(-6, 0))			<< std::endl;
	std::cout << "Sur les aretes (attendu: 0) :" << std::endl;
	std::cout << "\tP(-5, -5) = " << bsp(an, bn, cn, Point(-5, -5))			<< std::endl;
	std::cout << "\tP(0, -5)  = " << bsp(an, bn, cn, Point(0, -5))			<< std::endl;

	return (0);
}
