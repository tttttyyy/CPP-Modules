#include "Span.hpp"

int main()
{
	try
	{
		Span numbers(5);

		numbers.addNumber(9);
		numbers.addNumber(6);
		numbers.addNumber(3);
		numbers.addNumber(51);
		// std::cout << numbers.shortestSpan() << std::endl;
		std::cout << numbers.longestSpan() << std::endl;

	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}