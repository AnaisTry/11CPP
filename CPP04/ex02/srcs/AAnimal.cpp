/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:59:24 by angassin          #+#    #+#             */
/*   Updated: 2024/04/08 18:53:13 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Default constructor
AAnimal::AAnimal()
{
	std::cout << "AAnimal created" << std::endl;
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destroyed" << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type_ = other.type_;
	}
	return *this;
}

std::string AAnimal::getType() const
{
	return this->type_;
}
