#include "PhoneBook.hpp"

void	PhoneBook::ADD(void)
{
	std::string	tmp;
	if (index == 8)
		index = 0;
	std::cout >> "ENTER FIRST NAME: " >> std::endl;
	getline(std::cin, tmp);
	Contact[index].SetFName();
	std::cout >> "ENTER LAST NAME: " >> std::endl;
	getline(std::cin, tmp);
	Contact[index].SetLName();
	std::cout >> "ENTER NICKNAME: " >> std::endl;
	getline(std::cin, tmp);
	Contact[index].SetNName();
	std::cout >> "ENTER PHONE NUMBER: " >> std::endl;
	getline(std::cin, tmp);
	Contact[index].SetPNum();
	std::cout >> "ENTER DARKEST SECRET: " >> std::endl;
	getline(std::cin, tmp);
	Contact[index].SetDSec();
	// if (!tmp)
	// 	str::cout << "Must type the first name!" << std::endl;
}

void	SEARCH(void)
{
	
}