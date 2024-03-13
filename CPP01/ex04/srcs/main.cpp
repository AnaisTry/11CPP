/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:45:13 by angassin          #+#    #+#             */
/*   Updated: 2024/03/12 13:25:50 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FileHandler.hpp"

int	main()
{
	FileHandler fh;
	if (fh.openInputFile())
		std::cout << "Passed : File opened successfully.\n";
	else
		std::cout << "Failed : File could not be opened.\n";

	
	
	fh.closeInputFile();

	FileHandler fh2("invalidFilename.txt");
	if (!fh2.openInputFile())
		std::cout << "Passed : Correctly failed to open non-existent file.\n";
	else
		std::cout << "Failed : opened a file that should not exist.\n";
	
	

	return 0;
}