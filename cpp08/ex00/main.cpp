/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:49:44 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/22 15:50:06 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T>
static void	test(T &c, int value)
{
	try
	{
		typename T::iterator it = ::easyfind(c, value);
		std::cout << "Trouve : " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Non trouve (" << value << ") : " << e.what() << std::endl;
	}
}

int main()
{
	std::vector<int>	v;
	std::list<int>		l;
	std::deque<int>		d;

	for (int i = 0; i < 5; ++i)
	{
		v.push_back(i * 10);
		l.push_back(i * 10);
		d.push_back(i * 10);
	}

	std::cout << "--- vector ---" << std::endl;
	test(v, 30);
	test(v, 99);

	std::cout << "--- list ---" << std::endl;
	test(l, 0);
	test(l, 99);

	std::cout << "--- deque ---" << std::endl;
	test(d, 40);
	test(d, 99);

	std::cout << "--- vide ---" << std::endl;
	std::vector<int> empty;
	test(empty, 1);

	std::cout << "--- doublon (premiere occurrence) ---" << std::endl;
	std::vector<int> dup;
	dup.push_back(7);
	dup.push_back(5);
	dup.push_back(7);
	std::vector<int>::iterator it = ::easyfind(dup, 7);
	std::cout << "index : " << (it - dup.begin()) << std::endl;	// attendu : 0

	std::cout << "--- const ---" << std::endl;
	const std::vector<int> &cv = v;
	try
	{
		std::vector<int>::const_iterator cit = ::easyfind(cv, 20);
		std::cout << "Trouve : " << *cit << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}