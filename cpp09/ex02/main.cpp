/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:15:38 by ttiprez           #+#    #+#             */
/*   Updated: 2026/11/16 17:07:13 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <exception>
#include <vector>
#include <deque>
#include <utility>

void	print_pairs_tab(std::vector<std::pair<int, int> > tab)
{
	std::cout << "(";
	for (size_t i = 0; i < tab.size(); i++)
	{
		if (tab[i].second != -1)
			std::cout << "(" << tab[i].first << ", " << tab[i].second << ")";
		else 
			std::cout << "(" << tab[i].first << ")";
		if (i + 1 < tab.size())
			std::cout << ", ";
	}
	std::cout << ")" << std::endl;
}

void	print_tab(std::vector<int> tab)
{
	std::cout << "(";
	for (size_t i = 0; i < tab.size(); i++)
	{
		std::cout << tab[i];
		if (i + 1 < tab.size())
			std::cout << ", ";
	}
	std::cout << ")" << std::endl;
}

std::vector<std::pair<int, int> >	create_pairs(std::vector<int>	tab)
{
	std::vector<std::pair<int, int> >	pairs_tab;
	size_t	i = 0;

	for (; i + 1 < tab.size(); i += 2)
	{
		if (tab[i] > tab[i + 1])
			pairs_tab.push_back(std::make_pair(tab[i], tab[i + 1]));
		else
			pairs_tab.push_back(std::make_pair(tab[i + 1], tab[i]));
	}

	// Verifier orphelin
	if (i < tab.size())
		pairs_tab.push_back(std::make_pair(tab[i], -1));
	
	return (pairs_tab);
}

int main(int argc, char const *argv[])
{
	int									arr[] = {7, 3, 9, 1, 8, 5, 2, 6, 4};
	std::vector<int>					default_tab(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::vector<std::pair<int, int> >	pairs_tab = create_pairs(default_tab);

	std::cout << "---------- Former les paires ----------" << std::endl;
	print_pairs_tab(pairs_tab);
	
	std::cout << "\n---------- Trier les grands ----------" << std::endl;
	std::vector<int>	highs;
	for (size_t i = 0; i < pairs_tab.size(); i++)
		if (pairs_tab[i].second != -1)
			highs.push_back(pairs_tab[i].first);
	std::cout << "Liste a trier : ";
	print_tab(highs);
	std::cout << std::endl;

	std::cout <<"Paires du niveau inferieur :";
	std::vector<std::pair<int, int> >	high_pairs = create_pairs(highs);
	print_pairs_tab(high_pairs);
	std::cout << std::endl;

	std::cout << "\n---------- Trier les grands de ce niveau ----------" << std::endl;
	
	
	return 0;
}

// Faut que ce soit recursif, genre tant que y'a plus de 2 paires on recuperer les grand des paires jusqu'a avoir qu'une valeur (La plus grande donc)
// SUITE DE JACOBSTHAL : 0 1 1 3 5 11 21 43 [...]		=> n = (n - 1) + ((n - 2) * 2)
//														=> n est obtenu en ajoutant n - 1 à 2 x (n - 2).
