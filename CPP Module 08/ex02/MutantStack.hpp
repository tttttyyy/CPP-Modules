#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <class T, class Container = deque<T> >
class MutantStack : public std::stack<T, constainer>
{
	MutantStack();	
	MutantStack(Const Mutantstack &);
	MutantStack& operator=(Const Mutantstack &);
	~MutantStack();

	typename Container::iterator it;

};

#endif