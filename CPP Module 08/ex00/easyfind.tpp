#include "easyfind.hpp"

template<typename T>
void easyfind(T container, int data)
{
	typename std::vector<int>::iterator it;
	it = std::find(container.begin(), container.end(), data);
	if (it == container.end())
		throw NoSuchDataMemberException();
	std::cout << "Success!" << std::endl;
}

const char* NoSuchDataMemberException::what() const throw()
{
	return("\33[1;31m[ERROR] No Member With such Data!");
}

