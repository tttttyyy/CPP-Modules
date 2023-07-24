#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iomanip>
#include <fstream>
#include "Bureaucrat.hpp"


class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const AForm &);
		AForm(std::string, const int, const int);
		AForm& operator=(const AForm &);
		virtual ~AForm();

		std::string		getName() const;
		bool			getSign() const;
		int				getGradeSign() const;
		int				getGradeExecute() const;

		void			beSigned(const Bureaucrat &);
		virtual void	execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
	private:
		const std::string	m_name;
		bool				m_sign;
		const int			m_gradeSign;
		const int			m_gradeExecute;
};

std::ostream& operator<<(std::ostream&, const AForm &);

#endif