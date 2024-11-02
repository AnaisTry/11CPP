/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:31:03 by angassin          #+#    #+#             */
/*   Updated: 2024/11/02 00:38:52 by angassin         ###   ########.fr       */
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

		std::string	line, date;
		double	value;

		std::getline(input, line);

		while(std::getline(input, line))
		{
			try
			{
				BitcoinExchange::parseLine(line, '|', date, value);
				if (value < 0)
					throw std::runtime_error("Error: not a positive number.");
				if (value > 1000)
					throw std::runtime_error("Error: too large a number.");
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
