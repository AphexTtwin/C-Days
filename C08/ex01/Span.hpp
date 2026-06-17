#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	std::vector<int> vi;
	unsigned int size;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &src);
	Span &operator=(const Span &src);
	~Span();

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

	template <typename Iterator>
	void addNumbers(Iterator first, Iterator last)
	{
		int distance = std::distance(first, last);

		if(vi.capacity() - vi.size() < static_cast<size_t>(distance))
			throw std::out_of_range("the container not big to handle all that numbers\n");
		vi.insert(vi.end(), first, last);
	}

	void print();
};

#endif
