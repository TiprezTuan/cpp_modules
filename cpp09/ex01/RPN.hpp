/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:09:09 by ttiprez           #+#    #+#             */
/*   Updated: 2026/11/17 15:20:47 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class RPN
{
	public:
		// Special Member Functions
		RPN(const std::string& expression);
		RPN(const RPN& other);
		~RPN(void);
		
		// Operator
		RPN&	operator=(const RPN& other);

		// Public Member Functions
		int	calculate()	const;

	private:
		// Special Member Functions
		RPN(void);

		// Private Member Functions
		int	_operation(int left, int right, char op)	const;

		// Attributes
		std::string	_expression;
};

#endif /* RPN_HPP */