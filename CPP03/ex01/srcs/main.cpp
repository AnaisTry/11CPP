/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:07:43 by angassin          #+#    #+#             */
/*   Updated: 2024/04/08 12:02:20 by angassin         ###   ########.fr       */
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
	scav.beRepaired(10);
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

	// test guardgate
	scavonymous.guardGate();

	std::cout << std::endl;

	// Create multiple ScavTrap objects
    ScavTrap scav1("Scav1");
	std::cout << std::endl;
    ScavTrap scav2("Scav2");
	std::cout << std::endl;
    ScavTrap scav3("Scav3");
	std::cout << std::endl;

    // Test attacking with each ScavTrap
    scav1.attack("Target1");
    scav2.attack("Target2");
    scav3.attack("Target3");
	std::cout << std::endl;

    // Test that the actions of one ScavTrap don't affect the others
    scav1.takeDamage(20);
    scav2.beRepaired(10);
    scav3.guardGate();
	std::cout << std::endl;

    // Print out the state of each ScavTrap again to check if they've changed correctly
    std::cout << scav1.getName() << " has " << scav1.getHitPoints() << " hitPoints, "
              << scav1.getEnergyPoints() << " energyPoints, and "
              << scav1.getDamage() << " attackDamage" << std::endl;

    std::cout << scav2.getName() << " has " << scav2.getHitPoints() << " hitPoints, "
              << scav2.getEnergyPoints() << " energyPoints, and "
              << scav2.getDamage() << " attackDamage" << std::endl;

    std::cout << scav3.getName() << " has " << scav3.getHitPoints() << " hitPoints, "
              << scav3.getEnergyPoints() << " energyPoints, and "
              << scav3.getDamage() << " attackDamage" << std::endl << std::endl;
	

	return 0;
}
