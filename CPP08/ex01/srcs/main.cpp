/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:16:44 by angassin          #+#    #+#             */
/*   Updated: 2024/07/05 12:07:12 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#define GREEN   "\033[32m"
#define RESET   "\033[0m"


int main() 
{ 


	std::cout << GREEN << "Test default constructor" << RESET << std::endl;
	Span spMax;
	
	std::cout << std::endl << GREEN << "Test shortestSpan and longestSpan on an empty container" 
		<< RESET << std::endl;
	try 
	{
		spMax.shortestSpan();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try 
	{
		spMax.longestSpan();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << GREEN << "Test addNumber, shortestSpan and longestSpan" << RESET << std::endl;

	Span sp = Span(10); 

	sp.addNumber(6); 
	sp.addNumber(3); 
	sp.addNumber(17); 
	sp.addNumber(9); 
	sp.addNumber(11);

	sp.printContainer();
	std::cout << sp.shortestSpan() << std::endl; 
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl << GREEN << "Test addRange" << RESET << std::endl;

	sp.addRange(5);
	sp.printContainer();
	std::cout << sp.shortestSpan() << std::endl; 
	std::cout << sp.longestSpan() << std::endl;

	spMax.addRange(10001);
	std::cout << spMax.shortestSpan() << std::endl; 
	std::cout << spMax.longestSpan() << std::endl;

	std::cout << std::endl << GREEN << "Test addNumber and addRange when container full" << RESET
		<< std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		sp.addRange(1);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << GREEN << "Test copy constructor and assignment operator" << RESET << std::endl;

	Span spCopy = sp;
	spCopy.printContainer();

	
	return 0; 
}