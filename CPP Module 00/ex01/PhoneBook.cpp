#include "PhoneBook.hpp"
PhoneBook::PhoneBook(){}
PhoneBook::~PhoneBook(){}

void	PhoneBook::ADD(void)
{
	std::string	tmp;
	if (index == 8)
		index = 0;
	std::cout << "ENTER FIRST NAME: " << std::endl;
	getline(std::cin, tmp);
	contact[index].SetFName(tmp);
	std::cout << "ENTER LAST NAME: " << std::endl;
	getline(std::cin, tmp);
	contact[index].SetLName(tmp);
	std::cout << "ENTER NICKNAME: " << std::endl;
	getline(std::cin, tmp);
	contact[index].SetNName(tmp);
	std::cout << "ENTER PHONE NUMBER: " << std::endl;
	getline(std::cin, tmp);
	contact[index].SetPNum(tmp);
	std::cout << "ENTER DARKEST SECRET: " << std::endl;
	getline(std::cin, tmp);
	contact[index].SetDSec(tmp);
	// if (!tmp)
	// 	str::cout << "Must type the first name!" << std::endl;
}

void	PhoneBook::SEARCH(void)
{
	int	i;
	std::string	tmp;
	std::cout << "ENTER THE INDEX: " << std::endl;
	getline(std::cin, tmp);
	i = std::atoi((char *)tmp);
	std::cout << i << '|' << contact[i].GetFName() << '|' << contact[i].GetLName() << '|' << contact[i].GetNName() << std::endl;
		
}

void	PhoneBook::EXIT(void)
{
	exit(0);
}