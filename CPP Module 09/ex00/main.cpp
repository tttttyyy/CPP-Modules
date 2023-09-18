#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	// if (argc != 2)
	// {
	// 	std::cerr << "\033[1;31m[ERROR] NO INPUT FILES ARE FOUND!" << std::endl;
	// 	exit(2);
	// }
	try
	{
		for (int i = 1; argv[i]; i++)
		{
			BitcoinExchange btc(argv[i]);
			btc.exchange();

		}
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}