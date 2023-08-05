#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

//creating 2 templates
//1 for the actual argument can be array of anything
//the other one for length can be int double size_t etc
template <typename arg, typename len> void iter(arg *p, len l, arg (*f)( arg &))
{
	for (len i = 0; i < l; i++)
		f(p[i]);
}


#endif