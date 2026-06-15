#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#include <iostream>

class ScalarConverter
{
private:

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
	~ScalarConverter();

	static void convert(char *c);
};



#endif