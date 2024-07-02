/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:51:38 by angassin          #+#    #+#             */
/*   Updated: 2024/07/02 11:37:26 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <climits>


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

	std::deque<int> deq;
	searchContainer(deq, "deq", 5);

	std::cout << GREEN << "Test container of one element that is not the one we look for" << RESET << std::endl;

	lst.push_back(0);
	searchContainer(lst, "lst", 5);

	myVector.push_back(0);
	searchContainer(myVector, "myVector", 5);

	deq.push_back(0);
	searchContainer(deq, "deq", 5);

	std::cout << GREEN << "Test container containing only the element we look for" << RESET << std::endl;

	std::list<int> lst1;
	lst1.push_back(5);
	searchContainer(lst1, "lst1", 5);

	std::vector<int> vector1;
	vector1.push_back(5);
	searchContainer(vector1, "vector1", 5);

	std::deque<int> deq1;
	deq1.push_back(5);
	searchContainer(deq1, "deq1", 5);
	
	std::cout << GREEN << "Test with number missing" << RESET << std::endl;

	lst.push_back(INT_MAX);
	lst.push_back(INT_MIN);
	searchContainer(lst, "lst", 5);
	
	
	myVector.push_back(INT_MAX);
	myVector.push_back(INT_MIN);
	searchContainer(myVector, "myVector", 5);

	
	deq.push_back(INT_MAX);
	deq.push_back(INT_MIN);
	searchContainer(deq, "deq", 5);

	std::cout << GREEN << "Test with number included" << RESET << std::endl;
	lst.push_back(5);
	searchContainer(lst, "lst", 5);
	
	myVector.push_back(5);
	searchContainer(myVector, "myVector", 5);
	
	deq.push_back(5);
	searchContainer(deq, "deq", 5);
	
	return 0;
}