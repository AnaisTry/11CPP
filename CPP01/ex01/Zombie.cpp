/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:54:37 by angassin          #+#    #+#             */
/*   Updated: 2024/02/22 19:52:31 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>


Zombie::Zombie() : name_("")
{
	std::cout << "Zombie " << name_ << " created" << std::endl;
}
Zombie::Zombie(std::string name) : name_(name)
{
	std::cout << "Zombie " << name_ << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name_ << " destroyed" << std::endl;
}


void Zombie::announce(void)
{
	std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}
