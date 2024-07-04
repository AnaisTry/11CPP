/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:14:38 by angassin          #+#    #+#             */
/*   Updated: 2024/07/04 18:40:37 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <climits>
#include <exception>
#include <stdexcept>
#include <algorithm> // min_element
#include <numeric> // adjacent_difference
#include <vector>

// Default constructor
Span::Span() : maxN_(INT_MAX)
{
	std::cout << "Span container created" << std::endl;
}

Span::Span(unsigned int maxN) : maxN_(maxN)
{
	std::cout << "Span container of max " << maxN_ << " integers created" 
		<< std::endl;
}

// Destructor
Span::~Span()
{
	std::cout << "Span destroyed" << std::endl;
}

// Copy constructor
Span::Span(const Span& other)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
Span& Span::operator=(Span const& other)
{
	std::cout << "Span assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->maxN_ = other.maxN_;
		this->container_ = other.container_;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (container_.size() < maxN_)
		container_.insert(number);
	else 
		throw std::exception();
}

void Span::printContainer() const
{
	std::multiset<int>::iterator it;

	std::cout << "content : ";
	for (it = container_.begin(); it != container_.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// size_t Span::shortestSpan() const
// {
// 	if (container_.size() < 2)
// 		throw std::logic_error("Not enough elements for span detection");
	
	 
// 	std::multiset<int>::iterator it;
// 	it = container_.begin();
// 	std::multiset<int>::iterator nextIt;
// 	nextIt = ++container_.begin();

// 	size_t shortestSpan = *nextIt - *it; // implicit cast
	
// 	for (; nextIt != container_.end(); ++it, ++nextIt)
// 	{
// 		size_t currentSpan = *nextIt - *it;
// 		if (currentSpan < shortestSpan)
// 			shortestSpan = currentSpan;
// 	}
// 	return shortestSpan;
// }

/*
	returns the smallest difference between two numbers stored in the container
	copying the result of the differences in the vector and returning 
	the smallest difference
*/
size_t Span::shortestSpan() const
{
	if (container_.size() < 2)
		throw std::logic_error("Not enough elements for span detection");

	std::vector<size_t> span(container_.size() - 1);
	std::adjacent_difference(container_.begin(), container_.end(), span.begin());

	return *std::min_element(span.begin(), span.end());
}

size_t Span::longestSpan() const
{
	if (container_.size() < 2)
		throw std::logic_error("Not enough elements for span detection");
		
	return *container_.rbegin() - *container_.begin();
}
