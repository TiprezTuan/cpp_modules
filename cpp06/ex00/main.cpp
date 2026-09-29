/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:58:41 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/29 15:26:37 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <vector>
#include <string>

void runTest(const std::string& input) {
	std::cout << "========================================" << std::endl;
	std::cout << "Test pour : \"" << input << "\"" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	ScalarConverter::convert(input);
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
 	if (argc > 1)
	{
		ScalarConverter::convert(argv[1]);
	}
	else
	{
		std::vector<std::string> tests;

		// 1. Chars
		tests.push_back("'a'");
		tests.push_back("'Z'");
		tests.push_back("'*'");
		tests.push_back("0"); // Char non affichable (NUL)

		// 2. Ints
		tests.push_back("42");
		tests.push_back("-42");
		tests.push_back("2147483647");  // INT_MAX
		tests.push_back("-2147483648"); // INT_MIN

		// 3. Floats
		tests.push_back("0.0f");
		tests.push_back("42.0f");
		tests.push_back("-4.2f");
		tests.push_back("3.14159f");

		// 4. Doubles
		tests.push_back("0.0");
		tests.push_back("42.0");
		tests.push_back("-4.2");
		tests.push_back("3.1415926535");

		// 5. Cas spéciaux (Pseudo-literals)
		tests.push_back("-inff");
		tests.push_back("+inff");
		tests.push_back("nanf");
		tests.push_back("-inf");
		tests.push_back("+inf");
		tests.push_back("nan");

		// 6. Overflows
		tests.push_back("2147483648");   // int overflow
		tests.push_back("-2147483649");  // int underflow
		tests.push_back("1e39f");        // float overflow

		// 7. Entrées invalides
		tests.push_back("abc");
		tests.push_back("42f8");
		tests.push_back("hello world");

		// Exécution des tests
		for (size_t i = 0; i < tests.size(); ++i) {
			runTest(tests[i]);
		}
	}
	return 0;
}