/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:17:16 by angassin          #+#    #+#             */
/*   Updated: 2024/03/15 18:03:17 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLER_HPP
# define FILEHANDLER_HPP

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
		bool createOutputFile();
		void copyAndReplaceFile(const std::string& from, const std::string& to);

		
	private:
		std::string fileName_;
		std::ifstream inputFile_;
		std::ofstream outputFile_;
};

std::string replace(const std::string& str, const std::string& from, const std::string& to);

#endif