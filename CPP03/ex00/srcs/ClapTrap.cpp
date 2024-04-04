/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:31:53 by angassin          #+#    #+#             */
/*   Updated: 2024/04/04 18:06:10 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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

ClapTrap::ClapTrap& operator=(const ClapTrap& other)
{
	if (this != &other)
		this
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << this->name_ << " attacks " << target
	<< ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
}

