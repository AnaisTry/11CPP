/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:14:38 by angassin          #+#    #+#             */
/*   Updated: 2024/07/03 11:46:41 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <climits>

// Default constructor
Span::Span() : maxN_(INT_MAX)
{
	std::cout << "Span container created" << std::endl;
}

Span::Span(unsigned int maxN) : maxN_(maxN)
{
	std::cout << "Span container of max " << maxN_ << " integers created" << std::endl;
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