#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "\033[1;31m[ERROR] SHOULD INPUT ARRAY OF POSITIVE INTEGERS!" << std::endl;
		exit(2);
	}
	for(int i = 0; i < argc; ++i)
}