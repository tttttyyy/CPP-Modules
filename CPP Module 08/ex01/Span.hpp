#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
    public:
        Span();
        Span(int);
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
    private:
        int *m_arr;
};

#endif