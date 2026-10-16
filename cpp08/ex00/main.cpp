/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:57:28 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/16 16:16:15 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	std::vector<int>	v;
	v.push_back(42);

	try {
		// Test qui réussit
		std::vector<int>::iterator it = ::easyfind(v, 42);
		std::cout << "Trouve : " << *it << std::endl;

		// Test qui échoue (lève une exception)
		::easyfind(v, 99);
	}
	catch (const std::exception& e) {
		std::cout << "Non trouve : " << e.what() << std::endl;
	}

	return 0;
}

