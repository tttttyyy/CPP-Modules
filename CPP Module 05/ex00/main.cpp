#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	def;
		Bureaucrat	par("cute", 150);
		std::cout << def << std::endl;
		std::cout << par << std::endl;
		def.increment();
		par.decrement();
		std::cout << def << std::endl;
		std::cout << par << std::endl;
	}
	catch(std::exception &e)
	{  
		std::cout << e.what() << std::endl;
	}
}