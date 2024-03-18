/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:49:23 by angassin          #+#    #+#             */
/*   Updated: 2024/03/18 12:56:24 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
# include <iostream>

int main()
{
	Harl harl;

	std::cout << std::endl;
	std::cout << "[ DEBUG ]" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "[ INFO ]" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "[ WARNING ]" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "[ ERROR ]" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "[ ]" << std::endl;
	harl.complain("");
	std::cout << std::endl;

	return 0;
}