/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 00:00:12 by angassin          #+#    #+#             */
/*   Updated: 2024/04/08 00:15:18 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
	std::cout << "FragTrap " << this->getName() << " created" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
	std::cout << "FragTrap " << this->getName() << " created with" << this->hitPoints_
	<< " hit points, " << this->energyPoints_ << " energy points and " << this->attackDamage_
	<< " attack damage." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignment operator called from " << this->getName();
	std::cout << " to " << other.getName() << std::endl; 
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}

	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " requests a high five!" << std::endl;
}
