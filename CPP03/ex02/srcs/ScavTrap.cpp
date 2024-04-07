/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:06:30 by angassin          #+#    #+#             */
/*   Updated: 2024/04/07 18:42:36 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex01
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>	

// Default constructor
ScavTrap::ScavTrap()
{
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
	std::cout << "ScavTrap " << this->getName() << " created with " << this->hitPoints_ 
	<< " hit points, " << this->energyPoints_ << " energy points and " 
	<< this->attackDamage_ << " attack damage." << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
		std::cout << "ScavTrap " << this->getName() << " created with " << this->hitPoints_ 
	<< " hit points, " << this->energyPoints_ << " energy points and " 
	<< this->attackDamage_ << " attack damage." << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " destroyed" << std::endl;
}

// Assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignment operator called from " << this->getName();
	std::cout << " to " << other.getName() << std::endl; 
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

// Member functions
void ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints_ > 0 && this->hitPoints_ > 0)
	{
		std::cout << "ScavTrap " << this->name_ << " attacks " << target
		<< ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
		this->energyPoints_ -= 1;
	}
	else
	{
		std::cout << "ScavTrap " << this->name_ << " is out of energy points!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name_ << " has entered in Gate keeper mode." << std::endl;
}
