#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


template<typename T>

typename T::iterator easyfind(T &container , int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::out_of_range("value not found!\n");
	else
		return it;
}
#endif