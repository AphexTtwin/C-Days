#include "Span.hpp"

Span::Span()
{
	vi.reserve(0);
	size = 0;
}

Span::Span(unsigned int n)
{
	vi.reserve(n);
	size = n;
}

Span::Span(const Span& src)
{
	vi = src.vi;
	this->size = src.size;
}
Span& Span::operator=(const Span &src)
{

	if (this != &src)
	{
		vi = src.vi;
		this->size = src.size;
	}
	return *this;
}
Span::~Span()
{

}

void Span::addNumber(int num)
{
	if (vi.size() < size)
	{
		vi.push_back(num);
	}
	else
		throw std::out_of_range("container is full you cant add more\n");

}

void Span::print()
{
	std::cout << "--------------------" << std::endl;
	std::cout << "container capacity is " << vi.capacity() << std::endl;
	std::cout << "container size s is " << vi.size() << std::endl;
	std::cout << "now printing values .\n";

	std::vector<int>::iterator it = vi.begin();
	for (size_t i = 0; i < vi.size(); i++)
		std::cout << it[i] << " - ";
	std::cout << std::endl;
}

int Span::shortestSpan()
{
	if (vi.size() <= 1)
		throw std::out_of_range("we dont have enough numbers \n");

	std::vector<int> temp = vi;
	std::sort(temp.begin(), temp.end());

	std::vector<int>::iterator  it = temp.begin();
	std::vector<int>::iterator itplus = temp.begin();

	itplus++;
	int res;
	int val = *itplus - *it;
	while (itplus != temp.end())
	{
		res =  *itplus - *it;

		if (res < val)
			val = res;
		it++;
		itplus++;
	}
	return val;
}

int Span::longestSpan()
{
	if (vi.size() <= 1)
		throw std::out_of_range("we dont have enough numbers \n");

	std::vector<int>::iterator max;
	std::vector<int>::iterator min;

	min = std::min_element(vi.begin(), vi.end());
	max = std::max_element(vi.begin(), vi.end());

	return (*max - *min);
}