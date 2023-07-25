#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RBF", 72, 45), m_target("noTarget") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RBF", 72, 45), m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & toCopy) : m_target(toCopy.m_target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &toCopy)
{
	if (this != &toCopy)
		m_target = toCopy.m_target;
	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();
	if (!getSign())
		throw AForm::SignException();
	std::cout << m_target << "\33[1;36mMakes some drilling noises\033[0m" << std::endl;
	if (std::rand() % 2)
		std::cout << m_target << "\33[1;32m has been robotomized successfully\033[0m" << std::endl;
	else
		std::cout << m_target << "\33[1;31m's robotomy has been failed\033[0m" << std::endl;
}