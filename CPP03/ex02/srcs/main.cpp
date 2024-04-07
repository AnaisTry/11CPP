/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:07:43 by angassin          #+#    #+#             */
/*   Updated: 2024/04/08 00:22:30 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

int	main()
{
	
    // Create a FragTrap object
    FragTrap frag("frag");

    // Print out the initial state of the FragTrap
    std::cout << frag.getName() << " has " << frag.getHitPoints() << " hitPoints, "
              << frag.getEnergyPoints() << " energyPoints, and "
              << frag.getDamage() << " attackDamage" << std::endl;

    // Test attacking with the FragTrap
    frag.attack("Target1");

    // Print out the state of the FragTrap after attacking
    std::cout << frag.getName() << " has " << frag.getHitPoints() << " hitPoints, "
              << frag.getEnergyPoints() << " energyPoints, and "
              << frag.getDamage() << " attackDamage" << std::endl;

    // Test taking damage and being repaired
    frag.takeDamage(20);
    frag.beRepaired(10);

    // Print out the state of the FragTrap after taking damage and being repaired
    std::cout << frag.getName() << " has " << frag.getHitPoints() << " hitPoints, "
              << frag.getEnergyPoints() << " energyPoints, and "
              << frag.getDamage() << " attackDamage" << std::endl;

    // Test the highFivesGuys function
    frag.highFivesGuys();

    return 0;
}
