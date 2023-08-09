#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			std::cout << "Program takes 1 argument";
		else
			ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}