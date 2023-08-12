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

void ScalarConverter::castChar()
{
	if (m_argv.size() == 1)
	{
		m_char = m_argv[0];
		m_double = static_cast<double>(m_argv[0]);
		m_int = static_cast<int>(m_argv[0]);
		m_float = static_cast<float>(m_argv[0]);
	}
}


void ScalarConverter::printChar()
{
	if(std::isprint(m_char))
		std::cout << m_char << std::endl;
	else
		std::cout << "Not displayable" << std::endl;

	// if (d <= 32 || d == 127)
	// else if (d > 32 && d < 127)
	// 	std::cout << char(d) << std::endl;
	// else
	// 	std::cout << "impossible" << std::endl;
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

int	ScalarConverter::checkInf()
{
	if (m_argv == "nan" || m_argv == "nanf")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: nanf" << std::endl
				  << "double: nan" << std::endl;
	}
	else if (m_argv == "inf" || m_argv == "inff")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: inff" << std::endl
				  << "double: inf" << std::endl;
	}
	else if (m_argv == "-inf" || m_argv == "-inff")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: -inff" << std::endl
				  << "double: -inf" << std::endl;
	}
	else
		return (0);
	return (1);
}

bool ScalarConverter::isNumber(const char *ob, const char *null)
{
	if (null != ob && (*null == '\0'))
	;
	return (false);
}

void ScalarConverter::convert(char *ob)
{
	if (!ob)
		return ;
	char *null = NULL;
	m_argv = ob;
	m_literal = std::strtod(ob, &null);
	if (checkInf())
		;
	else if (!m_literal && ob[0] != '0' && m_argv.size() == 1)
	{
		castChar();
		printChar();
	}
	else if (isNumber(ob, null))
	{
		std::cout << "hihi" << std::endl;
	}
	else
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
