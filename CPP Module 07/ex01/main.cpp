#include "iter.hpp"
template <typename arg> 
void print(const arg &x)
{
	std::cout << x << std::endl;
}
int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}


// int main()
// {
// 	int arrI[4] = {0, 1, 2, 3};
// 	iter(arrI, 4, &print);

// 	std::cout << "********************" << std::endl;

// 	float arrF[4] = {0.2f, 1.2f, 2.2f, 3.2f};
// 	iter(arrF, 4, &print);

// 	std::cout << "********************" << std::endl;

// 	char arrC[4] = {'a', 'b', 'c', 'd'};
// 	iter(arrC, 4, &print);

// 	std::cout << "********************" << std::endl;

// 	std::string arrS[4] = {"Hi", "Cute", "Cucumber", "!"};
// 	iter(arrS, 4, &print);
// }