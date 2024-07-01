/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:51:38 by angassin          #+#    #+#             */
/*   Updated: 2024/07/01 12:47:44 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

#define GREEN   "\033[32m"
#define RESET   "\033[0m"

template <typename C>
void searchContainer(const C& container, const std::string& containerName, int needle)
{
	typename C::const_iterator it;
	try
	{
		it = easyfind(container, needle);
		std::cout << "Found value " << *it << " in container " << containerName << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Value " << needle << " not found in container " << containerName << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << GREEN << "Test empty container" << RESET << std::endl;
	std::list<int> lst;
	searchContainer(lst, "lst", 5);

	std::vector<int> myVector;
	searchContainer(myVector, "myVector", 5);
	
	std::cout << GREEN << "Test with number missing" << RESET << std::endl;

	lst.push_back(0);
	lst.push_back(4);
	lst.push_back(10);
	searchContainer(lst, "lst", 5);
	
	myVector.push_back(0);
	myVector.push_back(4);
	myVector.push_back(10);
	searchContainer(myVector, "myVector", 5);

	std::cout << GREEN << "Test with number included" << RESET << std::endl;
	lst.push_back(5);
	searchContainer(lst, "lst", 5);
	
	myVector.push_back(5);
	searchContainer(myVector, "myVector", 5);
	
	return 0;
}