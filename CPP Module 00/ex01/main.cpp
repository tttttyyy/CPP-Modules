#include "PhoneBook.hpp"

int main()
{
	PhoneBook PB;
	std::string tmp;
	while (true)
	{
		std::cout << "ENTER THE COMMAND: ";
		getline(std::cin, tmp);
		if (std::cin.eof())
			return (1);
		if (tmp == "ADD")
			PB.ADD();
		else if (tmp == "SEARCH")
			PB.SEARCH();
		else if (tmp == "EXIT")
			PB.EXIT();
		else
			std::cerr << "[ERROR] INCORRECT COMMAND" << std::endl;
	}
}