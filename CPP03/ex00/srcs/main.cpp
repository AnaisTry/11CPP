/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:07:43 by angassin          #+#    #+#             */
/*   Updated: 2024/04/08 12:00:21 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap anonymous;
	ClapTrap robot("robot");
	

	std::cout << std::endl;	

		
	
	std::cout << "ClapTrap's attributes before battle:" << std::endl;
	std::cout <<  robot.getName() << " has " << robot.getHitPoints() << " hitPoints, " <<
	robot.getEnergyPoints() << " energyPoints, and " <<
	robot.getDamage() << " attackDamage" << std::endl << std::endl;

	// test attack, takeDamage and beRepaired
	robot.attack("Target");
	std::cout << robot.getName() << "'s energy points: " << robot.getEnergyPoints() << std::endl;
	robot.takeDamage(5);
	std::cout << robot.getName() <<"'s hit points: " << robot.getHitPoints() << std::endl << std::endl;
	
	robot.beRepaired(5);
	std::cout << robot.getName() <<"'s hit points: " << robot.getHitPoints() << std::endl << std::endl;
	robot.beRepaired(0);
	robot.beRepaired(1000); 
	robot.takeDamage(1000); // This should not cause hitPoints_ to go below 0
	std::cout << robot.getName() <<"'s hit points: " << robot.getHitPoints() << std::endl << std::endl;
	
	while (robot.getEnergyPoints() > 0)
	{
		robot.attack("Target");
	}
	std::cout << robot.getName() <<"'s hit points: " << robot.getHitPoints() << std::endl << std::endl;	
	std::cout << robot.getName() << "'s energy points: " << robot.getEnergyPoints() << std::endl;
	robot.attack("Target");
		
	std::cout << std::endl;

	// test copy constructor
	ClapTrap robotCopy(robot);
	std::cout << "robotCopy's name: " << robotCopy.getName() << " has : " << robotCopy.getEnergyPoints() << " energy points, " 
		<< robotCopy.getHitPoints() << " hit points and " << robotCopy.getDamage() << " attackDamage"  << std::endl << std::endl;

	// test assignment operator
	anonymous = robot;
	std::cout << "Anonymous' name: " << anonymous.getName() << std::endl << std::endl;

	return 0;
}
