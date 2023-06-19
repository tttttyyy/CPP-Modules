#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size = 0;
}
PhoneBook::~PhoneBook(){}

int	check_fon(std::string str)
{
	unsigned int i;

	i = 0;
	if (str[i] == '+')
		++i;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (2);
		++i;
	}
	return (0);
}

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
	while (std::cin.eof() || tmp.empty() || check_fon(tmp))
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

std::string truncate(std::string str, size_t width, bool show_ellipsis=true)
{
    if (str.length() > width)
	{
        if (show_ellipsis)
            return str.substr(0, width) + '.';
        else
		return str.substr(0, width);
	}
    return str;
}

void	PhoneBook::SEARCH(void)
{
	int	i;
	std::string	tmp;
	char *index;
	if (size == 0)
		return;
	for (int j = 0; j < size; j++)
	{
		
		std::cout << "\033[0m" << j << '|'<< std::setw(10) << truncate(contact[j].GetFName(), 9, 1);
		std::cout << '|' << std::setw(10) << truncate(contact[j].GetLName(), 9, 1);
		std::cout << '|' << std::setw(10) << truncate(contact[j].GetNName(), 9, 1) << std::endl;
	}
	std::cout << "\033[0m" << "ENTER THE INDEX: ";
	getline(std::cin, tmp);
	if (std::cin.eof())
		return ;
	std::strtol(tmp.c_str(), &index, 10);
	if (*index != '\0')
		std::cout << "\033[31m" << "[ERROR] MUST TYPE ONLY DIGITS\n";
	else
	{
		i = std::atoi(tmp.c_str());
		if (i < 0 || i > 7)
			std::cout << "\033[31m" << "[ERROR] INCORRECT INDEX\n";
		if (i <= size)
		{
		std::cout << "\033[0m" << std::setw(12) << "INDEX: " << i << std::endl;
		std::cout << std::setw(12) << "FIRST NAME: " << contact[i].GetFName() << std::endl;
		std::cout << std::setw(12) << "LAST NAME: " << contact[i].GetLName() << std::endl;
		std::cout << std::setw(12) << "NICKNAME: " << contact[i].GetNName() << std::endl;
		}
		else
			std::cout << "\033[31m" << "[ERROR] NO VALLUE FOUND\n";
	}
}