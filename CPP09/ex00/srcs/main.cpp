/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:31:03 by angassin          #+#    #+#             */
/*   Updated: 2024/10/30 13:01:07 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[], char *envp[])
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		std::cout << RED << "Usage: " << argv[0] << " path/to/config-file" << WHITE << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange	exchange;
		exchange.loadBitcoinRates("data.csv");

		std::ifstream	input(argv[1]);
		if (!input.is_open())
			throw std::runtime_error("Error: could not open file." + std::string(argv[1]));

		std::string	line, date, valueStr;
		double	value;

		while(std::getline(input, line))
		{
			std::istringstream	iss(line);
			if (std::getline(iss, date, '|') && std::getline(iss, valueStr))
			{
				date.erase(0, date.find_first_not_of(" \t"));
				date.erase(0, date.find_last_not_of(" \t") + 1);

				double	result = exchange.getBitcoinRate(date, value);
				
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	

	
	return 0;
}