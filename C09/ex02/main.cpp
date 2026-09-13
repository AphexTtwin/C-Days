#include "PmergeMe.hpp"


int main(int ac, char **av)
{
	try
	{
		if (ac < 2)
		{
			std::cout << "Error enter at least two numbers \n";
			return 1;
		}

		PmergeMe obj;

		obj.parseInput(av);
		obj.process();
		return 0;

	}
	catch(std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

}