#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	int		index;
	int		size;
	Contact contact[8];
	public:
		PhoneBook();
		~PhoneBook();
	

	void	ADD(void);
	void	SEARCH(void);
	void	EXIT(void);
};
#endif
