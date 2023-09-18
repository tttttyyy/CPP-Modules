#include "RPN.hpp"

RPN::RPN() : m_arg("unknown")
{}

RPN::RPN(const std::string & arg) : m_arg(arg)
{}

RPN::RPN(const RPN &toCopy)
{ *this = toCopy; }

RPN& RPN::operator=(const RPN &toCopy)
{
	if(this != &toCopy)
	{
		m_arg = toCopy.m_arg;
		rpn = toCopy.rpn;
	}
	return(*this);
}

RPN::~RPN() {}

void RPN::calculate()
{
	for(int i = 0; m_arg[i]; i++)
	{
		if (m_arg[i] == ' ')
			continue;
		else if(isdigit(m_arg[i]))
		{
			if (m_arg[i + 1] != ' ')
				throw IncorrectRPNExpression();
			rpn.push(m_arg[i] - 48);
		}
		else if (m_arg[i] == '+' || m_arg[i] == '*' || m_arg[i] == '/' || m_arg[i] == '-')
		{
			double operand1 = rpn.top();
			rpn.pop();
			double operand2 = rpn.top();
			rpn.pop();
			switch(m_arg[i])
			{
				case '+' :
					rpn.push(operand2 + operand1);
					break;
				case '-' :
					rpn.push(operand2 - operand1);
					break;
				case '*' :
					rpn.push(operand2 * operand1);
					break;
				case '/' :
					rpn.push(operand2 / operand1);
					break;
				default :
					throw IncorrectRPNExpression();
			}
		}
		else
			throw IncorrectRPNExpression();
	}
	std::cout << rpn.top() << std::endl; 
    rpn.pop();
}

const char* RPN::IncorrectRPNExpression::what() const throw()
{
	return("\33[1;31m[ERROR] Incorrect RPN Expression !\33[0;m");	
}
