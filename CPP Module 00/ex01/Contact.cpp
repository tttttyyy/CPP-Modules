#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}
std::string Contact::GetFName() const
{
	return (m_first_name);
}
std::string Contact::GetLName() const
{
	return (m_last_name);
}
std::string Contact::GetNName() const
{
	return (m_nickname);
}
std::string Contact::GetPNum() const
{
	return (m_phone_number);
}
std::string Contact::GetDSec() const
{
	return (m_darkest_secret);
}
void Contact::SetFName(std::string fname)
{
	m_first_name = fname;	
}
void Contact::SetLName(std::string lname)
{
	m_last_name = lname;	
}
void Contact::SetNName(std::string nname)
{
	m_nickname = nname;	
}
void Contact::SetPNum(std::string number)
{
	m_phone_number = number;	
}
void Contact::SetDSec(std::string secret)
{
	m_darkest_secret = secret;	
}
