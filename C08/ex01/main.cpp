#include "Span.hpp"

int main()
{

	try
	{

		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		sp.print();
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what();
	}

	std::cout <<  std::endl<< "|--------------------|" << std::endl;
	std::cout << std::endl;

	try
	{

		Span sp = Span(10000);
		for (int i = 0; i < 10000; i++)
		{
			sp.addNumber(rand());
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what();
	}

	std::cout <<  std::endl<< "|--------------------|" << std::endl;
	std::cout << std::endl;

	try
	{

		std::vector<int> cont;
		for (int i = 0; i < 10000; i++)
		{
			cont.push_back(rand());
		}

		Span sp(10002);
		sp.addNumber(6);
		sp.addNumber(3);

		sp.addNumbers(cont.begin(), cont.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what();
	}

}