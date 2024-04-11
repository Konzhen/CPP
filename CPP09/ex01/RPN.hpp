#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <regex.h>
#include <string>

class RPN
{
	private:

	RPN();
	RPN(const RPN &rpn);
	RPN &operator=(const RPN &rpn);

	protected:

	public:
	static void			exec(char *param);
	~RPN();
};

#endif