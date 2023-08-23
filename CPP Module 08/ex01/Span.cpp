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
