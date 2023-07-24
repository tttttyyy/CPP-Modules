#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iomanip>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const Form &);
		Form(std::string, const int, const int);
		Form& operator=(const Form &);
		~Form();

		std::string	getName() const;
		bool		getSign() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;

		void		beSigned(const Bureaucrat &);
	private:
		const std::string	m_name;
		bool				m_sign;
		const int			m_gradeSign;
		const int			m_gradeExecute;
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream&, const Form &);

#endif