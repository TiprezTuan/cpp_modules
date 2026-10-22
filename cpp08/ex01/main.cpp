/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:56:35 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/22 15:47:43 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <limits>
#include "Span.hpp"

static int	g_ok = 0;
static int	g_ko = 0;

static void	check(const std::string &name, bool cond)
{
	if (cond)
	{
		std::cout << "[OK] " << name << std::endl;
		++g_ok;
	}
	else
	{
		std::cout << "[KO] " << name << std::endl;
		++g_ko;
	}
}

static void	title(const std::string &t)
{
	std::cout << "\n=== " << t << " ===" << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	// ---------------------------------------------------------
	title("Exemple du sujet");
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortest : " << sp.shortestSpan() << std::endl;
		std::cout << "longest  : " << sp.longestSpan() << std::endl;
		check("shortestSpan == 2", sp.shortestSpan() == 2);
		check("longestSpan == 14", sp.longestSpan() == 14);
	}

	// ---------------------------------------------------------
	title("Span plein (addNumber simple)");
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		bool thrown = false;
		try { sp.addNumber(3); }
		catch (const std::exception &e)
		{
			thrown = true;
			std::cout << "exception : " << e.what() << std::endl;
		}
		check("exception quand plein", thrown);
		check("contenu intact apres l'exception", sp.longestSpan() == 1);
	}

	// ---------------------------------------------------------
	title("Pas assez de nombres");
	{
		Span empty(5);
		bool t1 = false;
		try { empty.shortestSpan(); }
		catch (const std::exception &e)
		{
			t1 = true;
			std::cout << "exception : " << e.what() << std::endl;
		}
		check("shortestSpan sur span vide", t1);

		bool t2 = false;
		try { empty.longestSpan(); }
		catch (const std::exception &e)
		{
			t2 = true;
			std::cout << "exception : " << e.what() << std::endl;
		}
		check("longestSpan sur span vide", t2);

		Span one(5);
		one.addNumber(42);
		bool t3 = false;
		try { one.shortestSpan(); }
		catch (const std::exception &e)
		{
			t3 = true;
			std::cout << "exception : " << e.what() << std::endl;
		}
		check("shortestSpan avec 1 seul element", t3);

		bool t4 = false;
		try { one.longestSpan(); }
		catch (const std::exception &e)
		{
			t4 = true;
			std::cout << "exception : " << e.what() << std::endl;
		}
		check("longestSpan avec 1 seul element", t4);
	}

	// ---------------------------------------------------------
	title("Cas particuliers");
	{
		Span same(3);
		same.addNumber(5);
		same.addNumber(5);
		same.addNumber(5);
		check("doublons : shortest == 0", same.shortestSpan() == 0);
		check("doublons : longest == 0", same.longestSpan() == 0);

		Span neg(4);
		neg.addNumber(-10);
		neg.addNumber(10);
		neg.addNumber(-3);
		neg.addNumber(0);
		check("negatifs : shortest == 3", neg.shortestSpan() == 3);
		check("negatifs : longest == 20", neg.longestSpan() == 20);

		Span ext(2);
		ext.addNumber(std::numeric_limits<int>::min());
		ext.addNumber(std::numeric_limits<int>::max());
		check("extremes : longest == 4294967295", ext.longestSpan() == 4294967295L);
	}

	// ---------------------------------------------------------
	title("Ajout par range : vector");
	{
		int arr[] = {10, 1, 7, 20, 4};
		std::vector<int> v(arr, arr + 5);
		Span sp(5);
		sp.addNumber(v.begin(), v.end());
		check("vector : shortest == 3", sp.shortestSpan() == 3);
		check("vector : longest == 19", sp.longestSpan() == 19);
	}

	// ---------------------------------------------------------
	title("Ajout par range : list");
	{
		std::list<int> l;
		l.push_back(100);
		l.push_back(50);
		l.push_back(75);
		Span sp(3);
		sp.addNumber(l.begin(), l.end());
		check("list : shortest == 25", sp.shortestSpan() == 25);
		check("list : longest == 50", sp.longestSpan() == 50);
	}

	// ---------------------------------------------------------
	title("Ajout par range : tableau C (int*)");
	{
		int arr[] = {1, 2, 3, 4};
		Span sp(4);
		sp.addNumber(arr, arr + 4);
		check("int* : shortest == 1", sp.shortestSpan() == 1);
		check("int* : longest == 3", sp.longestSpan() == 3);
	}

	// ---------------------------------------------------------
	title("Range trop grande (rien ne doit etre ajoute)");
	{
		std::vector<int> v;
		for (int i = 0; i < 10; ++i)
			v.push_back(i * 100);
		Span sp(5);
		sp.addNumber(1);
		sp.addNumber(2);

		bool thrown = false;
		try { sp.addNumber(v.begin(), v.end()); }
		catch (const std::exception &e)
		{
			thrown = true;
			std::cout << "exception : " << e.what() << std::endl;
		}
		check("exception si la range depasse", thrown);
		// si la verif est faite en amont, il reste 3 places libres
		// et le span contient toujours seulement {1, 2}
		check("aucun ajout partiel (longest == 1)", sp.longestSpan() == 1);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(5);
		bool full = false;
		try { sp.addNumber(6); }
		catch (const std::exception &) { full = true; }
		check("il restait bien exactement 3 places", full);
	}

	// ---------------------------------------------------------
	title("Range vide");
	{
		std::vector<int> v;
		Span sp(3);
		bool ok = true;
		try { sp.addNumber(v.begin(), v.end()); }
		catch (const std::exception &) { ok = false; }
		check("range vide : pas d'exception", ok);
	}

	// ---------------------------------------------------------
	title("Gros test : 20 000 nombres");
	{
		const unsigned int N = 20000;
		std::vector<int> big;
		for (unsigned int i = 0; i < N; ++i)
			big.push_back(std::rand());
		Span sp(N);
		sp.addNumber(big.begin(), big.end());
		std::cout << "shortest : " << sp.shortestSpan() << std::endl;
		std::cout << "longest  : " << sp.longestSpan() << std::endl;
		check("gros test : shortest >= 0", sp.shortestSpan() >= 0);
		check("gros test : shortest <= longest",
			  sp.shortestSpan() <= sp.longestSpan());
	}

	// ---------------------------------------------------------
	title("Gros test deterministe : 0..9999 melanges en sens inverse");
	{
		const unsigned int N = 10000;
		Span sp(N);
		for (unsigned int i = 0; i < N; ++i)
			sp.addNumber(static_cast<int>(N - 1 - i));
		check("shortest == 1", sp.shortestSpan() == 1);
		check("longest == 9999", sp.longestSpan() == 9999);
	}

	// ---------------------------------------------------------
	title("Copie et affectation");
	{
		Span a(3);
		a.addNumber(1);
		a.addNumber(10);

		Span b(a);
		check("copie : longest == 9", b.longestSpan() == 9);

		Span c(10);
		c = a;
		check("affectation : longest == 9", c.longestSpan() == 9);

		// la copie est independante de l'original
		a.addNumber(100);
		check("copie independante (b longest reste 9)", b.longestSpan() == 9);
		check("original modifie (a longest == 99)", a.longestSpan() == 99);

		// la capacite max est aussi copiee
		b.addNumber(2);
		bool full = false;
		try { b.addNumber(3); }
		catch (const std::exception &) { full = true; }
		check("copie : capacite max conservee (3)", full);
	}

	// ---------------------------------------------------------
	title("Span de taille 0");
	{
		Span sp(0);
		bool thrown = false;
		try { sp.addNumber(1); }
		catch (const std::exception &) { thrown = true; }
		check("Span(0) : addNumber lance une exception", thrown);
	}

	std::cout << "\n--------------------------------" << std::endl;
	std::cout << "Resultat : " << g_ok << " OK, " << g_ko << " KO" << std::endl;
	return (g_ko == 0 ? 0 : 1);
}