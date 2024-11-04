/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:33 by angassin          #+#    #+#             */
/*   Updated: 2024/11/04 14:34:43 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Default constructor
RPN::RPN()
{
	// std::cout << "RPN created" << std::endl;
}

// Destructor
RPN::~RPN()
{
	// std::cout << "RPN destroyed" << std::endl;
}

// Copy constructor
RPN::RPN(const RPN& other)
{
	// std::cout << "RPN copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
RPN& RPN::operator=(RPN const& other)
{
	// std::cout << "RPN assignment operator called" << std::endl;
	if (this != &other) {
		// Copy data members from other
	}
	return *this;
}
