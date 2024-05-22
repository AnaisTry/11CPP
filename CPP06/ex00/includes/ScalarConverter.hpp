/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:13:43 by angassin          #+#    #+#             */
/*   Updated: 2024/05/22 17:54:31 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cctype>

class ScalarConverter
{
	public:
		static void convert(std::string const& input);

	 private:
		ScalarConverter();
		virtual ~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(ScalarConverter const& other);
};

template <typename T, typename V>
void printValue(const T& value, const std::string& typeName)
{
	if (value >= std::numeric_limits<V>::lowest() && value <= std::numeric_limits<V>::max())
		std::cout << typeName << ": " << static_cast<V>(value);
	else
		std::cout << typeName << ": impossible";
	if (typeName == "float" || typeName == "double")
		std::cout << (typeName == "float" ? ".0f" : ".0");
	std::cout << std::endl;
}

template <typename T>
void printValues(const T& value)
{
	    std::cout << "char: ";
        if (value >= 0 && value <= 127 && isprint(static_cast<char>(value)))
            std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
        else if (value >= 0 && value <= 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;
        printValue<T, int>(value, "int");
        printValue<T, float>(value, "float");
		printValue<T, double>(value, "double");
}

template <typename T>
void convertAndPrint(const std::string& input)
{
	T value;
	std::istringstream iss(input);
	iss >> value;
	if (iss.fail())
	{
		std::cout << "Value out of range" << std::endl;
		return;
	}
	printValues(value);
}

#endif