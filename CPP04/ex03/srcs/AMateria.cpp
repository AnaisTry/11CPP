/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:08:02 by angassin          #+#    #+#             */
/*   Updated: 2024/04/15 11:22:27 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

// Default constructor
AMateria::AMateria() : type_("default")
{
	std::cout << "AMateria created with default constructor" << std::endl;
}

// Parameterized constructor
AMateria::AMateria(const std::string& type) : type_(type)
{
	std::cout << "AMateria " << type_ << " created" << std::endl;
}

// Destructor
AMateria::~AMateria() 
{
	std::cout << "AMateria " << type_ << " destroyed" << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria& other) : type_(other.type_)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type_ = other.type_;
	}
	return *this;
}

const std::string& AMateria::getType() const
{
	return this->type_;
}
