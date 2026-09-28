/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:58:41 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/28 15:08:15 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		std::cout << "argv[1] = " << argv[1] << std::endl;	
		ScalarConverter::convert(argv[1]);
	}
	else
		std::cout << "argc == 1" << std::endl;
	return 0;
}