#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}
std::string Contact::GetFName()
{
	return (m_first_name);
}
std::string Contact::GetLName()
{
	return (m_last_name);
}
std::string Contact::GetNName()
{
	return (m_nickname);
}
std::string Contact::GetPNum()
{
	return (m_phone_number);
}
std::string Contact::GetDSec()
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
