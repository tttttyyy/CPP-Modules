#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size = 0;
}
PhoneBook::~PhoneBook(){}

void	PhoneBook::ADD(void)
{
	std::string	tmp;
	if (size < 8)
		++size;
	if (index == 8)
		index = 0;
	std::cout << "ENTER FIRST NAME: ";
	getline(std::cin, tmp);
	while (std::cin.eof() || tmp.empty())
	{
		std::cout << "MUST ENTER FIRST NAME: ";
		getline(std::cin, tmp);
	}
	contact[index].SetFName(tmp);
	std::cout << "ENTER LAST NAME: ";
	getline(std::cin, tmp);
	while (std::cin.eof() || tmp.empty())
	{
		std::cout << "MUST ENTER LAST NAME: ";
		getline(std::cin, tmp);
	}
	contact[index].SetLName(tmp);
	std::cout << "ENTER NICKNAME: ";
	getline(std::cin, tmp);
	while (std::cin.eof() || tmp.empty())
	{
		std::cout << "MUST ENTER NICKNAME: ";
		getline(std::cin, tmp);
	}
	contact[index].SetNName(tmp);
	std::cout << "ENTER PHONE NUMBER: ";
	getline(std::cin, tmp);
	while (std::cin.eof() || tmp.empty())
	{
		std::cout << "MUST ENTER PHONE NUMBER: ";
		getline(std::cin, tmp);
	}
	contact[index].SetPNum(tmp);
	std::cout << "ENTER DARKEST SECRET: ";
	getline(std::cin, tmp);
	while (std::cin.eof() || tmp.empty())
	{
		std::cout << "MUST ENTER DARKEST SECRET: ";
		getline(std::cin, tmp);
	}
	contact[index].SetDSec(tmp);
	++index;
}

void	PhoneBook::SEARCH(void)
{
	int	i;
	std::string	tmp;
	if (size == 0)
		return;
	for (int j = 0; j < size; j++)
	{
		std::cout << j << '|'<< std::setw(10) << contact[j].GetFName() << '|' << std::setw(10) << contact[j].GetLName() << '|' << std::setw(10) << contact[j].GetNName() << std::endl;
	}
	std::cout << "ENTER THE INDEX: ";
	getline(std::cin, tmp);
	i = std::atoi(tmp.c_str());  // std::stringstream
	if (i < 0 || i > 7)
		std::cout << "[ERROR] INCORRECT INDEX";
	if (i <= size)
	{
	std::cout << std::setw(12) << "INDEX: " << i << std::endl;
	std::cout << std::setw(12) << "FIRST NAME: " << contact[i].GetFName() << std::endl;
	std::cout << std::setw(12) << "LAST NAME: " << contact[i].GetLName() << std::endl;
	std::cout << std::setw(12) << "NICKNAME: " << contact[i].GetNName() << std::endl;
	}
}

void	PhoneBook::EXIT(void)
{
	exit(0);
}