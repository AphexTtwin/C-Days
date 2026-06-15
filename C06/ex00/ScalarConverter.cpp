#include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void handleSpecialCase(std::string hsc, double &value)
{
	value = std::strtod(hsc.c_str(), NULL);
}

bool check_special_cases(std::string s, std::string special_Case[], double &value)
{
	for (int i = 0; i < 8; i++)
	{
		if (s == special_Case[i])
		{
			handleSpecialCase(s, value);
			return true;
		}
	}
	return false;
}
// Pseudo-literals" just means they're not real C++ literals, but you still need to handle them as special cases!

// NaN can be:
// Any undefined/imaginary result:
// Mathematical operations:
// cpp
// 0.0 / 0.0        // Zero divided by zero
// infinity - infinity
// infinity * 0
// sqrt(-1.0)       // Square root of negative
// log(-1.0)        // Logarithm of negative
// asin(2.0)        // Inverse sine out of range

// double x = 0.0 / 0.0;  // This creates NaN
// double y = sqrt(-1.0);  // Also creates NaN
// Why? NaN is the only value in programming that doesn't equal itself. It's a special rule!
void ScalarConverter::convert(char *str)
{
	std::string s = str;
	double value = 0.0;


	if (s.length() == 1)
	{
		char c = s[0];
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return;
	}

	std::string special_Case[] = {"nan", "nanf", "inf", "+inf",
								  "-inf", "inff", "+inff", "-inff"};

	bool isSpecial = check_special_cases(s, special_Case, value);

	if (!isSpecial)
	{
		char *endptr;
		value = std::strtod(s.c_str(), &endptr);
		// if (*endptr == 'f')
		// {
		// }
		// else if (*endptr != '\0' || endptr == s.c_str())
		// {
		// 	std::cout << "Invalide input: " << endptr << std::endl;
		// 	return;
		// }
		std::string remaining(endptr);

		// If there's anything left AND it's not exactly "f" or "F"
		if (!remaining.empty() && remaining != "f" && remaining != "F")
		{
			std::cout << "Invalide input: " << endptr << std::endl;
			return;
		}
	}

	if (value != value || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	if (value != value || value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	float f = static_cast<float>(value);
	std::cout << "float: " << f;
	if (f == static_cast<int>(f) && f == f)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << value;
	if (value == static_cast<int>(value) && value == value)
		std::cout << ".0";
	std::cout << std::endl;

	// char c = static_cast<char>(value);
	// int i = static_cast<int>(value);
	// float f = static_cast<float>(value);
	// double d = value;

	// std::cout << "char: " << c << std::endl;
	// std::cout << "int: " << i << std::endl;
	// std::cout << "float: " << f << std::endl;
	// std::cout << "double: " << d << std::endl;
}