/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheatSheet.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:20:08 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/27 20:01:04 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <exception>
#include <iterator>

int main()
{
	// ------------------ Déclaration ------------------
	std::map<std::string, float>	myMap;
	
	// ------------------ Insertion de données ------------------
	myMap["2011-02-30"] = 30;

	// ------------------ Recherche et Accès ------------------
		// 1. Avec [] (ATTENTION : Crée une entrée à 0 si la clé n'existe pas !)
	float price = myMap["2011-02-30"];
	(void)price;

		// 2. Avec find() (SECURISE : Ne crée rien si la clé est absente)
	std::map<std::string, float>::iterator it = myMap.find("2011-02-30");
	if (it != myMap.end())
		std::cout << it->first << " => " << it->second << std::endl;
	else
		std::cout << "Key does not exist" << std::endl;

	// ------------------ Recherche par borne ------------------
	std::map<std::string, float>	mySecondMap;
	mySecondMap["2011-02-29"] = 29;
	mySecondMap["2011-02-30"] = 30;
	mySecondMap["2011-02-31"] = 31;

		// lower_bound renvoie un iterator de la valeur la plus proche 
		// de la valeur entree en parametre
	std::map<std::string, float>::iterator it2 = mySecondMap.lower_bound("2011-02-30");

	if (it2 != mySecondMap.end() && it2->first == "2011-02-30")
		std::cout << "Date exacte existante" << std::endl;
	else if (it2 != mySecondMap.end())
		std::cout << "Date la plus proche : " << (--it2)->first << std::endl;
	else
		std::cout << "Date non trouvee" << std::endl;

	// ------------------ Parcourir la map ------------------
	for (std::map<std::string, float>::const_iterator it3 = mySecondMap.begin(); it3 != mySecondMap.end(); it3++)
		std::cout << it3->first << " => " << it3->second << std::endl;

	// ------------------ Autres methodes utiles ------------------
	myMap.size();				// Nombre d'elements
	myMap.empty();				// True if empty
	myMap.erase("2011-02-29");	// Supprime l'element associe a la cle
	myMap.clear();				// Vide la map

	return (EXIT_SUCCESS);
}
