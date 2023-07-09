#include "Point.hpp"

int main( void )
{
 	Point p1(0, 0), p2(0, 10), p3(10, 0);
    Point p(2, 2);
    if (bsp(p1, p2, p3, p))
        std::cout << "Point is inside triangle!\n";
    else
        std::cout << "Point isn't inside triangle!\n";
	return 0;
}