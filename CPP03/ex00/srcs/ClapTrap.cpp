/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:31:53 by angassin          #+#    #+#             */
/*   Updated: 2024/04/04 18:25:33 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap():name_(""), hitPoints_(10), energyPoints_(10),
	attackDamage_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name_(name), hitPoints_(10), energyPoints_(10),
	attackDamage_(0)
{
	std::cout << "ClapTrap " << this->name_ << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "copied " << other.name_ << " in " << std::endl;
	*this = other;
	
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap& operator=(const ClapTrap& other)
{
	std::cout << "Assignation operator called from " << this->name_;
	std::cout << " to " << other.getName() << std::endl; 
	if (this != &other)
		this->name_ = other.getName();

	return *this;
}

std::string ClapTrap::getName() const
{
	return this->name_;
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << this->name_ << " attacks " << target
	<< ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
}

