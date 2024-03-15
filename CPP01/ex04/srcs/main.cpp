/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:45:13 by angassin          #+#    #+#             */
/*   Updated: 2024/03/15 17:34:56 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "FileHandler.hpp"


int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	
	FileHandler fh;

	fh.setFileName(argv[1]);

	if (!fh.openInputFile())	
		return 1;

	if (!fh.createOutputFile())
		return 2;

	fh.copyAndReplaceFile(argv[2], argv[3]);
	
	return 0;
}

// #include <cassert>

// int main()
// {
// 	/* tests */
// 	// fh.setFileName("Makefile");
// 	// if (fh.openInputFile())
// 	// 	std::cout << "Passed : File opened successfully.\n";
// 	// else
// 	// 	std::cout << "Failed : File could not be opened.\n";

	
	

// 	// fh.setFileName("NonexistentFile");
// 	// if (!fh.openInputFile())
// 	// 	std::cout << "Passed : Correctly failed to open non-existent file.\n";
// 	// else
// 	// 	std::cout << "Failed : opened a file that should not exist.\n";
	
// 	// fh.setFileName("Makefile");
// 	// if (fh.createOutputFile())
// 	// 	std::cout << "Passed : Output file created succesfully.\n";
// 	// else
// 	// 	std::cout << "Failed : Output file could not be created.\n";

// 	// Test 1: Basic replacement
//     assert(replace("Hello, world!", "world", "there") == "Hello, there!");

//     // Test 2: Multiple replacements
//     assert(replace("foo foo foo", "foo", "bar") == "bar bar bar");

//     // Test 3: 'from' string is a substring of 'to' string
//     assert(replace("foo foo foo", "foo", "foobar") == "foobar foobar foobar");

//     // Test 4: 'from' string not found in 'str'
//     assert(replace("Hello, world!", "earth", "there") == "Hello, world!");

//     // Test 5: Empty 'from' string
//     assert(replace("Hello, world!", "", "there") == "Hello, world!");

//     // Test 6: Empty 'to' string (removal)
//     assert(replace("Hello, world!", "world", "") == "Hello, !");

//     // Test 7: Empty 'str'
//     assert(replace("", "world", "there") == "");

//     // Test 8: 'from' and 'to' are the same
//     assert(replace("Hello, world!", "world", "world") == "Hello, world!");

// 	std::cout << "tests success" << std::endl;
// }