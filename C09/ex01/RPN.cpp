#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string value)
{
	input = value;
}

RPN::RPN(const RPN &src)
{
	this->input = src.input;
	this->stk = src.stk;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		this->input = src.input;
		this->stk = src.stk;
	}
	return *this;
}

RPN::~RPN()
{
}

//"+ - / *"
static bool isOPerator(char c)
{
	return c == '+' || c == '-' || c == '/' || c == '*';
}

//"+ - / *"
void managedStack(int a, int b, std::stack<int> &stk, char c)
{
	int value;

	if (c == '+')
		value = a + b;
	else if (c == '-')
		value = a - b;
	else if (c == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error: Division by zero!\n");
		value = a / b;
	}
	else if (c == '*')
		value = a * b;
	stk.push(value);
}

void RPN::process_input()
{
	size_t i = 0;
	while (i < input.size())
	{
		if (std::isdigit(input[i]))
		{
			int value = input[i] - '0';
			stk.push(value);
			i++;
		}
		else if (isOPerator(input[i]))
		{
			if (stk.size() < 2)
				throw std::runtime_error("Error: Not enough operands!\n");
			int b = stk.top();
			stk.pop();
			int a = stk.top();
			stk.pop();
			managedStack(a, b, stk, input[i]);
			i++;
		}
		else if (std::isspace(input[i]))
		{
			i++;
		}
		else
			throw std::runtime_error("Invalid input!\n");
	}
}

void RPN::print()
{
	if (stk.empty())
		throw std::runtime_error("Error: No result!\n");
	if (stk.size() != 1)
		throw std::runtime_error("Error \n");
	std::cout << stk.top() << std::endl;
}