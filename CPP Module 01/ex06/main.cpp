#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "\033[31m" << "Enter DEBUG, INFO, WARNING or ERROR\n";
        return (1);
	}
	Harl		complainer;
	complainer.complain(argv[1]);
}