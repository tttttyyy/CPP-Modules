#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

#define THRESHOLD 10

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe& operator=(const PmergeMe &);
		~PmergeMe();

		void sort(int, char **);
		template<typename Contain>
		void mergeInsert(Contain &, int, int);
		template<typename Contain>
		void insertion(Contain &, int, int);
		template<typename Contain>
		void merge(Contain &, int, int, int);

		template<typename Contain>
		void parseSequence(Contain &, int, char **);

	private:
		std::vector<int> m_vectorSequence;
		std::deque<int> m_dequeSequence;
};

#endif