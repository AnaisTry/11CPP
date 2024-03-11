/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:45:13 by angassin          #+#    #+#             */
/*   Updated: 2024/03/11 09:20:01 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FileHandler.hpp"

int	main()
{
	FileHandler fh("Makefile");;
	if (fh.openInputFile())
		std::cout << "Passed : File opened successfully.\n";
	else
		std::cout << "Failed : File could not be opened.\n";

	FileHandler fh2("invalidFilename.txt");
	if (!fh2.openInputFile())
		std::cout << "Passed : Correctly failed to open non-existent file.\n";
	else
		std::cout << "Failed : opened a file that should not exist.\n";



	return 0;
}