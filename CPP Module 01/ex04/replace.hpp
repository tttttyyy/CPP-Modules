#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <iomanip>

class Replace
{
	public:
		Replace(std::string, std::string, std::string);
		void	replaceStrings(void);
	private:
		std::string m_filename;
		std::string s1;
		std::string s2;
};



#endif