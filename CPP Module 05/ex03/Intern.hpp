#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &);
		Intern& operator=(const Intern &);
		~Intern();

		AForm* makeForm(const std::string &, const std::string &);
		class NameExistenceException : public std::exception
		{
			const char* what(void) const throw();
		};
};

#endif