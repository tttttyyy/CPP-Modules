#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <iomanip>
#include <cmath>

// #include <stdlib> 

class ScalarConverter
{
	public:
		static bool isNumber(const char*, const char*);
		static bool isInt();
		static bool isDouble();
		static bool isFloat();
		static void print();
		static void castChar();
		static void convert(char*);
		static bool	checkInf();

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter& operator=(const ScalarConverter &);
		~ScalarConverter();

		static char			m_char;
		static int			m_int;
		static float		m_float;
		static double		m_double;
		static double		m_literal;
		static std::string	m_argv;

	class unknownTypeException : public std::exception
	{
		const char* what() const throw();
	};
};

#endif