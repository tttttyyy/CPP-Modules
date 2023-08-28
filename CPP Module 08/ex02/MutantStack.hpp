#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() : std::stack<T, Container>() {}
		MutantStack<T, Container>(const MutantStack<T, Container> &toCopy)
		{ *this = toCopy; }
		MutantStack<T, Container>& operator=(const MutantStack<T, Container> &toCopy)
		{
			if(this != &toCopy)
				this->c = toCopy.c;
			return(*this);
		}
		~MutantStack<T, Container>() {}


		typedef typename Container::iterator iterator;
		typedef typename Container::iterator const_iterator;

		iterator begin()
		{
			return(this->c.begin());
		}

		iterator end()
		{
			return(this->c.end());
		}

		const_iterator begin() const
		{
			return(this->c.begin());
		}

		const_iterator end() const
		{
			return(this->c.end());
		}
};

#endif