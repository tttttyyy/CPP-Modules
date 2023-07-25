#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("noName"), m_grade(10) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & toCopy) : m_name(toCopy.m_name), m_grade(toCopy.m_grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat & toCopy)
{
	if (this != &toCopy)
	{
		// const_cast<std::string&>(m_name) = toCopy.m_name; //as it is constant no need to reassign
		m_grade = toCopy.m_grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName()const { return(m_name); }

int Bureaucrat::getGrade()const { return(m_grade); }

void Bureaucrat::increment()
{
	if (m_grade == 1)
		throw GradeTooHighException();
	--m_grade;
}

void Bureaucrat::decrement()
{
	if (m_grade == 150)
		throw GradeTooLowException();
	++m_grade;

}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& output)
{
    os << output.getName() << ", bureaucrat grade " << output.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\33[1;31m[ERROR] The number is too high !\033[0m");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\33[1;31m[ERROR] The number is too low !\033[0m");
}