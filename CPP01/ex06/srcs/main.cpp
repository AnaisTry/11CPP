/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:49:23 by angassin          #+#    #+#             */
/*   Updated: 2024/03/18 13:14:27 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	Harl h;
	int level = switch_select(argv[1]);
	switch (level)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			h.complain("DEBUG");
			std::cout << std::endl;
			// fall through

		case 1:
		std::cout << "[ INFO ]" << std::endl;
			h.complain("INFO");
			std::cout << std::endl;
			// fall through
			
		case 2:
		std::cout << "[ WARNING ]" << std::endl;
			h.complain("WARNING");
			std::cout << std::endl;
			// fall through
			
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			h.complain("ERROR");
			std::cout << std::endl;
			break;
			
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

	return 0;
}
