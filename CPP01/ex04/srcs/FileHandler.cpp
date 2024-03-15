/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:38:07 by angassin          #+#    #+#             */
/*   Updated: 2024/03/15 18:24:30 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FileHandler.hpp"

# include <iostream>
# include <string>
# include <fstream> // std::ifstream, std::ofstream
# include <sstream> // std::stringstream
# include <ios> // std::ios_base


FileHandler::FileHandler() : fileName_("")
{
	std::cout << "FileHandler constructed with default constructor" << std::endl;
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
	c_str() converts std::string to const char*
*/
bool FileHandler::openInputFile()
{
	inputFile_.open(fileName_.c_str());
	if(!inputFile_.is_open())
	{
		std::cerr << "Failed to open file." << std::endl;
		return false;
	}
	return true;	
}


bool FileHandler::createOutputFile()
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


void FileHandler::copyAndReplaceFile(const std::string& from, const std::string& to)
{
	std::string line;
	if (inputFile_.is_open())
	{
		while(getline(inputFile_, line))
		{
			outputFile_ << replace(line, from, to) << std::endl;
			if (!outputFile_) 
			{
				std::cerr << "Error writing to output file." << std::endl;
				break;
			}
			if (inputFile_.fail() && !inputFile_.eof()) 
				std::cerr << "Error reading from input file." << std::endl;
		}
	}
	else
	    std::cerr << "Input file is not open." << std::endl;

	inputFile_.close();
	outputFile_.close();
}

/* 
	static const size_t npos = -1; used to state "not found" 
	to.find(from) != std::string::npos check is used to determine 
	if the from string is a substring of the to string.	
*/
std::string replace(const std::string& str, const std::string& from, const std::string& to)
{
	if(from.empty())
		return str;
	std::string replacedStr = str;
	std::string::size_type pos = 0;
	while ((pos = replacedStr.find(from, pos)) != std::string::npos)
	{
		replacedStr.erase(pos, from.length());
		replacedStr.insert(pos, to);
		pos += to.length();
    }
	return replacedStr;
}
