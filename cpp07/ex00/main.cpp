/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:20:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/01 15:34:00 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	swap(T& a, T& b)
{
	T& tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template <typename T>
T	max(const T& a, const T& b)
{
	return (a > b ? a : b);
}

int main()
{
	{
		std::cout << "========== SWAP ==========" << std::endl;
		int	a = 5;
		int	b = 6;
		std::cout << "a = " << a << " | b = " << b << std::endl;
		std::cout << "swap..." << std::endl;
		swap<int>(a, b);
		std::cout << "a = " << a << " | b1 = " << b << std::endl;
	}

	{
		std::cout << "\n========== MIN ==========" << std::endl;
		float	a = 4.35;
		float	b = 8.874;
		std::cout << "min(" << a << ", " << b << ") = " << min<float>(a, b) << std::endl;
	}

	{
		std::cout << "\n========== MAX ==========" << std::endl;
		char	a = 'z';
		char	b = 'a';
		std::cout << "max(" << a << ", " << b << ") = " << max<char>(a, b) << std::endl
	}

	return 0;
}
