#include "whatever.hpp"
#include <cmath>
#include<limits>
// int main()
// {
// 	std::cout << max<int>(3, 7) << std::endl;
// 	std::cout << max<double>(3.0, 7.0) << std::endl;
// 	std::cout << max<char>('g', 'e') << std::endl;

// 	std::cout << "********************" << std::endl;

// 	std::cout << min<int>(3, 7) << std::endl;
// 	std::cout << min<double>(3.0, 7.0) << std::endl;
// 	std::cout << min<char>('g', 'e') << std::endl;

// 	std::cout << "********************" << std::endl;


// 	int a = 2;
// 	int b = 3;

// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

// 	std::cout << "********************" << std::endl;

// 	std::string c = "chaine1";
// 	std::string d = "chaine2";

// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

// 	std::cout << "********************" << std::endl;

// 	double e = std::numeric_limits<double>::infinity();
// 	double f = nan("1");
// 	std::cout << "e = " << e << ", f = " << f << std::endl;
// 	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
// 	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
// }

int main(void)
{
Awesome a(2), b(4);
swap(a, b);
std::cout << a << " " << b << std::endl;
std::cout << max(a, b) << std::endl;
std::cout << min(a, b) << std::endl;
return (0);
}