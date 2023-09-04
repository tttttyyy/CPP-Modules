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
		std::cerr << "\033[1;31m" << "[ERROR] FILE IS EMPTY !" << "\033[0m" << std::endl;
		infile.close();
		exit(2);
	}
	parseInput(tmp);
	// while (pos != std::string::npos)
	// 	m_filedata.push()

}

void BitcoinExchange::parseInput(std::string &tmp)
{
	std::string date;
	std::string value;
	size_t	pos;
	pos = tmp.find(" | ");
	std::istringstream iss(tmp);
	// while (getline(iss, date, '|'))
	std::getline(iss, date, '|');
	std::cout << date << std::endl;
	iss >> value;
	float f = strtof(value.c_str(), NULL);
	// float f = atof(date.c_str());
	std::cout << f << std::endl;
	// std::vector<int>::iterator it;
	// for (it = m_arr.begin(); it != m_arr.end(); it++)
	// 	std::cout << *it << std::endl;

}

void convertDate(std::string &date)
{
	int datetmp[3];
	std::istringstream iss(date);
	std::getline(iss, datetmp[0], '-');
	std::cout << datetmp[0] << std::endl;

}
// std::string		tmp;
// 	size_t			index = 0;

// 	std::ofstream outfile(m_filename + ".replace");
// 	{
// 		outfile << tmp.substr(index, pos - index);
// 		outfile << s2;
// 		index = pos + s1.length();
// 		pos = tmp.find(s1, pos + s1.length() + 1);
// 	}
// 	outfile << tmp.substr(index);
// 	outfile.close();
// 	infile.close();