/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:15:38 by ttiprez           #+#    #+#             */
/*   Updated: 2026/11/16 17:51:24 by ttiprez          ###   ########.fr       */
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

std::vector<int>	get_high(std::vector<std::pair<int ,int> > &pairs)
{
	std::vector<int>	highs;

	for (size_t i = 0; i < pairs.size(); i++)
		if (pairs[i].second != -1)
			highs.push_back(pairs[i].first);
	return (highs);
}

std::vector<int>	get_pend(const std::vector<std::pair<int, int> > &pairs, const std::vector<int> &sorted)
{
	std::vector<int>	pend;
	std::vector<bool>	used(pairs.size(), false);
	
	// Parcours de sorted
	for (size_t i = 0; i < sorted.size(); i++)
	{
		// Trouver le petit associé a sorted[i]
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (!used[i] && pairs[j].second != -1 && pairs[j].first == sorted[i])
			{
				pend.push_back(pairs[j].second);
				used[i] = true;
				break;
			}
		}
	}
	return (pend);
}

std::vector<int>	ford_jacobsthal_algorithm(const std::vector<int> &tab)
{
	std::vector<int>	sorted;

	// Condition d'arrêt
	if (tab.size() <= 1)
		return (tab);

	// Création paires + orphelin
	std::vector<std::pair<int, int> > pairs = create_pairs(tab);
	bool	has_odd	= (!pairs.empty() && pairs.back().second == -1);
	int		odd = has_odd ? pairs.back().first : 0;

	// Récursion sur les grands
	sorted = ford_jacobsthal_algorithm(get_high(pairs));

	// Pour chaque grand trié, retrouver son petit(b1, b2, ...)
	std::vector<int>	pend = get_pend(pairs, sorted);

	// Chaine principale
	sorted.insert(sorted.begin(), pend[0]);
}

int main(int argc, char const *argv[])
{
	int									arr[] = {7, 3, 9, 1, 8, 5, 2, 6, 4};
	std::vector<int>					default_tab(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::vector<std::pair<int, int> >	pairs_tab = create_pairs(default_tab);

	std::cout << "---------- Former les paires ----------" << std::endl;
	print_pairs_tab(pairs_tab);
	
	std::cout << "\n---------- Trier les grands ----------" << std::endl;
	std::vector<int>	highs = get_high(pairs_tab);
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
