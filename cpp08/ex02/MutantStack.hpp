/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:50:23 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/22 15:40:47 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		// Special Member Functions
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();

		// Operator
		MutantStack&	operator=(const MutantStack& other);

		// Typedef
		typedef typename Container::iterator		iterator;
		typedef typename Container::const_iterator	const_iterator;

		// Member Functions
		iterator		begin();
		iterator		end();
		const_iterator	begin()	const;
		const_iterator	end()	const;
};

# include "MutantStack.tpp"

#endif /* MUTANTSTACK_HPP */