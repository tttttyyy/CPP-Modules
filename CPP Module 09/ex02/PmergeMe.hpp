#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe& operator=(const PmergeMe &);
		~PmergeMe();
	private:
		std::vector<int> array;
};

#endif