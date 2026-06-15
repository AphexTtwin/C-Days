#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T *arr;
	unsigned int n_size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	Array &operator=(const Array &src);
	~Array();

	T &operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	unsigned int size() const;
};

#include "Array.tpp"

#endif
