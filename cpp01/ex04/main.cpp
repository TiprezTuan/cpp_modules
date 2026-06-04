/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 02:59:32 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/04 03:30:37 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

static void replace(std::string *str, std::string s1, std::string s2)
{
	size_t	pos = 0;
	while ((pos = str->find(s1, pos)) != std::string::npos)
	{
		str->erase(pos, s1.length());
		str->insert(pos, s2);
		pos += s2.length();
	}
}

int main(int ac, const char **av)
{
	// Variables
	std::string		filename = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];

	// Gestion d'erreurs
	if (ac != 4)
	{
		std::cerr << "Error: filename, s1, s2 required" << std::endl;
		return (1);
	}
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}

	// Ouverture fichiers
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	
	std::ofstream	replace_file((filename + ".replace").c_str());
	if (!replace_file.is_open())
	{
		std::cerr << "Error: could not create output file" << std::endl;
		return (1);
	}

	// Lecture du fichier & copie dans fichier.replace
	std::string		currentLine;
	while (getline(file, currentLine))
	{
		replace(&currentLine, s1, s2);
		replace_file << currentLine << std::endl;
	}

	// Fermeture des fichiers
	file.close();
	replace_file.close();
	return (0);
}
