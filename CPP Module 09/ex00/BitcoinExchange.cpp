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
	std::ifstream	database ("data.csv");
	if (!database.is_open())
	{
		std::cerr << "\033[1;31m[ERROR] NO SUCH DATABASE FILE !\033[0m" << std::endl;
		exit(2);
	}
	std::string tmpData;
	if (!getline(database, tmpData))
	{
		std::cerr << "\033[1;31m[ERROR] DATABASE FILE IS EMPTY !\033[0m" << std::endl;
		database.close();
		exit(2);
	}
	while (getline(database, tmpData))
	{
		if(tmpData.empty())
			continue;
		parseDatabase(tmpData);
	}



	std::ifstream	infile (m_filename);
	if (!infile.is_open())
	{
		std::cerr << "\033[1;31m[ERROR] NO SUCH INPUT FILE !\033[0m" << std::endl;
		exit(2);
	}
	std::string tmpInput;
	if (!getline(infile, tmpInput))
	{
		std::cerr << "\033[1;31m[ERROR] INPUT FILE IS EMPTY !\033[0m" << std::endl;
		infile.close();
		exit(2);
	}
	while (getline(infile, tmpInput))
	{
		if(tmpInput.empty())
			continue;
		parseInput(tmpInput);
	}
}

void BitcoinExchange::parseDatabase(std::string & tmp)
{
	std::istringstream iss(tmp);
	std::string date;
	std::string value;
	if (!(std::getline(iss, date, ',')))
		throw IncorrectDatabaseException();
	iss >> value;
	float f = strtof(value.c_str(), NULL);
	if (!checkDate(date))
		throw IncorrectDatabaseException();

	m_database.insert(std::make_pair(date, f));
}

void BitcoinExchange::parseInput(std::string &tmp)
{
	std::string date;
	std::string value;
	std::istringstream iss(tmp);
	if (!(std::getline(iss, date, '|')) || !tmp.find("|"))
		std::cerr << "Error: bad input => " << tmp << std::endl;
	iss >> value;
	float f = strtof(value.c_str(), NULL);
	// float f = atof(date.c_str());
	if (!checkDate(date) || value.find(" ") != std::string::npos || date.empty() || value.empty())
		std::cerr << "Error: bad input => " << tmp << std::endl;
	else if (f < 0)
		std::cerr << "Error: not a positive number." << std::endl;
	else if (f > 1000)
		std::cerr << "Error: too large a number." << std::endl;
	else
	{
		std::string tmp = trim(date);
		std::pair<std::string, float> curr = matchingRate(tmp);
		std::cout << tmp << " => " << f << " = " << f * curr.second << std::endl; 
	}
}

std::string BitcoinExchange::trim(std::string date)
{
	int i;
	for(i = 0; std::isspace(date[i]); i++)
		;
	std::string tmp = date.substr(i);
	int e;
	for(e = tmp.size() - 1; std::isspace(tmp[e]); e--)
		;
	std::string tmp1 = tmp.substr(0, e + 1);
	return(tmp1);
}
std::pair<std::string, float> BitcoinExchange::matchingRate(std::string date)
{
	std::map<std::string, float>::reverse_iterator it;
	for(it = m_database.rbegin(); it != m_database.rend(); ++it)
        if (it->first <= date)
            return std::make_pair(it->first, it->second);
	return std::make_pair(m_database.begin()->first, m_database.begin()->second);
}

bool BitcoinExchange::checkDate(std::string &date)
{
	std::string date_tmp = trim(date);
	if(date_tmp.find(" ") != std::string::npos || date_tmp.empty())
		return(false);
	static unsigned int datetmp[3];
	std::string datecurr;
	std::istringstream iss(date_tmp);
	for (int i = 0; i < 3; i++)
	{
		std::getline(iss, datecurr, '-');
		datetmp[i] = atoi(datecurr.c_str());
	}
	std::string left;
	iss >> left;
	if (!valiDate(datetmp) || !left.empty())
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

const char* BitcoinExchange::IncorrectDatabaseException::what() const throw()
{
	return("\33[1;31m[ERROR] Incorrect Database !\33[0;m");	
}