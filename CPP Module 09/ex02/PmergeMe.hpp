#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>

#define THRESHOLD 10

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe& operator=(const PmergeMe &);
		~PmergeMe();

		void sort(int argc, char **argv);
		void mergeInsert(int, int);
		void insertion(int, int);
	private:
		std::vector<int> m_vectorSequence;
};

#endif