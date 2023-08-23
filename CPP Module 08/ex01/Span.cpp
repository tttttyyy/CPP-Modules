#include "Span.hpp"

Span::Span() : m_size(0) {}

Span::Span(unsigned int size) : m_size(size) {}

Span::Span(const Span &toCopy)
{
	m_size = toCopy.m_size;
	m_arr = toCopy.m_arr;
}

Span& Span::operator=(const Span &toCopy)
{
	if (this != &toCopy)
	{
		m_size = toCopy.m_size;
		m_arr = toCopy.m_arr;
	}
	return(*this);
}

Span::~Span() {}

int Span::shortestSpan()
{
	if (m_arr.size() <= 1)
		throw NoSpanCanBeFoundException();
	int min = INT_MAX;
	std::sort(m_arr.begin(), m_arr.end());
	std::vector<int>::iterator it;
	for (it = m_arr.begin(); it + 1 != m_arr.end(); it++)
		if (min > *(it + 1) - *it)
			min = *(it + 1) - *it;
	return (min);
}

int Span::longestSpan()
{
	if (m_arr.size() <= 1)
		throw NoSpanCanBeFoundException();
	std::sort(m_arr.begin(), m_arr.end());
	return(*(m_arr.end() - 1) - *(m_arr.begin()));
}

void    Span::addNumber(int num)
{
	if (m_size <= m_arr.size())
		throw NoSpaceLeftException();
	m_arr.push_back(num);
}

const char* Span::NoSpaceLeftException::what() const throw()
{
	return("\33[1;31m[ERROR] No Space Left !");
}

const char* Span::NoSpanCanBeFoundException::what() const throw()
{
	return("\33[1;31m[ERROR] No Span Can Be Found !");
}