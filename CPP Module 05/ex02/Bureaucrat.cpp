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
		// m_name = toCopy.m_name;
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

void Bureaucrat::signForm(AForm & f) //taking const reference because
{										  //it's faster also no need for tmp
	try
	{
		f.beSigned(*this);
		std::cout << m_name << "\33[1;32m signed " << f.getName() << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << m_name << "\33[1;31m couldn’t sign \033[0m" << f.getName()
		<< "\33[1;31m because " << e.what() << "\033[0m" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& output)
{
    os << output.getName() << "\33[1;34m, bureaucrat grade " << output.getGrade() << "\033[0m";
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

void Bureaucrat::executeForm(AForm const & aform)
{
	try
	{
		aform.execute(*this);
		std::cout << m_name << " executed " << aform.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << m_name << "\33[1;31m failed \033[0m" << aform.getName()
		<< "\33[1;31m because " << e.what() << "\033[0m" << std::endl;
	}
}