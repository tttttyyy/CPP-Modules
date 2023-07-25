#ifndef  SHRUBBERYCREATIONFORM_HPP
#define  SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const & executor) const;
	private:
		std::string m_target;
};

#endif