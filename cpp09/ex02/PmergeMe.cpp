/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:38:30 by ttiprez           #+#    #+#             */
/*   Updated: 2026/11/17 16:40:24 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

#include "PmergeMe.hpp"

/************************************/
/*			Classic Functions		*/
/************************************/
// --- create_pairs ---
static std::vector<std::pair<int, int> >	create_pairs(const std::vector<int>	&tab)
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
static std::deque<std::pair<int, int> >	create_pairs(const std::deque<int>	&tab)
{
	std::deque<std::pair<int, int> >	pairs_tab; size_t	i = 0;
	for (; i + 1 < tab.size(); i += 2)
	{
		if (tab[i] > tab[i + 1]) pairs_tab.push_back(std::make_pair(tab[i], tab[i + 1]));
		else pairs_tab.push_back(std::make_pair(tab[i + 1], tab[i]));
	}
	if (i < tab.size()) pairs_tab.push_back(std::make_pair(tab[i], -1));
	return (pairs_tab);
}

// --- get_high ---
static std::vector<int>	get_high(const std::vector<std::pair<int ,int> > &pairs)
{
	std::vector<int>	highs;

	for (size_t i = 0; i < pairs.size(); i++)
		if (pairs[i].second != -1)
			highs.push_back(pairs[i].first);
	return (highs);
}
static std::deque<int>	get_high(const std::deque<std::pair<int ,int> > &pairs)
{
	std::deque<int>	highs;
	for (size_t i = 0; i < pairs.size(); i++) if (pairs[i].second != -1) highs.push_back(pairs[i].first);
	return (highs);
}

// --- get_pend ---
static std::vector<int>	get_pend(const std::vector<std::pair<int, int> > &pairs, const std::vector<int> &sorted)
{
	std::vector<int>	pend;
	std::vector<bool>	used(pairs.size(), false);
	
	// Parcours de sorted
	for (size_t i = 0; i < sorted.size(); i++)
	{
		// Trouver le petit associé a sorted[i]
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (!used[j] && pairs[j].second != -1 && pairs[j].first == sorted[i])
			{
				pend.push_back(pairs[j].second);
				used[j] = true;
				break;
			}
		}
	}
	return (pend);
}
static std::deque<int>	get_pend(const std::deque<std::pair<int, int> > &pairs, const std::deque<int> &sorted)
{
	std::deque<int>	pend; std::deque<bool>	used(pairs.size(), false);
	
	for (size_t i = 0; i < sorted.size(); i++)
		for (size_t j = 0; j < pairs.size(); j++)
			if (!used[j] && pairs[j].second != -1 && pairs[j].first == sorted[i])
				{pend.push_back(pairs[j].second); used[j] = true; break;}
	return (pend);
}

/************************************/
/*		Special Member Functions	*/
/************************************/
PmergeMe::PmergeMe(const std::vector<int> &input)
	: _input(input)
	{}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _input(other._input)
	{}

PmergeMe::~PmergeMe()	{}

/************************************/
/*				Operator			*/
/************************************/
PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
		{_input = other._input;}
	return (*this);
}

/************************************/
/*		Public Member Functions		*/
/************************************/
// --- print_tab ---
void	PmergeMe::print_tab(std::vector<int> &tab)
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
void	PmergeMe::print_tab(std::deque<int> &tab)
{
	std::cout << "(";
	for (size_t i = 0; i < tab.size(); i++)
		{std::cout << tab[i]; if (i + 1 < tab.size()) std::cout << ", ";}
	std::cout << ")" << std::endl;
}

// --- sortVector ---
void	PmergeMe::sortVector(void)
{
	clock_t	start = clock();

	_vec = _input;
	_vec = _ford_jacobsthal_algorithm(_vec);

	clock_t end = clock();
	_timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

// -- sortDeque ---
void	PmergeMe::sortDeque(void)
{
	clock_t	start = clock();

	_deq.assign(_input.begin(), _input.end());
	_deq = _ford_jacobsthal_algorithm(_deq);

	clock_t end = clock();
	_timeDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

/************************************/
/*		Private Member Functions	*/
/************************************/
// --- ford_jacobsthal_algorithm ---
std::vector<int>	PmergeMe::_ford_jacobsthal_algorithm(const std::vector<int> &tab)
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
	sorted = _ford_jacobsthal_algorithm(get_high(pairs));

	// Pour chaque grand trié, retrouver son petit(b1, b2, ...)
	std::vector<int>	pend = get_pend(pairs, sorted);
	if (has_odd)
		pend.push_back(odd);

	// Chaine principale
	sorted.insert(sorted.begin(), pend[0]);
	
	// Insérer les petits
	std::vector<int>	highs = sorted;
	size_t				total = pend.size(), prev = 1, jPrev = 1, jCurr = 3;

	while (prev < total)
	{
		size_t top = std::min<size_t>(total, jCurr);
		for (size_t i = top; i > prev; i--)
		{
			std::vector<int>::iterator	limit;
			if (i == highs.size())
				limit = sorted.end();
			else
				limit = std::find(sorted.begin(), sorted.end(), highs[i - 1]);
			std::vector<int>::iterator	pos = std::upper_bound(sorted.begin(), limit, pend[i - 1]);
			sorted.insert(pos, pend[i - 1]);
		}
		prev = top;
		size_t	next = jCurr + jPrev * 2;
		jPrev = jCurr;
		jCurr = next;
	}

	return (sorted);
}
std::deque<int>	PmergeMe::_ford_jacobsthal_algorithm(const std::deque<int> &tab)
{
	std::deque<int>	sorted;
	if (tab.size() <= 1)	return (tab);
	std::deque<std::pair<int, int> > pairs = create_pairs(tab);
	bool	has_odd	= (!pairs.empty() && pairs.back().second == -1);
	int		odd = has_odd ? pairs.back().first : 0;
	sorted = _ford_jacobsthal_algorithm(get_high(pairs));
	std::deque<int>	pend = get_pend(pairs, sorted);
	if (has_odd) pend.push_back(odd);
	sorted.insert(sorted.begin(), pend[0]);
	std::deque<int>	highs = sorted;
	size_t			total = pend.size(), prev = 1, jPrev = 1, jCurr = 3;
	while (prev < total)
	{
		size_t top = std::min<size_t>(total, jCurr);
		for (size_t i = top; i > prev; i--)
		{
			std::deque<int>::iterator	limit;
			if (i == highs.size()) limit = sorted.end();
			else limit = std::find(sorted.begin(), sorted.end(), highs[i - 1]);
			std::deque<int>::iterator	pos = std::upper_bound(sorted.begin(), limit, pend[i - 1]);
			sorted.insert(pos, pend[i - 1]);
		}
		prev = top; size_t	next = jCurr + jPrev * 2; jPrev = jCurr; jCurr = next;
	}
	return (sorted);
}

/************************************/
/*				Getters				*/
/************************************/
std::vector<int>	PmergeMe::getVec(void)
	{return (_vec);}

std::deque<int>		PmergeMe::getDeq(void)
	{return (_deq);}

double	PmergeMe::getTimeVec(void)
	{return (_timeVec);}

double	PmergeMe::getTimeDeq(void)
	{return (_timeDeq);}