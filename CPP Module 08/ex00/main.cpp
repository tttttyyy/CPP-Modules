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
	
}