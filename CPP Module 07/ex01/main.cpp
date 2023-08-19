#include "iter.hpp"

void add(const int &x)
{
	std::cout << x << std::endl;

}

int main()
{
	int arr[4] = {0, 1, 2, 3};

	iter(arr, 4, &add);
}