#include "iter.hpp"

template<typename T>
void printMutableElement(T &element)
{
	std::cout << element << std::endl;
}

template<typename T>
void printConstElement(const T &element)
{
	std::cout << element << std::endl;
}

template<typename T>
void incrementElement(T &element)
{
	++element;
	std::cout << element << std::endl;
}

int main()
{
	int numbers[] = {1, 2, 3, 4, 5};
	const char *words[] = {"one", "two", "three"};
	const int constants[] = {10, 20, 30};

	std::cout << "Mutable int array:" << std::endl;
	::iter(numbers, 5, printMutableElement<int>);

	std::cout << "Incremented int array:" << std::endl;
	::iter(numbers, 5, incrementElement<int>);

	std::cout << "String literal array:" << std::endl;
	::iter(words, 3, printConstElement<const char *>);

	std::cout << "Const int array:" << std::endl;
	::iter(constants, 3, printConstElement<int>);

	return 0;
}