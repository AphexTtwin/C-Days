#ifndef  RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>


class RPN
{
private :
	std::string input;
	std::stack<int> stk;
public:
	RPN();
	RPN(std::string value);
	RPN(const RPN& src);
	RPN &operator=(const RPN& src);
	~RPN();

	void process_input();

	void print();
};

#endif