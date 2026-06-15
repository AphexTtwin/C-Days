#ifndef ARRAY_TPP
#define ARRAY_TPP

// This is called value initialization.
#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	arr = new T[0];
	n_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	arr = new T[n];
	n_size = n;
}

template <class T>
Array<T>::Array(const Array &src)
{
	this->n_size = src.n_size;
	this->arr = new T[n_size];
	for (unsigned int i = 0; i < n_size; i++)
		this->arr[i] = src.arr[i];
}


template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{

	if (this != &src)
	{
		delete[] this->arr;
		this->n_size = src.n_size;
		this->arr = new T[n_size];

		for (unsigned int i = 0; i < n_size; i++)
			this->arr[i] = src.arr[i];
	}
	return *this;
}
template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= n_size)
		throw std::out_of_range("index is out of range");

	return arr[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= n_size)
		throw std::out_of_range("index is out of range");

	return arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return n_size;
}

#endif