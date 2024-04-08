/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:59:24 by angassin          #+#    #+#             */
/*   Updated: 2024/04/08 18:53:13 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal()
{
	std::cout << "Animal created" << std::endl;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type_ = other.type_;
	}
	return *this;
}

std::string Animal::getType() const
{
	return this->type_;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
