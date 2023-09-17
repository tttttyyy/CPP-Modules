#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "\033[1;31m[ERROR] NO INPUT FILES ARE FOUND!" << std::endl;
		exit(2);
	}
	try
	{
		RPN expression(argv[1]);
		expression.calculate();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}