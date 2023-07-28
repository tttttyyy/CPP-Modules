#include "Form.hpp"

Form::Form() : m_name("noName"), m_sign(false), m_gradeSign(10), m_gradeExecute(10)
{}

Form::Form(std::string name, const int gS, const int gE) : m_name(name), m_sign(false), m_gradeSign(gS), m_gradeExecute(gE)
{
	if (gS < 1 || gE < 1)
		throw GradeTooHighException();
	else if (gS > 150 || gE > 150)
		throw GradeTooLowException();
}

Form::Form(const Form & toCopy) : m_name(toCopy.m_name), m_sign(toCopy.m_sign),
m_gradeSign(toCopy.m_gradeSign), m_gradeExecute(toCopy.m_gradeExecute)
{}

Form& Form::operator=(const Form & toCopy )
{
	if (this != &toCopy)
	{
		m_sign = toCopy.m_sign;
		// const_cast<int&>(m_gradeSign) = other.m_gradeSign;        //  data members are constant
        // const_cast<int&>(m_gradeExecute) = other.m_gradeExecute;  //  that is why reinitializing is not performed 
        // const_cast<std::string&>(m_name) = other.m_name;          //  however providing "solution" tip
	}
	return (*this);
}

Form::~Form() {}

std::string	Form::getName() const { return(m_name); }

bool Form::getSign() const { return(m_sign); }

int Form::getGradeSign() const { return(m_gradeSign); }

int Form::getGradeExecute() const { return(m_gradeExecute); }

const char* Form::GradeTooHighException::what() const throw()
{
	return ("\33[1;31m[ERROR] The grade is too high !\033[0m");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("\33[1;31m[ERROR] The grade is too low !\033[0m");
}

std::ostream& operator<<(std::ostream& os, const Form &output)
{
	os << output.getName() << "\33[1;34m, form info\033[0m" << std::endl;
	os << std::setw(15) << "Sign " << ": ";
	if (output.getSign())
		os << "\33[1;32mPositive\033[0m" << std::endl;
	else
		os << "\33[1;31mNegative\033[0m" << std::endl;
	os << std::setw(15) << "Grade(Sign) " << ": " << output.getGradeSign() << std::endl;
	os << std::setw(15) << "Grade(Execute) " << ": " << output.getGradeExecute() << std::endl;
	return (os);
}

void Form::beSigned(const Bureaucrat & fatty) //taking const reference because
{									  			//it's faster also no need for tmp
	if (fatty.getGrade() > m_gradeSign)
		throw GradeTooLowException();
	m_sign = true;
}