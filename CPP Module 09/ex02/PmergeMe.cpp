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
	}
	std::cout << "Before: ";
	if(argc > 6)
	{
		for (int i = 1; i < 5; i++)
			std::cout << argv[i] << ' ';
		std::cout << "[...]" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << ' ';
		std::cout << std::endl;
	}
	struct timeval time;
	double vStart = gettime(&time);
	parseSequence(m_vectorSequence, argc, argv);
	mergeInsert(m_vectorSequence, 0, m_vectorSequence.size() - 1);
	double vEnd = gettime(&time);
	
	double dStart = gettime(&time);
	parseSequence(m_dequeSequence, argc, argv);
	mergeInsert(m_dequeSequence, 0, m_dequeSequence.size() - 1);
	double dEnd = gettime(&time);


	std::cout << "After: ";
	if(m_vectorSequence.size() > 5)
	{
		std::vector<int>::iterator it;
		for (it = m_vectorSequence.begin(); it < m_vectorSequence.begin() + 5 - 1; it++)
			std::cout << *it << ' ';
		std::cout << "[...]" << std::endl;
	}
	else
	{
		std::vector<int>::iterator it;
		for (it = m_vectorSequence.begin(); it != m_vectorSequence.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
	}
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::[..] : " << (vEnd - vStart) / 1000 << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::[..] : " << (dEnd - dStart) / 1000 << std::endl;
}

template<typename Contain>
void PmergeMe::parseSequence(Contain &T, int argc, char **argv)
{
	for(int i = 1; i < argc; ++i)
	{
		int num = atoi(argv[i]);
		if (num > 0)
			T.push_back(num);
		else
		{
			std::cerr << "\033[1;31m[ERROR] ONLY POSITIVE INTEGERS!" << std::endl;
			exit(2);
		}
	}
}

template<typename Contain>
void PmergeMe::mergeInsert(Contain &T, int left, int right)
{
	if(left < right)
	{
		if(right - left <= THRESHOLD)
			insertion(T, left, right);
		else
		{
			int mid = left + (right - left) / 2;
			mergeInsert(T, mid + 1, right);
			mergeInsert(T, left, mid);
			merge(T, left, mid, right);
		}
	}
}

template<typename Contain>
void PmergeMe::insertion(Contain &T, int left, int right)
{
	int  j;
    for (int i = left + 1; i <= right; i++)
	{
        int key = T[i];
        j = i - 1;
        // Move elements of m_vectorSequence[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && T[j] > key)
		{
            T[j + 1] = T[j];
            j--;
        }
        T[j + 1] = key;
    }
}

template<typename Contain>
void PmergeMe::merge(Contain &T,int left, int mid, int right)
{
	int const size_sa1 = mid - left + 1;
	int const size_sa2 = right- mid;

	std::vector<int> sa1(size_sa1);
	std::vector<int> sa2(size_sa2);
	for(int i = 0; i < size_sa1; i++)
		sa1[i] = T[left + i];
	for(int i = 0; i < size_sa2; i++)
		sa2[i] = T[mid + 1+ i];

	int index_sa1 = 0, index_sa2 = 0;
	int indexMergedArray = left;
	while(index_sa1 < size_sa1 && index_sa2 < size_sa2)
	{
		if(sa1[index_sa1] <= sa2[index_sa2])
		{
			T[indexMergedArray] = sa1[index_sa1];
			index_sa1++;
		}
		else
		{
			T[indexMergedArray] = sa2[index_sa2];
			index_sa2++;
		}
		indexMergedArray++;
	}
	while(index_sa1 < size_sa1)
	{
		T[indexMergedArray] = sa1[index_sa1];
		index_sa1++;
		indexMergedArray++;
	}
	while(index_sa2 < size_sa2)
	{
		T[indexMergedArray] = sa2[index_sa2];
		index_sa2++;
		indexMergedArray++;
	}
}

double	PmergeMe::gettime(struct timeval *time)
{
	gettimeofday(time, NULL);
	return ((time->tv_sec * 1000000) + (time->tv_usec));
}