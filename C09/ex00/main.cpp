#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cerr << "Error: could not open file. " << std::endl;
		return 1;
	}

	BitcoinExchange obj;
	std::string filename = av[1];
	obj.loadDatabase();
	obj.processInputFile(filename);

	return 0;
}