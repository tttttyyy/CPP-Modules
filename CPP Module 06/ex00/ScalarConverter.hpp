#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
// #include <stdlib> 

class ScalarConverter
{
	public:
		static void convert(char* );
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter& operator=(const ScalarConverter &);
		~ScalarConverter();

		char	m_char;
		int		m_int;
		float	m_float;
		double	m_double;
};

#endif