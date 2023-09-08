#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::string filename) : m_filename(filename) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &toCopy)
{(void)toCopy;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &toCopy)
{(void)toCopy; return(*this);}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::exchange()
{
	std::ifstream	infile (m_filename);
	if (!infile.is_open())
	{
		std::cerr << "\033[1;31m[ERROR] NO SUCH FILE !\033[0m" << std::endl;
		exit(2);
	}
	std::string tmp;
	if (!getline(infile, tmp))
	{
		std::cerr << "\033[1;31m[ERROR] FILE IS EMPTY !\033[0m" << std::endl;
		infile.close();
		exit(2);
	}
	parseInput(tmp);
	while (getline(infile, tmp))
		parseInput(tmp);
}

void BitcoinExchange::parseInput(std::string &tmp)
{
	std::string date;
	std::string value;
	std::istringstream iss(tmp);
	if (!(std::getline(iss, date, '|')))
		std::cerr << "Error: bad input => " << tmp << std::endl;
	iss >> value;
	float f = strtof(value.c_str(), NULL);
	// float f = atof(date.c_str());
	if (!checkDate(date))
		std::cerr << "Error: bad input => " << tmp << std::endl;
	else if (f < 0)
		std::cerr << "Error: not a positive number." << std::endl;
	else if (f > 1000)
		std::cerr << "Error: too large a number." << std::endl;
	else
	{
		std::pair<std::string, float> curr = fittingRate();
		input[date] = f;
	}
}

std::pair<std::string, float> BitcoinExchange::fittingRate(const std::pair<std::string, float> &input)
{
	
}

bool BitcoinExchange::checkDate(std::string &date)
{
	static unsigned int datetmp[3];
	std::string datecurr;
	std::istringstream iss(date);
	for (int i = 0; i < 3; i++)
	{
		std::getline(iss, datecurr, '-');
		datetmp[i] = atoi(datecurr.c_str());
	}
	if (!valiDate(datetmp))
		return false; //write vaild date funtion idtead of this if
	return(true);
}

bool leapYear(unsigned int year)
{
	return(!(year % 400) || (!(year % 4) && year % 100));
}

bool BitcoinExchange::valiDate(unsigned int date[3])
{
	if (date[0] < 2009)
		return (false);
	switch(date[1])
	{
		case 4:
		case 6:
		case 9:
		case 11:
			return date[2] <= 30;
		case 2:
			if(leapYear(date[0]))
				return date[2] <= 29;
			else
				return date[2] <= 28;
		default:
			return date[2] <=31;
	}
	return(true);
}