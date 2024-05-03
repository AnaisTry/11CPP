/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:50:20 by angassin          #+#    #+#             */
/*   Updated: 2024/04/24 18:19:52 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice created" << std::endl;
}

// Destructor
Ice::~Ice()
{
	std::cout << "Ice destroyed" << std::endl;
}

// Copy constructor
Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type_ = other.type_;
	}
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
