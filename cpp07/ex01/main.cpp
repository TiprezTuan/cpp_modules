/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:20:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/01 16:02:03 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "iter.hpp"

template <typename F>
void	increment(F& a)
	{a++;}

template <typename F>
void	display(const F& a)
	{std::cout << a<< std::endl;}

void	upperCaseString(std::string& str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
}

int main() {
	// ---- TEST 1: Tableau d'entiers (Lecture seule) ----
	std::cout << "--- Test 1: Int Array (Print) ---" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

	// On passe la fonction template instanciée explicitement avec <int>
	::iter(intArray, intLen, display<int>);
	std::cout << "\n\n";

	// ---- TEST 2: Tableau d'entiers (Modification) ----
	std::cout << "--- Test 2: Int Array (Increment) ---" << std::endl;
	::iter(intArray, intLen, increment<int>);
	::iter(intArray, intLen, display<int>);
	std::cout << "\n\n";

	// ---- TEST 3: Tableau de chaînes (std::string) ----
	std::cout << "--- Test 3: String Array ---" << std::endl;
	std::string strArray[] = {"hello", "42", "paris"};
	size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

	// Modification des strings en majuscules
	::iter(strArray, strLen, upperCaseString);
	// Affichage avec le template printElement instancié avec <std::string>
	::iter(strArray, strLen, display<std::string>);
	std::cout << "\n";

	return 0;
}

