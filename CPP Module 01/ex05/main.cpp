#include "Harl.hpp"

int main()
{
	Harl		complainer;
	std::string	line;
	while (true)
	{
		std::cout << "ENTER THE MODE: " ;
		getline(std::cin, line);
		if (line.compare("EXIT") == 0 || std::cin.eof())
			return (1);
		complainer.complain(line);
	}
}