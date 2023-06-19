#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string	m_phone_number;
	std::string m_darkest_secret;
	public:
		Contact();
		~Contact();
		std::string GetFName() const;
		std::string GetLName() const;
		std::string GetNName() const;
		std::string GetPNum() const;
		std::string GetDSec() const;
		void SetFName(std::string);
		void SetLName(std::string);
		void SetNName(std::string);
		void SetPNum(std::string);
		void SetDSec(std::string);
};

#endif