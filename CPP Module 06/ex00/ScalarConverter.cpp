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

void ScalarConverter::print()
{
	std::cout << "char: ";
	if(std::isprint(m_char))
		std::cout << m_char << std::endl;
	else
		std::cout << std::setw(15) <<  "Not displayable" << std::endl;
	std::cout << "int: " << std::setw(2) << m_int << std::endl;
	std::cout << "float: ";
	if (m_argv.find('.') == std::string::npos || m_literal == floor(m_literal))
		std::cout << m_float << ".0f" << std::endl;
	else
		std::cout << m_float << "f" << std::endl;
	std::cout << "double: ";
	if (m_argv.find('.') == std::string::npos || m_literal == floor(m_literal))
		std::cout << m_float << ".0" << std::endl;
	else
		std::cout << m_float << std::endl;

}

bool ScalarConverter::isInt()
{
	if (m_argv.empty() || (!std::isdigit(m_argv[0]) && m_argv[0] != '-' && m_argv[0] != '+'))
		return (false);
	m_double = static_cast<double>(m_literal);
	m_char = static_cast<char>(m_int);
	m_int = static_cast<int>(m_literal);
	m_float = static_cast<float>(m_literal);
	if (m_argv.find('.') != std::string::npos)
		return (false);
	return (true);
}

bool ScalarConverter::isFloat()
{
	if (m_argv.find('f') == std::string::npos || m_argv.find('f') + 1 != m_argv.size())
		return (false);
	isDouble();
	return (true);
}

bool ScalarConverter::isDouble()
{
	if (m_argv.find('.') == std::string::npos)
		return (false);
	if (m_argv.size() > 1 && m_argv[0] == '0' && m_argv[1] != '.')
        return false;
	isInt();
	if (m_argv.find('f') != std::string::npos)
		return (false);
	return (true);
}
bool	ScalarConverter::checkInf()
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
		return (false);
	return (true);
}

bool ScalarConverter::isNumber(const char *ob, const char *null)
{
	if (null != ob && (*null == '\0' || ob[strlen(ob) - 1] == 'f'))
	{
		while (std::isspace(*null))
			++null;
		if (*null == '\0' || ob[strlen(ob) - 1] == 'f')
        return true;
            return false;
	}
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
		print();
	}
	else if (isNumber(ob, null) && (isInt() || isDouble() || isFloat()))
		print();
	else
		throw unknownTypeException();
}

const char* ScalarConverter::unknownTypeException::what() const throw()
{
	return ("[ERROR] Unknown type conversion!");
}
