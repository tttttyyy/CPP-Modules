#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    public:
        Span();
        Span(unsigned int);
        Span(const Span &);
        Span& operator=(const Span &);
        ~Span();

        void    addNumber(int);
        int     shortestSpan();
        int     longestSpan();
        class NoSpaceLeftException : public std::exception
        {
            const char* what() const throw();
        };
        class NoSpanCanBeFoundException : public std::exception
        {
            const char* what() const throw();
        };
    private:
        std::vector<int>	m_arr;
		unsigned int		m_size;
};

#endif