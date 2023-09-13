#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &toCopy)
{ (void)toCopy; }

PmergeMe& PmergeMe::operator=(const PmergeMe &toCopy)
{ (void)toCopy; return(*this); }

PmergeMe::~PmergeMe()
{}

void PmergeMe::sort(int argc, char **argv)
{
	for(int i = 1; i < argc; ++i)
	{
		for (int l = 0; argv[i][l]; l++)
		{
			if(!isdigit(argv[i][l]))
			{
				std::cerr << "\033[1;31m[ERROR] ONLY DIGITS!" << std::endl;
				exit(2);
			}
		}
		int num = atoi(argv[i]);
		if (num > 0)
			m_vectorSequence.push_back(num);
		else
		{
			std::cerr << "\033[1;31m[ERROR] ONLY POSITIVE INTEGERS!" << std::endl;
			exit(2);
		}
	}
	mergeInsert(0, m_vectorSequence.size() - 1);
	std::vector<int>::iterator it = m_vectorSequence.begin();
	for (; it != m_vectorSequence.end(); it++)
		std::cout << *it << std::endl;

}

void PmergeMe::mergeInsert(int left, int right)
{
	if(left < right)
	{
		if(right - left <= THRESHOLD)
			insertion(left, right);
		else
		{
			int mid = left + (right - left) / 2;
			mergeInsert(mid + 1, right);
			mergeInsert(left, mid);
			// merge(left, mid, right);
		}
	}
}

void PmergeMe::insertion(int left, int right)
{
	int  j;
    for (int i = left + 1; i < right; i++)
	{
        int key = m_vectorSequence[i];
        j = i - 1;
        // Move elements of m_vectorSequence[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && m_vectorSequence[j] > key) {
            m_vectorSequence[j + 1] = m_vectorSequence[j];
            j = j - 1;
        }
        m_vectorSequence[j + 1] = key;
    }
}
