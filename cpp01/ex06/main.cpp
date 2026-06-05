/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:46:35 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/05 15:44:55 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);

	Harl	h1;

	h1.complain(av[1]);

	return (0);
}
