#include "BitcoinExchange.hpp"
		
BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		bitcoinRates_ = other.bitcoinRates_;
	return *this;
}

void	BitcoinExchange::loadBitcoinRates(const std::string& filename)
{
	std::ifstream	file(filename);
	std::string		line;
	
	std::getline(file,line);
	while(std::getline(file,line))
	{
		try
		{
			std::string	date, separator;
			double	rate;
			parseLine(line, ',', date, rate);
			bitcoinRates_[date] = rate;
		}
		catch(const std::exception& e)
		{
			std::cout << "Error parsing line: " << line << " - " << e.what() << '\n';
		}
	}	
}
		
double	BitcoinExchange::getBitcoinRate(const std::string& date, double amount) const
{
	std::map<std::string, double>::const_iterator	it = bitcoinRates_.lower_bound(date);
	if (it == bitcoinRates_.end() || it->first != date)
	{
		if (it == bitcoinRates_.begin())
			throw	std::runtime_error("Error: no valid date found for " + date);
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
			date.erase(date.find_last_not_of(" \t") + 1);
			valueStr.erase(0, valueStr.find_first_not_of(" \t"));
			valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

			if (!isValidDate(date))
				throw std::runtime_error("Error: bad input => " + line);

			std::istringstream valueStream(valueStr);
			if (!(valueStream >> value))
				throw std::runtime_error("Error: invalid rate in line: " + line);
			//  std::cout << RED << "Parsed line: date = " << date << ", value = " << value << WHITE << std::endl;

		} 
		else
			throw std::runtime_error("Error: bad input => " + line);
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	std::istringstream	iss(date);
	int	year, month, day;
	char	sep1, sep2;

	if (iss >> year >> sep1 >> month >> sep2 >> day && sep1 == '-' && sep2 == '-')
	{
		if (year >= 2000 && year <= 2050 && month >= 1 && month <= 12 && day >=1 && day <= 31)
		{
			if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
				return false;
			if (month == 2)
			{
				bool	isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
				if (day > 29 || (day == 29 && !isLeap))
					return false;
			}
			return true;
		}
	}
	return false;
}
