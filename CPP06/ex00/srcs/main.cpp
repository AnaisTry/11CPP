/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:13:13 by angassin          #+#    #+#             */
/*   Updated: 2024/05/22 12:16:14 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert <string to convert>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}