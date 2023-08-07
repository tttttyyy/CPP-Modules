#include "ScalarConverter.hpp"


void ScalarConverter::convert(char* ob)
{

	char *null = NULL;
	m_literal = std::strtod(ob, &null);
}
// void ScalarConverter::convert(char *ob)
// {
// 	if (!ob)
// 		return ;
// 	char *null = NULL;
// 	char *null = NULL;

// 	m_literal = std::strtod(ob, &null);
// 	// std::cout << m_literal << std::endl;
// 	// std::cout << "char: ";
// 	// toChar(tmp);
// 	// std::cout << "int: ";
// 	// toInt(tmp, ob);


// }