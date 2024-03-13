/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:45:13 by angassin          #+#    #+#             */
/*   Updated: 2024/03/13 12:07:42 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FileHandler.hpp"

int	main()
{
	FileHandler fh;
	fh.setFileName("Makefile");
	if (fh.openInputFile())
		std::cout << "Passed : File opened successfully.\n";
	else
		std::cout << "Failed : File could not be opened.\n";

	
	
	fh.closeInputFile();

	fh.setFileName("NonexistentFile");
	if (!fh.openInputFile())
		std::cout << "Passed : Correctly failed to open non-existent file.\n";
	else
		std::cout << "Failed : opened a file that should not exist.\n";
	
	fh.setFileName("Makefile");
	if (fh.createOutputFile(fh.outputFile_))
		std::cout << "Passed : Output file created succesfully.\n";
	else
		std::cout << "Failed : Output file could not be created.\n";
	

	return 0;
}