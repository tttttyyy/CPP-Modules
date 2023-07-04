#include "Fixed.hpp"

int main( void )
{
	Fixed a(45);
	Fixed c(4.2f);
	Fixed const b( Fixed( 5.05f ));
	// if (a <= c)
	// 	std::cout << "true\n";
	// else
	// 	std::cout << "false\n";
		std::cout << Fixed::min(a, c);
	return 0;
}