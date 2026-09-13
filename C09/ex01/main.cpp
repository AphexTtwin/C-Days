#include "RPN.hpp"

int main(int ac, char **av)
{


	try
	{

		if (ac != 2)
		{
			std::cerr << "We need one argement ! \n";
			return 1;
		}

		RPN rpn(av[1]);

		rpn.process_input();
		rpn.print();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	return 0;
}