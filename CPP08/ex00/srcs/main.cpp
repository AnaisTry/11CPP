/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:51:38 by angassin          #+#    #+#             */
/*   Updated: 2024/06/26 12:59:05 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>

template <typename C>
void searchContainer(const C& container, int needle)
{
	typename C::const_iterator it;
	try
	{
		it = easyfind(container, needle);
		std::cout << "Found value" << *it << " in container." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Value " << needle << "not found in container." << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	// test empty container
	std::list<int> lst;

	searchContainer(lst, 5);
	
	// test with number missing

	lst.push_back(0);
	lst.push_back(4);
	lst.push_back(10);

	searchContainer(lst, 5);

	// test with number included
	lst.push_back(5);

	searchContainer(lst, 5);
	
	return 0;
}