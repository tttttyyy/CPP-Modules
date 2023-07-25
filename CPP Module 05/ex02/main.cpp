#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat	par("cute", 1);
		ShrubberyCreationForm scf("cucumber");
		RobotomyRequestForm rrf("robot");
		PresidentialPardonForm ppf("sugar");
		std::cout << par << std::endl;

		par.decrement();
		par.signForm(scf);
		par.signForm(rrf);
		par.signForm(ppf);
		// std::cout << "kuku" << std::endl;
		scf.execute(par);
		rrf.execute(par);
		ppf.execute(par);

		std::cout << par << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}