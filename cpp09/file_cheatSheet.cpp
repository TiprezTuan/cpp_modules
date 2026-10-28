/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_cheatSheet.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:12:50 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/28 04:35:44 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ----------- Includes necessaires -----------
#include <fstream>
#include <iostream>
#include <string>

int main()
{
	// ----------- Ouvrir le fichier en READ -----------
	std::ifstream	file_read("containers.txt");
	if (!file_read)
		return (std::cout << "error" << std::endl, EXIT_FAILURE);

	// ----------- Ouvrir un fichier en WRITE -----------
	std::ofstream	file_write("containers.txt");
	if (!file_write)
		return (std::cout << "error" << std::endl, EXIT_FAILURE);

	// ----------- Ouvrir un fichier en APPEND -----------
	std::ofstream	file_append("containers.txt", std::ios::app);
	if (!file_append)
		return (std::cout << "error" << std::endl, EXIT_FAILURE);


	// ----------- Lire un fichier ligne par ligne -----------
	std::string		line;
	while (std::getline(file_read, line))
		std::cout << "Ligne lue : " << line << std::endl;

	return (std::cout << "success" << std::endl, EXIT_SUCCESS);
}
