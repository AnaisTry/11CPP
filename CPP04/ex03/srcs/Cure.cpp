/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:56:49 by angassin          #+#    #+#             */
/*   Updated: 2024/04/15 15:02:29 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include <iostream>

// Default constructor
Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure created" << std::endl;
}

// Destructor
Cure::~Cure()
{
	std::cout << "Cure destroyed" << std::endl;
}

// Copy constructor
Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type_ = other.type_;
	}
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
