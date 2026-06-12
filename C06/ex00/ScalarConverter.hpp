#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#include <iostream>
#include <string>

class ScalarConverter //utility classes
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
	~ScalarConverter();

public:
	static void convert(std::string const &literal);
};
#endif
// Instantiation