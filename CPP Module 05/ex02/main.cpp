#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat	def;
		Bureaucrat	par("cute", 142);

		// AForm		paper;
		// AForm		doc("Document", 140, 10);

		std::cout << def << std::endl;
		std::cout << par << std::endl;
		// std::cout << doc << std::endl;

		def.increment();
		par.decrement();
		// doc.beSigned(par);
		// par.signForm(doc);

		std::cout << def << std::endl;
		std::cout << par << std::endl;
		// std::cout << doc << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}