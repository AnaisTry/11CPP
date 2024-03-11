/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:38:07 by angassin          #+#    #+#             */
/*   Updated: 2024/03/11 09:49:27 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FileHandler.hpp"

# include <iostream>
# include <fstream> // std::ifstream, std::ofstream
# include <sstream> // std::stringstream
# include <ios> // std::ios_base

FileHandler::FileHandler(std::string filename): filename_(filename)
{
	std::cout << "FileHandler constructed" << std::endl;
}

FileHandler::~FileHandler()
{
	std::cout << "FileHandler destroyed" << std::endl;
}

/*
	std::ios_base::badbit: Indicates a fatal I/O error, such as a disk read error.
	std::ios_base::failbit: Indicates a non-fatal I/O error, such as a format error.
	c_str converts std::string to const char*
*/
bool FileHandler::openInputFile()
{
	inputFile_.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		inputFile_.open(filename_.c_str());
		return true;
	}
	catch (std::ios_base::failure& e)
	{
		return false;
	}
	
}

bool FileHandler::openOutputFile()
{
	outputFile_.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	try
	{
		outputFile_.open(filename_.c_str());
		return true;
	}
	catch (std::ios_base::failure& e)
	{
		return false;
	}
}