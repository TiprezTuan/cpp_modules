/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cheatsheet.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:11:23 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/28 20:26:43 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <cstdlib>
#include <iostream>
#include <vector>

int main(void)
{
	// ------------------ Déclaration ------------------
	// Déclaration d'une pile d'entiers
	std::stack<int>	myStack;

	// Déclaration avec un conteneur sous-jacent spécifique (ex: std::vector)
	std::stack<int, std::vector<int>>	myVectorStack;

	// ------------------ Méthodes principales ------------------
	myStack.push(12);	// Empile
	myStack.pop();		// Dépile
	myStack.top();		// Référence vers l'élément au sommet
	myStack.empty();	// True si pile vide
	myStack.size();		// Taille

	// ------------------ Exemple ------------------
	std::stack<int>	s;
	
	// Empiler
	s.push(10);	// Pile : [10]
	s.push(20);	// Pile : [10, 20] -> 20 est au sommet
	s.push(30);	// Pile : [10, 20, 30] -> 30 est au sommet

	// Consulter le sommet
	std::cout << "Sommet actuel : " << s.top() << std::endl;

	// Retirer le sommet
	s.pop();
	std::cout << "Nouveau sommet après pop : " << s.top() << std::endl;

	// Parcourir et vider la pile
	std::cout << "Contenu de la pile (du sommet vers la base) : ";
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;

	// Verifier la taille
	std::cout << "Taille de la pile : " << s.size() << std::endl;

	return (EXIT_SUCCESS);
}
