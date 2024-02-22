/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:01:20 by angassin          #+#    #+#             */
/*   Updated: 2024/02/22 22:02:21 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

int main()
{
	Weapon weapon("M4A1");
	std::cout << weapon.getType() << std::endl;
	weapon.setType("AK-47");
	std::cout << weapon.getType() << std::endl;
	return 0;
}