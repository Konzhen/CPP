#include "RPN.hpp"

RPN::RPN(){ }

RPN::RPN(const RPN &rpn)
{
	(void)rpn;
}

RPN& RPN::operator=(const RPN &rpn)
{
	(void)rpn;
	return *this;
}

RPN::~RPN(){ }

void			RPN::exec(char *param)
{
	std::stack<int> lst;
	int				tmp;
	int				tmp2;

	while(*param == ' ')
		param++;
	if (!isdigit(*param))
		throw std::runtime_error("Error, Wrong parameters");
	lst.push(*param - '0');
	param++;
	while(*param)
	{
		while(*param == ' ')
			param++;
		if (!isdigit(*param) && (*param != '+' && *param != '-' && *param != '/' && *param != '*'))
			throw std::runtime_error("Error, Wrong parameters");
		else if (*param >= '0' && *param <= '9')
			lst.push(*param - '0');
		if (lst.size() != 2)
			throw std::runtime_error("Error, Wrong parameters");
		else if (*param == '+')
		{
			tmp = lst.top();
			lst.pop();
			tmp2 = lst.top();
			lst.pop();
			lst.push(tmp2 + tmp);
		}
		else if (*param == '-')
		{
			tmp = lst.top();
			lst.pop();
			tmp2 = lst.top();
			lst.pop();
			lst.push(tmp2 - tmp);
		}
		else if (*param == '*')
		{
			tmp = lst.top();
			lst.pop();
			tmp2 = lst.top();
			lst.pop();
			lst.push(tmp2 * tmp);
		}
		else if (*param == '/')
		{
			tmp = lst.top();
			lst.pop();
			tmp2 = lst.top();
			lst.pop();
			lst.push(tmp2 / tmp);
		}
		if (lst.size() > 2)
			throw std::runtime_error("Error, Wrong parameters");
		param++;
	}
	tmp = lst.top();
	lst.pop();
	if (!lst.empty())
		throw std::runtime_error("Error, Wrong parameters");
	std::cout << tmp << std::endl;
}
