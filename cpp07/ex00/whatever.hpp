/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:35:11 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/01 15:42:21 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b)
	{T tmp = a; a = b; b = tmp;}

template <typename T>
T	min(const T& a, const T& b)
	{return (a < b ? a : b);}

template <typename T>
T	max(const T& a, const T& b)
	{return (a > b ? a : b);}

#endif /* WHATEVER_HPP */