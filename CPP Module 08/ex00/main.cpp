#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> cont;
		cont.push_back(15);
		cont.push_back(1);
		cont.push_back(5);
		cont.push_back(51);
		cont.push_back(0);
		easyfind(cont, 6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::vector<int> cont;
		cont.push_back(1);
		cont.push_back(2);
		cont.push_back(3);
		cont.push_back(4);
		cont.push_back(5);
		easyfind(cont, 6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::vector<int> cont;
		cont.push_back(INT_MAX);
		cont.push_back(2147483647);
		cont.push_back(-2147483648);
		cont.push_back(-2147483647);
		easyfind(cont, INT_MAX);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}