/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:59:20 by angassin          #+#    #+#             */
/*   Updated: 2024/06/04 15:39:51 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <limits>

#define GREEN   "\033[32m"
#define RESET   "\033[0m"

int main()
{
	std::cout << GREEN << "Test default constructor:" << RESET << std::endl;
	Array<int> a0;
	std::cout << "Size of a0: " << a0.size() << std::endl << std::endl;

	std::cout << GREEN << "Test parametric constructor :" << RESET << std::endl;
	Array<int> a1(5);
	std::cout << "Size of a1: " << a1.size() << std::endl << std::endl;
	Array<double> d1(10);
	std::cout << "Size of d1: " << d1.size() << std::endl << std::endl;
	Array<std::string> s1(3);
	std::cout << "Size of s1: " << s1.size() << std::endl << std::endl;

	std::cout << GREEN << "Test element access and initialization" << RESET << std::endl;

	if (a1.size() > 0)
	{
		a1[3] = 42;
		std::cout << "a1[0] = " << a1[0] << std::endl;
	}
	std::cout << std::endl;
	
	if (d1.size() > 0)
	{
		d1[0] = std::numeric_limits<double>::max();
		std::cout << "d1[0] = " << d1[0] << std::endl;
	}
	std::cout << std::endl;

	if (s1.size() > 0)
	{
		s1[0] = "Hello";
		std::cout << "s1[0] = " << s1[0] << std::endl;
	}
	std::cout << std::endl;
	for(unsigned int i = 0; i < a1.size(); ++i)
	{
		std::cout << "a1[" << i << "] = " << a1[i] << std::endl;
	}
	std::cout << std::endl;
	for(unsigned int i = 0; i < s1.size(); ++i)
	{
		std::cout << "s1[" << i << "] = " << s1[i] << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << GREEN << "Test copy constructor" << RESET << std::endl;
	Array<int> a2(a1);
	std::cout << "Size of a2: " << a2.size() << std::endl << std::endl;

	std::cout << GREEN << "Test assignment operator" << RESET << std::endl;
	a0 = a2;
	std::cout << "Size of a0: " << a0.size() << std::endl << std::endl;

	std::cout << GREEN << "Test out of bounds access" << RESET << std::endl;
	try
	{
		std::cout << a0[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << GREEN << "Test modification of original and copy" << RESET << std::endl;
	if (a0.size() > 0)
	{
		a0[0] = -2147483648;
		std::cout << "a0[0] = " << a0[0] << std::endl;
		std::cout << "a2[0] = " << a2[0] << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
