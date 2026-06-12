#include <iostream>
#include <string>

// template<typename T>
template<class T>

void Print(T k)
{
	std::cout << k << std::endl;
}

int main()
{
	// Print(10);
	// Print(12.7);
	// Print<int>(12.7);

	// Print("tanaka");
	// Print<char>(66);

	std::cin.get();
}