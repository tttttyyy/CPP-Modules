#include "ScalarConverter.hpp"

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
	if  (!d && !(d/10))
		std::cout << d << std::endl;
	else if  (!std::strtod(av, 10L) && av.length() > 1)
		std::cout << "impossible" << std::endl;
	// std::cout << d << std::endl;

}
void ScalarConverter::convert(char *ob)
{
	double tmp;
	char *null = NULL;

	tmp = std::strtod(ob, &null);
	std::cout << "char: ";
	toChar(tmp);
	std::cout << "int: ";
	toInt(tmp, ob);


}
