#include "ScalarConverter.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "we need one argement ! \n";
		exit(1);
	}

	ScalarConverter::convert(av[1]);

}