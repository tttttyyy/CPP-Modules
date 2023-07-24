#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCB", 145, 135), m_target("noTarget")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCB", 145, 135), m_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & toCopy)
{
	m_target = toCopy.m_target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & toCopy )
{
	if (this != &toCopy)
		m_target = toCopy.m_target;
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getSign() || executor.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();
	std::ofstream outfile(m_target + "_shrubbery");
	outfile << " _" << std::endl;
	outfile << "| | " << std::endl;
	outfile << "| |_ _ __ ___  ___ " << std::endl;
	outfile << "| __| '__/ _ \\/ _ \\/" << std::endl;
	outfile << "| |_| | |  __/  __/" << std::endl;
	outfile << " \\__|_|  \\___|\\___|" << std::endl;
}