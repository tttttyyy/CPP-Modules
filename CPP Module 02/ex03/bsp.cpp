#include "Point.hpp"

Fixed area(Point const p1, Point const p2, Point const p3)
{
	Fixed res = ((p1.getX()*(p2.getY() - p3.getY())) +
            p2.getX()*(p3.getY() - p1.getY()) +
            p3.getX()*(p1.getY() - p2.getY()))
            /2;
	return (res < 0 ? res * -1 : res);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed t1, t2, t3, find;
	t1 = area(a, b, point);
	t2 = area(a, point, c);
	t3 = area(point, b, c);
	find = area(a, b, c);
	if (find >= t1 + t2 + t3 && t1 != 0 && t2 != 0 && t3 != 0 )
        return (true);
    return (false);
}