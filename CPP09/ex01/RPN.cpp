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
		if (*param == '\0')
			break ;
		if (!isdigit(*param) && (*param != '+' && *param != '-' && *param != '/' && *param != '*'))
			throw std::runtime_error("Error, Wrong parameters");
		else if (*param >= '0' && *param <= '9')
			lst.push(*param - '0');
		else if (*param == '+')
		{
			tmp = lst.top();
			lst.pop();
			lst.top() += tmp;
		}
		else if (*param == '-')
		{
			tmp = lst.top();
			lst.pop();
			lst.top() -= tmp;
		}
		else if (*param == '*')
		{
			tmp = lst.top();
			lst.pop();
			lst.top() *= tmp;
		}
		else if (*param == '/')
		{
			if (lst.top() == 0)
				throw std::runtime_error("Error, Divided by 0");
			tmp = lst.top();
			lst.pop();
			lst.top() /= tmp;
		}
		param++;
	}
	int tab[lst.size()];
	size_t s = lst.size();
	size_t i;
	for (i = 0; i < s; i++)
	{
		tab[i] = lst.top();
		lst.pop();
	}
	i--;
	while (true)
	{
		std::cout << tab[i] << " ";
		if (i == 0)
			break ;
		i--;
	}
	std::cout << std::endl;
}
