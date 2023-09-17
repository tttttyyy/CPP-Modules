#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "\033[1;31m[ERROR] NO INPUT FILES ARE FOUND!" << std::endl;
		exit(2);
	}
	try
	{
		BitcoinExchange btc(argv[1]);
		btc.exchange();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}