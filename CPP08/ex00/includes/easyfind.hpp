/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:56:27 by angassin          #+#    #+#             */
/*   Updated: 2024/06/26 12:30:47 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>


template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(std::begin(container),
		std::end(container), value);
	if (it == std::end(container))
	{
		throw std::exception();
	}
		return it;
}

#endif