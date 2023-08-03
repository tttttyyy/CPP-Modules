#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "iostream"

template <typename what> void swap(what &a, what &b)
{
	what c = a;
	a = b;
	b = c;
}

template <typename what> what min(const what &a, const what &b)
{
	return ((a >= b) ? b : a);
}

template <typename what> what max(const what &a, const what &b)
{
	return ((a <= b) ? b : a);
}

#endif