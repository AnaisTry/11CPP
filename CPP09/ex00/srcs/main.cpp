/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:31:03 by angassin          #+#    #+#             */
/*   Updated: 2024/10/20 13:41:56 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[], char *envp[])
{
	if (argc > 2)
	{
		std::cout << RED << "Usage: " << argv[0] << " path/to/config-file" << WHITE << std::endl;
		return (1);
	}
	return 0;
}