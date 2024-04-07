/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:06:30 by angassin          #+#    #+#             */
/*   Updated: 2024/04/07 17:49:03 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex01
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>	

ScavTrap::ScavTrap(): ClapTrap("Default")
{
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
	std::cout << "ScavTrap " << this->getName() << " created with " << this->hitPoints_ 
	<< " hit points, " << this->energyPoints_ << " energy points and " 
	<< this->attackDamage_ << " attack damage." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
		std::cout << "ScavTrap " << this->getName() << " created with " << this->hitPoints_ 
	<< " hit points, " << this->energyPoints_ << " energy points and " 
	<< this->attackDamage_ << " attack damage." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignment operator called from " << this->getName();
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
