/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:46:09 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/01 16:04:16 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename F>
void	iter(T* array, const size_t lenght, F function)
{
	if (!array || !function)
		return ;

	for (size_t i = 0; i < lenght; i++)
		function(array[i]);
}

#endif /* ITER_HPP */