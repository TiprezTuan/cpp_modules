/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:38:27 by ttiprez           #+#    #+#             */
/*   Updated: 2026/11/17 16:38:38 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <vector>
# include <deque>

class PmergeMe
{
	public:
		// Special Member Functions
		PmergeMe(const std::vector<int>	&input);
		PmergeMe(const PmergeMe& other);
		~PmergeMe();

		// Operator
		PmergeMe&	operator=(const PmergeMe& other);

		// Public Member Functions
		void	sortVector(void);
		void	sortDeque(void);
		void	print_tab(std::vector<int> &tab);
		void	print_tab(std::deque<int> &tab);

		// Getters
		std::vector<int>	getVec(void);
		std::deque<int>		getDeq(void);
		double				getTimeVec(void);
		double				getTimeDeq(void);

	private:
		// Special Member Functions
		PmergeMe(void);

		// Private Member Functions
		std::vector<int>	_ford_jacobsthal_algorithm(const std::vector<int> &tab);
		std::deque<int>		_ford_jacobsthal_algorithm(const std::deque<int> &tab);

		// Attributes
		std::vector<int>	_input;
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		double				_timeVec;
		double				_timeDeq;
};

#endif	/* PMERGE_ME_HPP */