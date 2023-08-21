#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

//creating 2 templates
//1 for the actual argument can be array of anything
//the other one for length can be int double size_t etc
// template <typename arg, typename len> void iter(arg *p, len l, void (*f)(const arg &))
// {
// 	for (len i = 0; i < l; i++)
// 		f(p[i]);
// }

// template <typename arg> void iter(arg *p, int l, void (*f)(const arg &))
// {
// 	for (int i = 0; i < l; i++)
// 		f(p[i]);
// }


template <typename len>
void iter(len *p, int l, void (*f)(const len &))
{
	for (int i = 0; i < l; i++)
		f(p[i]);
}

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

// template< typename T >
// void print( const T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

#endif