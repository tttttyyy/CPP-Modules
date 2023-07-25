#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(const PresidentialPardonForm &);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &);
		~PresidentialPardonForm();

		void	execute(Bureaucrat const & executor) const;
	private:
		std::string m_target;
};


#endif