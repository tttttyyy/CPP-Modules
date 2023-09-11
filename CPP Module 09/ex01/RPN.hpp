#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
	public:
		RPN();
		RPN(const std::string &);
		RPN(const RPN &);
		RPN& operator=(const RPN &);
		~RPN();

		void calculate();

		class IncorrectRPNExpression : public std::exception
		{
		    const char* what() const throw();
		};
	private:
		std::string m_arg;
		std::stack<int> rpn;

};

#endif