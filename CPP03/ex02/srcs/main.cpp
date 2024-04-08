/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:07:43 by angassin          #+#    #+#             */
/*   Updated: 2024/04/08 12:25:41 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

int	main()
{
	
    FragTrap frag("frag");

    // initial state of the FragTrap
    std::cout << std::endl << frag.getName() << " has " << frag.getHitPoints() 
			  << " hitPoints, " << frag.getEnergyPoints() << " energyPoints, and "
              << frag.getDamage() << " attackDamage" << std::endl << std::endl;

    // Test attacking with the FragTrap
    frag.attack("Target1");

    // Print out the state of the FragTrap after attacking
    std::cout << frag.getName() << " has " << frag.getHitPoints() << " hitPoints, "
              << frag.getEnergyPoints() << " energyPoints, and "
              << frag.getDamage() << " attackDamage" << std::endl << std::endl;

    // Test taking damage and being repaired
    frag.takeDamage(20);
    frag.beRepaired(10);

    // Print out the state of the FragTrap after taking damage and being repaired
    std::cout << std::endl << frag.getName() << " has " << frag.getHitPoints() 
			  << " hitPoints, " << frag.getEnergyPoints() << " energyPoints, and "
              << frag.getDamage() << " attackDamage" << std::endl << std::endl;

    // Test the highFivesGuys function
    frag.highFivesGuys();

    return 0;
}
