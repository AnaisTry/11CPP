/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:16:44 by angassin          #+#    #+#             */
/*   Updated: 2024/07/04 00:45:33 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main() 
{ 
	Span sp = Span(5); 

	sp.addNumber(6); 
	sp.addNumber(3); 
	sp.addNumber(17); 
	sp.addNumber(9); 
	sp.addNumber(11);

	sp.printContainer();
	std::cout << sp.shortestSpan() << std::endl; 
	std::cout << sp.longestSpan() << std::endl; 
	return 0; 
}