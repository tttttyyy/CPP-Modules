#ifndef  BITCOINEXCHANGE_HPP
#define  BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::string);
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange& operator=(const BitcoinExchange &);
		~BitcoinExchange();
	private:
		std::string m_filename;
		std::vector<std::string> m_filedata;
		std::map<unsigned int[3], float> database;
		std::map<unsigned int[3], float> input;
};

#endif