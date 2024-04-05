/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:07:43 by angassin          #+#    #+#             */
/*   Updated: 2024/04/05 12:36:10 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap anonymous;
	ClapTrap robot("robot");
	ClapTrap robotCopy(robot);

	anonymous = robot;

	std::cout << "Anonymous' name: " << anonymous.getName() << std::endl;
	return 0;
}
