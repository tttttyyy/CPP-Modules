#include <iostream>

int main()
{
	std::string s("HI THIS IS BRAIN"); // initialize a string
	std::string* stringPTR = &s; // A pointer to the string
	std::string& stringREF = s; //  A reference to the string

	std::cout << "The memory address of the string = " << &s << std::endl;
	std::cout << "The memory address held by pointer = " << stringPTR << std::endl;
	std::cout << "The memory address held by reference = " << &stringREF << std::endl;

	std::cout << "The value of the string = " << s << std::endl;
	std::cout << "The value pointed to by pointer = " << *stringPTR << std::endl;
	std::cout << "The value pointed to by reference = " << stringREF << std::endl;
}