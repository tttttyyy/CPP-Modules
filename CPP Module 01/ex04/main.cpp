#include "replace.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "\033[31m"<<"❌ [ERROR] INCORRECT NUMBER OF ARGUMENTS !" << "\033[30m" << std::endl;
		return (0);
	}
	Replace arg(argv[1], argv[2], argv[3]);
	arg.replaceStrings();
	system("leaks replace_cover");
}