#include "Base.hpp"

Base::~Base() {}

Base * generate(void)
{
	std::srand(time(0));
	int index = std::rand() % 3;
	if (index == 0)
		return(new A());
	else if (index == 1)
		return(new B());
	return (new C());
}

void identify(Base* p)
{
	A *a;
	a = dynamic_cast<A*>(p);
	if (a)
		std::cout << "Type of the object is A" << std::endl;
	B *b;
	b = dynamic_cast<B*>(p);
	if (b)
		std::cout << "Type of the object is B" << std::endl;
	C *c;
	c = dynamic_cast<C*>(p);
	if (c)
		std::cout << "Type of the object is C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type of the object is A" << std::endl;
	}
	catch(const std::bad_cast & e) {(void)e;}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type of the object is B" << std::endl;
	}
	catch(const std::bad_cast & e) {(void)e;}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type of the object is C" << std::endl;
	}
	catch(const std::bad_cast & e) {(void)e;}
}

