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
		template<typename T>
        void    addRange(const T begin, const T end)
		{
			if (begin - end > (T)m_size)
				throw NoSpaceLeftException();
			m_arr.insert(m_arr.end(), begin, end);
			// std::vector<int>::iterator it;
			// for (it = m_arr.begin(); it != m_arr.end(); it++)
			// 	std::cout << *it << std::endl;
		}
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