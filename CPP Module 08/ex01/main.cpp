#include "Span.hpp"

int main()
{
	try
	{
		Span numbers(1);

		numbers.addNumber(5);
		numbers.addNumber(5);

	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}