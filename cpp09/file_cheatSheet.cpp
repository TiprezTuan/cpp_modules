/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_cheatSheet.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:12:50 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/28 04:50:35 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ----------- Includes necessaires -----------
#include <fstream>
#include <iostream>
#include <string>

int main()
{

	// ##################### LECTURE #####################
	// ----------- Ouvrir le fichier en READ -----------
	std::ifstream	file_read("content.txt");
	if (!file_read)
		return (std::cout << "error" << std::endl, EXIT_FAILURE);
	file_read.close();

	// ----------- Lire ligne/ligne -----------
	std::ifstream	file1("content.txt");
	std::string		line;
	
	if (file1)
	{
		while (std::getline(file1, line))
			std::cout << "Ligne lue : " << line << std::endl;
		file1.close();
	}

	// ----------- Lire mot/mot | valeur/valeur -----------
	std::ifstream	file2("content.txt");
	std::string		word;
	int				num;
	
	if (file2)
	{
		// Lit le premier mot et le premier séparés separe par des espaces 
		file2 >> word >> num;
		std::cout << "Mot : " << word << ", nombre : " << num << std::endl;
		file2 >> word >> num;
		std::cout << "Mot : " << word << ", nombre : " << num << std::endl;
		file2.close();
	}

	// ##################### ECRITURE #####################
	// ----------- Ouvrir un fichier en WRITE -----------
	std::ofstream	file_write("write.txt");
	if (!file_write)
		return (std::cout << "error" << std::endl, EXIT_FAILURE);

	file_write << "Bonjour le monde !" << std::endl;
	file_write << "Valeur numerique" << 42 << std::endl;
	file_write.close();

	// ----------- Verifier la fin du fichier et les erreurs -----------
	// file.eof()	-> true si fin du fichier
	// file.fail()	-> true si erreur de formatage/lecture
	
	/*
	// ----------- Ouvrir un fichier en APPEND -----------
	std::ofstream	file_append("content.txt", std::ios::app);
	if (!file_append)
		return (std::cout << "error" << std::endl, EXIT_FAILURE);
	*/

	return (std::cout << "success" << std::endl, EXIT_SUCCESS);
}
