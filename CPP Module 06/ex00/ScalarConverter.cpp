#include "ScalarConverter.hpp"

char		ScalarConverter::m_char = '0';
int			ScalarConverter::m_int = 0;
float		ScalarConverter::m_float = 0;
double		ScalarConverter::m_double = 0;
double		ScalarConverter::m_literal = 0;
std::string	ScalarConverter::m_argv = "0";

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy)
{
	*this = toCopy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &toCopy)
{
	(void)toCopy;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void toChar(double d)
{
	if (d <= 32 || d == 127)
		std::cout << "Non displayable" << std::endl;
	else if (d > 32 && d < 127)
		std::cout << char(d) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void toInt(double d, std::string av)
{
	(void)d;
	(void)av;
	// if  (!d && !(d/10))
	// 	std::cout << d << std::endl;
	// else if  (!std::strtod(av, 10L) && av.length() > 1)
	// 	std::cout << "impossible" << std::endl;
	// std::cout << d << std::endl;

}

int	checkInf()
{
	// if (m_argv == "nan" || argv == "nanf")
	// else if (m_argv == "inf" || argv == "inff")
	// else if (m_argv == "-inf" || argv == "-inff")
	return (1);
}

void ScalarConverter::convert(char *ob)
{
	if (!ob)
		return ;
	char *null = NULL;
	m_argv = ob;
	m_literal = std::strtod(ob, &null);
	// std::cout << m_literal;
	// 	std::cout << "kukuuuu" << std::endl;
	if (checkInf())
	{
		throw unknownTypeException();
	}
	// std::cout << "char: ";
	// toChar(tmp);
	// std::cout << "int: ";
	// toInt(tmp, ob);


}

const char* ScalarConverter::unknownTypeException::what() const throw()
{
	return ("[ERROR] Unknown type conversion!");
}
