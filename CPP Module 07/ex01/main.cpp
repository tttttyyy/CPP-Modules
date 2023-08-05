#include "iter.hpp"

int add(int &x)
{
	return(x++);
}

int main()
{
	int arr[4] = {0, 1, 2, 3};

	iter(arr, 4, &add);
	for(int i = 0; i < 4; i++)
		std::cout << arr[i] << std::endl;
}