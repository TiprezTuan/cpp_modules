/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:46:35 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/05 15:28:47 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int main(void)
{
	Harl h1;

	h1.complain("DEBUG");
	std::cout << std::endl;
	h1.complain("INFO");
	std::cout << std::endl;
	h1.complain("WARNING");
	std::cout << std::endl;
	h1.complain("ERROR");

	return (0);
}
