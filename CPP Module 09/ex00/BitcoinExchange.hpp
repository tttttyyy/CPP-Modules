#ifndef  BITCOINEXCHANGE_HPP
#define  BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::string);
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange& operator=(const BitcoinExchange &);
		~BitcoinExchange();

		void exchange();
		void parseInput(std::string &);
		void convertDate(std::string &);

	private:
		std::string m_filename;
		std::map<unsigned int[3], float> database;
		std::map<unsigned int[3], float> input;
};

#endif