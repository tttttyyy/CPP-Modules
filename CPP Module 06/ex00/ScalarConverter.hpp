#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
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

		static char			m_char;
		static int			m_int;
		static float		m_float;
		static double		m_double;
		static double		m_literal;
		static std::string	m_argv;
		
	class unknownTypeException : std::exception
	{
		const char* what() const throw();
	};
};

#endif