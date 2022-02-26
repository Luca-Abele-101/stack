#include <iostream>

#include "StackVirtual.hpp"
#include "StackArrayExceptions.hpp"
#include "StackArray.hpp"

template <class T>
void StackArray<T>::swap(StackArray<T>& src)
{
	std::swap(array_, src.array_);
	std::swap(top_, src.top_);
	std::swap(size_, src.size_);
}

template <class T>
StackArray<T>& StackArray<T>::operator=(const StackArray& src)
{
	if (this == &src)
	{
		return *this;
	}

	size_ = src.size_;
	top_ = src.top_;
	delete[] array_;

	try
	{
		array_ = new T[src.size_ + 1];
	}
	catch (...)
	{
		throw WrongStackSize();
	}

	for (int i = 1; i <= src.top_; i++)
	{
		array_[i] = src.array_[i];
	}
}

template <class T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& src)
{
	if (this == &src)
	{
		return *this;
	}

	size_ = src.size_;
	top_ = src.top_;
	delete[] array_;
	array_ = src.array_;

	src.size_ = 0;
	src.top_ = 0;
	src.array_ = nullptr;
}
