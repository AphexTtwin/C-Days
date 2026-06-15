#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename Func>
void iter(T *array, const std::size_t len, Func f)
{
	if (!array || !f || len <= 0)
		return;
	for (std::size_t i = 0; i < len; ++i)
		f(array[i]);
}

#endif