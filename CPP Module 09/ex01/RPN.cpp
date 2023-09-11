#include "RPN.hpp"

RPN::RPN() : m_arg("unknown")
{}

RPN::RPN(const std::string & arg) : m_arg(arg)
{}

RPN::RPN(const RPN &toCopy)
{ (void)toCopy; }

RPN& RPN::operator=(const RPN &toCopy)
{ (void)toCopy; return(*this); }

RPN::~RPN()
{}

void RPN::calculate()
{
	std::istringstream iss(m_arg);
	std::string token;

	while(iss >> token)
	{
		if(isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
			rpn.push(atoi(token.c_str()));
		else
		{
			int operand1 = rpn.top();
			rpn.pop();
			int operand2 = rpn.top();
			rpn.pop();
			switch(token[0])
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

	}
     std::cout << rpn.top() <<" ";
    rpn.pop();
}

const char* RPN::IncorrectRPNExpression::what() const throw()
{
	return("\33[1;31m[ERROR] Incorrect RPN Expression !\33[0;m");	
}
