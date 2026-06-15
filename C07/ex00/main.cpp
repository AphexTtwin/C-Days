#include <iostream>
#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	return 0;
}

// int main()
// {
// 	int a = 37;
// 	int b = 13;

// 	std::cout << std::endl;

// 	std::cout << "a = " << a << " " << "b = " << b << std::endl;
// 	swap(a,b);
// 	std::cout << "-----after the SWAP and shii-----\n";
// 	std::cout << "a = " << a << " " << "b = " << b << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "a = " << a << " " << "b = " << b << std::endl;
// 	std::cout << "-----after the MIN and shii-----\n";
// 	std::cout << min(a, b) <<std::endl;

// 	std::cout << std::endl;

// 	double c = 11.8;
// 	double d = 11.8;
// 	std::cout << "c = " << c << " " << "d = " << d << std::endl;
// 	std::cout << "-----after the MAX and shii-----\n";
// 	std::cout << max(c, d) <<std::endl;

// }