/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 07:26:09 by angassin          #+#    #+#             */
/*   Updated: 2024/03/02 08:53:40 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include "HumanB.hpp"


HumanB::HumanB(std::string name): name_(name)
{
	std::cout << "HumanB constructed " << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}


void HumanB::attack() const
{
	std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl; 
	
}