/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:17:16 by angassin          #+#    #+#             */
/*   Updated: 2024/03/14 10:05:49 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLER_HPP
# define FILEHANDLER_HPP

# include <iostream>
# include <fstream> // std::ifstream, std::ofstream
# include <sstream> // std::stringstream 

class FileHandler
{
	public:
		FileHandler();
		FileHandler(std::string fileName);
		~FileHandler();
		void setFileName(std::string fileName);
		bool openInputFile();
		void closeInputFile();
		bool createOutputFile();
		void closeOutputFile();
		void copyAndReplaceFile();

		
	private:
		std::string fileName_;
		std::ifstream inputFile_;
		std::ofstream outputFile_;
};

std::string replace(const std::string& str, const std::string& from, const std::string& to);

#endif