#include "PhoneBook.hpp"

int main()
{
	PhoneBook PB;
	std::string tmp;
	while (true)
	{
		std::cout << "\033[0m" << "ENTER THE COMMAND: ";
		getline(std::cin, tmp);
		if (std::cin.eof())
			return (1);
		if (tmp == "ADD")
			PB.ADD();
		else if (tmp == "SEARCH")
			PB.SEARCH();
		else if (tmp == "EXIT")
			break ;
		else
			std::cerr << "\033[31m" << "[ERROR] INCORRECT COMMAND" << std::endl;
	}
}