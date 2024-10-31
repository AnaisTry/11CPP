/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:31:03 by angassin          #+#    #+#             */
/*   Updated: 2024/10/31 18:19:46 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
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
			try
			{
				BitcoinExchange::parseLine(line, ',', date, value);
				double result = exchange.getBitcoinRate(date, value);
				std::cout << date << " => " << value << " = " << result << std::endl;
			}
			catch (const std::runtime_error& e)
			{
				std::cout << e.what() << '\n';
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	return 0;
}