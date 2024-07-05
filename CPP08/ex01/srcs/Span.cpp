/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:14:38 by angassin          #+#    #+#             */
/*   Updated: 2024/07/05 19:27:02 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <climits>
#include <stdexcept> // logic_error, runtime_error
#include <algorithm> // min_element
#include <numeric> // adjacent_difference
#include <vector>
#include <cstdlib> // rand, srand

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
		throw std::runtime_error("The container is full, can't add more elements");
}

void Span::addRange(size_t rangeSize)
{

	if (container_.size() + rangeSize > maxN_)
		throw std::runtime_error("Adding this range exceeds maximum allowed size");

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (size_t i = 0; i < rangeSize; ++i)
		container_.insert(std::rand());
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
	adjacent_difference stores the first input, so we need to skip it to avoid wrong results
*/
size_t Span::shortestSpan() const
{
	if (container_.size() < 2)
		throw std::logic_error("Not enough elements for span detection");

	std::vector<size_t> span(container_.size());
	std::adjacent_difference(container_.begin(), container_.end(), span.begin());

	return *std::min_element(span.begin() + 1, span.end());
}

size_t Span::longestSpan() const
{
	if (container_.size() < 2)
		throw std::logic_error("Not enough elements for span detection");

	return *container_.rbegin() - *container_.begin();
}
