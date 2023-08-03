#include "whatever.hpp"

int main()
{
	std::cout << max<int>(3, 7) << std::endl;
	std::cout << max<double>(3.0, 7.0) << std::endl;
	std::cout << max<char>('g', 'e') << std::endl;

	std::cout << "********************" << std::endl;

	std::cout << min<int>(3, 7) << std::endl;
	std::cout << min<double>(3.0, 7.0) << std::endl;
	std::cout << min<char>('g', 'e') << std::endl;

	//do some tests for swap too
}