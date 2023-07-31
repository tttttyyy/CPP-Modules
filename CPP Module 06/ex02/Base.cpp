#include "Base.hpp"

Base * generate(void)
{
	void	(*objectPtr[3]) () = {&A, &B, &C};
	int index = std::rand % 3;
	*objectPtr[index]();
}
void identify(Base* p);
void identify(Base& p);


// std::srand(time(0));