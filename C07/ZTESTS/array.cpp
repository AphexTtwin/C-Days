#include <iostream>
#include <cstdio>

int main()
{
	int *a;
	a = new int();

	std::cout << *a << std::endl;
	printf("%d\n", *a);
}