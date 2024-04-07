/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:07:43 by angassin          #+#    #+#             */
/*   Updated: 2024/04/07 18:11:28 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int	main()
{
	
	ScavTrap scavonymous;

	std::cout << std::endl;

	ScavTrap scav("scav");

	std::cout << std::endl;

	
	std::cout << "ScavTrap's attributes before battle:" << std::endl;
	std::cout <<  scav.getName() << " has " << scav.getHitPoints() << " hitPoints, " <<
	scav.getEnergyPoints() << " energyPoints, and " <<
	scav.getDamage() << " attackDamage" << std::endl << std::endl;

	// test attack, takeDamage and beRepaired
	scav.attack("Target");
	std::cout << scav.getName() << "'s energy points: " << scav.getEnergyPoints() << std::endl;
	scav.takeDamage(20);
	std::cout << scav.getName() <<"'s hit points: " << scav.getHitPoints() << std::endl << std::endl;
	
	scav.beRepaired(5);
	std::cout << scav.getName() <<"'s hit points: " << scav.getHitPoints() << std::endl << std::endl;
	scav.beRepaired(0);
	scav.beRepaired(10); // This should not cause hitPoints_ to go above its maximum value
	scav.takeDamage(500); // This should not cause hitPoints_ to go below 0
	std::cout << scav.getName() <<"'s hit points: " << scav.getHitPoints() << std::endl << std::endl;
	
	while (scav.getEnergyPoints() > 0 && scav.getHitPoints() > 0)
	{
		scav.attack("Target");
	}
	std::cout << scav.getName() <<"'s hit points: " << scav.getHitPoints() << std::endl << std::endl;	
	std::cout << scav.getName() << "'s energy points: " << scav.getEnergyPoints() << std::endl;
	scav.attack("Target");
		
	std::cout << std::endl;

	// test copy constructor
	ClapTrap scavCopy(scav);
	std::cout << "scavCopy's name: " << scavCopy.getName() << " has : " << scavCopy.getEnergyPoints() << " energy points, " 
		<< scavCopy.getHitPoints() << " hit points and " << scavCopy.getDamage() << " attackDamage"  << std::endl << std::endl;

	// test assignment operator
	scavonymous = scav;
	std::cout << "Scavonymous' name: " << scavonymous.getName() << " has : " << scavonymous.getEnergyPoints() << " energy points, " 
		<< scavonymous.getHitPoints() << " hit points and " << scavonymous.getDamage() << " attackDamage"  << std::endl << std::endl;

	return 0;
}
