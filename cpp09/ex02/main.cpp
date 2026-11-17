/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:15:38 by ttiprez           #+#    #+#             */
/*   Updated: 2026/11/17 16:43:22 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <iomanip>
#include "PmergeMe.hpp"

std::vector<int> parse_args(int argc, char const *argv[])
{
	if (argc < 2)
		throw std::invalid_argument("Error");

	std::vector<int>	result;

	for (int i = 1; i < argc; i++)
	{
		std::string	s(argv[i]);

		// Vide ou autre chose que des chiffres (rejette aussi "-5" et "+5")
		if (s.empty() || s.find_first_not_of("0123456789") != std::string::npos || s == "0")
			throw std::invalid_argument("Error");

		// Dépassement : strtol positionne errno à ERANGE s'il déborde d'un long
		errno = 0;
		long	n = std::strtol(s.c_str(), NULL, 10);
		if (errno == ERANGE || n > INT_MAX)
			throw std::invalid_argument("Error");

		result.push_back(static_cast<int>(n));
	}
	return (result);
}

int main(int argc, char const *argv[])
{
	try {
		std::vector<int>	input = parse_args(argc, argv);
		PmergeMe			sorter(input);

		std::cout << "Before: ";
		std::vector<int> tempVec = input;
		sorter.print_tab(tempVec);

		sorter.sortVector();
		sorter.sortDeque();

		std::cout << "After: ";
		std::vector<int> sortedVec = sorter.getVec();
		sorter.print_tab(sortedVec);

		std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " << std::fixed << std::setprecision(0) << sorter.getTimeVec() * 1000000 << " us (" << std::setprecision(6) << sorter.getTimeVec() << " s)" << std::endl;
		std::cout << "Time to process a range of " << input.size() << " elements with std::deque : " << std::fixed << std::setprecision(0) << sorter.getTimeDeq() * 1000000 << " us (" << std::setprecision(6) << sorter.getTimeDeq() << " s)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
