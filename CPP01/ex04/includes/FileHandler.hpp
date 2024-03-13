/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:17:16 by angassin          #+#    #+#             */
/*   Updated: 2024/03/13 12:00:38 by angassin         ###   ########.fr       */
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
		std::ofstream getOutputFile() const;
		void setFileName(std::string fileName);
		bool openInputFile();
		void closeInputFile();
		bool createOutputFile(std::ofstream& outputFile_);
		void closeOutputFile();
		// void readFile();
		// void writeFile(std::string content);

		
	private:
		std::string fileName_;
		std::ifstream inputFile_;
		std::ofstream outputFile_;
};

#endif