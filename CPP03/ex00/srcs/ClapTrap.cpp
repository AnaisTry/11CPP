/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:31:53 by angassin          #+#    #+#             */
/*   Updated: 2024/04/04 16:42:56 by angassin         ###   ########.fr       */
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

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << this->name_ << " attacks " << target
	<< ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
}

