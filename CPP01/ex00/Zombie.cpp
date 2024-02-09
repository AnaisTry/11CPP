/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:54:37 by angassin          #+#    #+#             */
/*   Updated: 2024/02/09 21:51:15 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

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

/*
	allocates a zombie, name it, and return it 
	so it can be used outside of the function
*/
Zombie* newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return zombie;
}
void randomChump(std::string name)
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}

