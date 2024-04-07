/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:31:53 by angassin          #+#    #+#             */
/*   Updated: 2024/04/08 00:24:14 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap():name_("Default"), hitPoints_(10), energyPoints_(10),
	attackDamage_(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	name_(name), hitPoints_(10), energyPoints_(10),
	attackDamage_(0)
{
	std::cout << "ClapTrap " << this->name_ << " created with " << this->hitPoints_ 
	<< " hitpoints, " << this->energyPoints_ << " energy points and " << this->attackDamage_
	<< " attack damage." << std::endl;	
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
	*this = other;
	
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Assignment operator called from " << this->name_;
	std::cout << " to " << other.getName() << std::endl; 
	if (this != &other)
	{
		this->name_ = other.getName();
		this->hitPoints_ = other.getHitPoints();
		this->energyPoints_ = other.getEnergyPoints();
		this->attackDamage_ = other.getDamage();
	}

	return *this;
}

std::string ClapTrap::getName() const
{
	return this->name_;
}

int ClapTrap::getHitPoints() const
{
	return this->hitPoints_;
}

int ClapTrap::getEnergyPoints() const
{
	return this->energyPoints_;
}

int ClapTrap::getDamage() const
{
	return this->attackDamage_;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints_ > 0 && this->hitPoints_ > 0)
	{
		std::cout << "ClapTrap " << this->name_ << " attacks " << target
		<< ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
		this->energyPoints_ -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << this->name_ << " is out of energy points!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->energyPoints_ > 0 && this->hitPoints_ > 0)
    {
        if (amount > this->hitPoints_) 
		{
            std::cout << "ClapTrap " << this->name_ << " takes " << this->hitPoints_
            << " points of damage!" << std::endl;
            this->hitPoints_ = 0;
        } 
		else 
		{
            this->hitPoints_ -= amount;
            std::cout << "ClapTrap " << this->name_ << " takes " << amount
            << " points of damage!" << std::endl;
        }
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints_ > 0 && this->hitPoints_ > 0)
	{
		this->hitPoints_ += amount;
		std::cout << "ClapTrap " << this->name_ << " is repaired for " << amount
		<< " points!" << std::endl;
		this->energyPoints_ -= 1;
	}
}
