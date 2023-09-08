#ifndef  BITCOINEXCHANGE_HPP
#define  BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
// #include <exception>

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
		bool checkDate(std::string &);
		bool valiDate(unsigned int date[3]);

	private:
		std::string m_filename;
		std::map<std::string, float> database;
		std::map<std::string, float> input;
};

#endif