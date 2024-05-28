/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:10:22 by angassin          #+#    #+#             */
/*   Updated: 2024/05/28 20:35:20 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANIP_HPP
# define MANIP_HPP
# include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b)
{
	return (a < b ? a : b);
}

#endif