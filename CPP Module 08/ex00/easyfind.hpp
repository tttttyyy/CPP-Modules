#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <iostream>

template<typename T>
void	easyfind(T, int);

class NoSuchDataMemberException : public std::exception
{
	const char* what() const throw();
};
#include "easyfind.tpp"
#endif