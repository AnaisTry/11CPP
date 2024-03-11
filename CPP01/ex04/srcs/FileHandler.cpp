/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:38:07 by angassin          #+#    #+#             */
/*   Updated: 2024/03/10 21:10:09 by angassin         ###   ########.fr       */
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
*/
bool FileHandler::openInputFile()
{
	inputFile_.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		inputFile_.open(filename_);
		return true;
	}
	catch (std::ifstream::failure& e)
	{
		return false;
	}
	

}