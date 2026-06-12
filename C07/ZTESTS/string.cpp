#include <iostream>

template<typename T>
T multiply(T a, T b)
{
	return (a * b);
}
int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";

	multiply(s1, s2);
}