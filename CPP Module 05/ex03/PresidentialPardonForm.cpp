#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF", 25, 5), m_target("noTarget") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 25, 5), m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & toCopy) : m_target(toCopy.m_target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm & toCopy )
{
	if (this != &toCopy)
		m_target = toCopy.m_target;
	return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();
	if (!getSign())
		throw AForm::SignException();
	std::cout << m_target << "\033[1;33m has been pardoned by Zaphod Beeblebrox.\033[0m" << std::endl;
}