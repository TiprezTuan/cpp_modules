/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:57:25 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/22 15:49:17 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &container, int toFind)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), toFind);

	if (it == container.end())
		throw (std::runtime_error("Error: Value not found"));

	return (it);
}

template <typename T>
typename T::const_iterator	easyfind(const T &container, int toFind)
{
	typename T::const_iterator	it = std::find(container.begin(), container.end(), toFind);

	if (it == container.end())
		throw (std::runtime_error("Error: Value not found"));

	return (it);
}

#endif /* EASYFIND_HPP */