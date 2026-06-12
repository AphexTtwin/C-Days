#include <iostream>


template<typename T>
void fun( T &elm)
{
	std::cout << "the element " << elm << std::endl;
}

template<typename T>
void mody(T &elm)
{
	elm = elm - 1;
	std::cout << "the element " << elm << std::endl;
}

template<typename T>
void iter(T *array,const int len, void (*f)(const T &))
{
	for (int i = 0; i < len; i++)
		f(array[i]);
}