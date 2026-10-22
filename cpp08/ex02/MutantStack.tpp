/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:50:22 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/22 15:41:01 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
	{}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
	{}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
	: std::stack<T, Container>(other)
	{}

template <typename T, typename Container>
MutantStack<T, Container>&
MutantStack<T, Container>::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<T, Container>::operator=(other);
	return (*this);
}
	
template <typename T, typename Container>				// Template
typename	MutantStack<T, Container>::iterator			// Retour
			MutantStack<T, Container>::begin()			// Fonction
	{return (this->c.begin());}

template <typename T, typename Container>				// Template
typename	MutantStack<T, Container>::iterator			// Retour
			MutantStack<T, Container>::end()			// Fonction
	{return (this->c.end());}

template <typename T, typename Container>				// Template
typename	MutantStack<T, Container>::const_iterator	// Retour
			MutantStack<T, Container>::begin()	const	// Fonction
	{return (this->c.begin());}

template <typename T, typename Container>				// Template
typename	MutantStack<T, Container>::const_iterator	// Retour
			MutantStack<T, Container>::end()	const	// Fonction
	{return (this->c.end());}

