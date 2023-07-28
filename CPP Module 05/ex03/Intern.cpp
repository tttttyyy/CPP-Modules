#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern & toCopy) { *this = toCopy; }

Intern& Intern::operator=(const Intern &toCopy)
{
	if (this != &toCopy)
	{
		*this = toCopy;
	}
	return(*this);
}

Intern::~Intern() {}

const char* Intern::NameExistenceException::what(void) const throw()
{
	return ("\33[1;31m[ERROR] Form name is incorrect !\033[0m");
}

AForm* Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	std::string names[3] = {"shrubbery", "robotomy", "presidental"};
	int i = -1;
	while (formName != names[++i])
	;
	switch (i)
	{
		case 0:
		{
			std::cout << "Intern creates a ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		}
		case 1:
		{
			std::cout << "Intern creates a RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(formTarget));
		}
		case 2:
		{
			std::cout << "Intern creates a PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(formTarget));
		}
		default:
			throw NameExistenceException();
	}
}
