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
		std::cout << numbers.shortestSpan() << std::endl;
		Span copy = numbers;
		copy.addRange(20, 25);
		std::cout << copy.shortestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Span numbers(0);

		numbers.addNumber(9);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Span numbers(30);

		numbers.addNumber(9);
		numbers.addNumber(6);
		numbers.addNumber(3);
		numbers.addNumber(51);
		Span copy = numbers;
		copy.addRange(20, 25);
		std::cout << copy.shortestSpan() << std::endl;
		std::cout << numbers.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}