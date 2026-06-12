#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>

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

void handleSpecialCase(std::string s, double &value)
{
	value = std::strtod(s.c_str(), NULL);
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


void ScalarConverter::convert(std::string const &literal)
{
	std::string s = literal;
	double value = 0.0;

	if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
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

	char *endptr;

	if (!isSpecial)
	{
		endptr = NULL;
		value = std::strtod(s.c_str(), &endptr);
		std::string remaining(endptr);
		if (!remaining.empty())
		{
			if ((remaining == "f" || remaining == "F") && s.find('.') != std::string::npos)
			{
			}
			else
			{
				std::cout << "char: impossible"   << std::endl;
				std::cout << "int: impossible"    << std::endl;
				std::cout << "float: impossible"  << std::endl;
				std::cout << "double: impossible" << std::endl;
				return ;
			}
		}
	}

	else
	{
		value = std::strtod(s.c_str(), &endptr);
		std::string remaining(endptr);
		if (!remaining.empty() && remaining != "f" && remaining != "F")
		{
			std::cout << "char: impossible"   << std::endl;
			std::cout << "int: impossible"    << std::endl;
			std::cout << "float: impossible"  << std::endl;
			std::cout << "double: impossible" << std::endl;
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
}