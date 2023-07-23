#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception> 


class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string, int);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat& operator=(const Bureaucrat &);
		~Bureaucrat();

		std::string	getName()const;
		int			getGrade()const;
		void		increment();
		void		decrement();
		void		signForm();
	private:
		const std::string	m_name;
		int					m_grade;
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif