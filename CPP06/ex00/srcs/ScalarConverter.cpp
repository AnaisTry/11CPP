/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:36:05 by angassin          #+#    #+#             */
/*   Updated: 2024/05/22 18:45:26 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
# include <iostream>
# include <string>
# include <cctype> //isprint
# include <sstream>

void ScalarConverter::convert(const std::string& input)
{
	// Check if the input is a char (non displayable char should not be used as inputs)
	if (input.length() == 1 && !isdigit(input[0]))
	{
		convertAndPrint<char>(input);
	}	
	// Check if the input is an int
	else if (input.find_first_not_of("0123456789-") == std::string::npos)
	{
		convertAndPrint<int>(input);
	}
	// Check if the input is a float
	else if (input.find_first_not_of("0123456789.-f") == std::string::npos || input == "nanf" 
		|| input == "+inff" || input == "-inff")
	{
		convertAndPrint<float>(input);
	}
	// Check if the input is a double
	else if (input.find_first_not_of("0123456789.-") == std::string::npos || input == "nan" 
		|| input == "+inf" || input == "-inf")
	{
		convertAndPrint<double>(input);
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
	}
	
}

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& other)
{
	(void)other;
	return *this;
}

