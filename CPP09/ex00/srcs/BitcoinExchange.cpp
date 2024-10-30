#include "BitcoinExchange.hpp"
		
BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != other)
		bitcoinRates_ = other.bitcoinRates_;
	return *this;
}

void	BitcoinExchange::loadBitcoinRates(const std::string& filename)
{
	std::ifstream	file(filename);
	std::string		line;
	while()
	{
		std::string	date, separator;
		double	rate;
		bitcoinRates_[date] = rate;
	}
		
}
		
double	BitcoinExchange::getBitcoinRate(const std::string& date, double amount) const
{
	std::map<std::string, double>::const_iterator	it = bitcoinRates_.lower_bound(date);
	if (it == bitcoinRates_.end() || it->first != date)
	{
		if (it == bitcoinRates_.begin())
			throw	std::runtime_error("error: ");
		--it;
	}
	return it->second * amount;
}

void	BitcoinExchange::parseLine(const std::string& line, const char& separator, std::string& date, double& value)
{
		
		std::istringstream	iss(line);
		std::string	valueStr;

		if (std::getline(iss, date, separator) && std::getline(iss, valueStr))
		{
			date.erase(0, date.find_first_not_of(" \t"));
			date.erase(0, date.find_last_not_of(" \t") + 1);
			valueStr.erase(0, date.find_first_not_of(" \t"));
			valueStr.erase(0, date.find_last_not_of(" \t") + 1);

			std::istringstream valueStream(valueStr);
			if (!(valueStream >> value))
				throw std::runtime_error("Error: invalid rate in line: " + line);
			
		} 
		else
			throw std::runtime_error("Error: invalid line format: " + line);
	}
}