/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:33:37 by angassin          #+#    #+#             */
/*   Updated: 2024/05/30 13:39:29 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <cstddef>
# include <iostream>

template <typename T>
void iter(T* array, std::size_t size, void (*f)(const T&))
{
	for (std::size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void print(const T& content)
{
	std::cout << content << std::endl;
}

template <typename T>
void addOne(T& value)
{
	std::cout << value + 1 << std::endl;
}

#endif

