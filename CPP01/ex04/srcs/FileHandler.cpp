/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:38:07 by angassin          #+#    #+#             */
/*   Updated: 2024/03/13 11:11:25 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FileHandler.hpp"

# include <iostream>
# include <fstream> // std::ifstream, std::ofstream
# include <sstream> // std::stringstream
# include <ios> // std::ios_base

FileHandler::FileHandler() : fileName_("")
{
	std::cout << "FileHandler constructed with default constructor";
}

FileHandler::FileHandler(std::string fileName): fileName_(fileName)
{
	std::cout << "FileHandler constructed" << std::endl;
}

FileHandler::~FileHandler()
{
	std::cout << "FileHandler destroyed" << std::endl;
}


void FileHandler::setFileName(std::string fileName)
{
	fileName_ = fileName;
}

/*
	std::ios_base::badbit: Indicates a fatal I/O error, such as a disk read error.
	std::ios_base::failbit: Indicates a non-fatal I/O error, such as a format error.
	| : bitwise OR operator : creates a bit pattern that combines both masks
	c_str converts std::string to const char*
*/
bool FileHandler::openInputFile()
{
	inputFile_.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		inputFile_.open(fileName_.c_str());
		return true;
	}
	catch (std::ios_base::failure& e)
	{
		return false;
	}
	
}

void FileHandler::closeInputFile()
{
	inputFile_.close();
}

bool FileHandler::createOutputFile(std::ofstream& outputFile_)
{
	outputFile_.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	try
	{
		outputFile_.open((fileName_+".replace").c_str());
		return true;
	}
	catch (std::ios_base::failure& e)
	{
		return false;
	}
}

void FileHandler::closeOutputFile()
{
	outputFile_.close();
}