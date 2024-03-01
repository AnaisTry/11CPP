/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:25:43 by angassin          #+#    #+#             */
/*   Updated: 2024/03/01 15:04:38 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& weapon ): name_(name), weapon_(weapon)
{
	std::cout << "HumanA constructed " << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destroyed" << std::endl;
}

void HumanA::attack() const
{
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl; 
	
}