#include "MutantStack.hpp"

int test1()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return(0);
}

int test2()
{
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(1);
	mstack.push(1);
	mstack.push(1);
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		*it *= 2;
	}
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
	return(0);
}

int test3()
{
	MutantStack<int> mstack;
	mstack.push(0);
	for (int i  = 0; i < 10; ++i)
		mstack.push(1);
	for (MutantStack<int>::iterator it = mstack.begin() + 2; it != mstack.end(); ++it)
	{
		*it = *(it - 2) + *(it - 1);
	}
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
	return(0);
}

int test4()
{
	MutantStack<float> fstack;

	fstack.push(1.f);
	fstack.push(42.42f);
	fstack.push(10.06f);
	fstack.push(-0.01f);
	for (MutantStack<float>::const_iterator it = fstack.begin(); it != fstack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
	MutantStack<float> copyStack = fstack;
	MutantStack<float>::const_iterator it = fstack.end();
	MutantStack<float>::const_iterator copy_it = copyStack.end();
	if (*it == *copy_it)
		std::cout << "\033[1;32mSame end iterator values!\033[0m" << std::endl;
	else
		std::cout << "\033[1;31m[ERROR] FAIL!\033[0m" << std::endl;
	return(0);
}

int test(int(*test)(), std::string testName)
{
	std::cout << "\033[1;32m" << testName << " started \033[0m" << std::endl;
	test();
	std::cout << "\033[1;31m" << testName << " ended \033[0m" << std::endl;
	std::cout << "\033[1;35mPress enter to continue\033[0m" << std::endl;
	std::cin.get();
	system("clear");
	return 0;
}

int main()
{
	std::string testNames[4] = {
		"test1",
		"test2",
		"test3",
		"test4"
	};
	int (*tests[4])() = {
		test1,
		test2,
		test3,
		test4
	};
	for (int i = 0; i < 4; i++)
		test(tests[i], testNames[i]);
	return 0;
}