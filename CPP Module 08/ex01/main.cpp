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
		// numbers.addRange(20, 25);
		// Span copy = numbers;
		// std::vector<int>::iterator m_copyb = copy.m_arr.begin();
		// std::vector<int>::iterator m_copye = m_copyb + 2;
		// numbers.addRange(m_copyb, m_copye);
		std::cout << numbers.shortestSpan() << std::endl;
		// std::cout << numbers.longestSpan() << std::endl;

	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}