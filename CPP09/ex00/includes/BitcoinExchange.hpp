#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>

# define RED "\033[31m"
# define WHITE "\033[37m"
class BitcoinExchange
{
	public:
		BitcoinExchange();
		virtual ~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void	loadBitcoinRates(const std::string& filename);
		double	getBitcoinRate(const std::string& date, double amount) const;

		static void	parseLine(const std::string& line, const char& separator, std::string& date, double& value);
		static bool	isValidDate(const std::string& date);
	 private:
		std::map<std::string, double> bitcoinRates_;
		
};

#endif