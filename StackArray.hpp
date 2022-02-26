#ifndef STACK_ARRAY_HPP
#define STACK_ARRAY_HPP

#include <iostream>
// #include <string>
// #include <memory>

#include "StackVirtual.hpp"
#include "StackArrayExceptions.hpp"

template <class T>
class StackArray : public Stack<T>
{
public:
	StackArray(int size = 100);
	StackArray(const StackArray<T>& src);
	StackArray(StackArray<T>&& src);
	StackArray& operator=(const StackArray<T>& src);
	StackArray& operator=(StackArray<T>&& src);
	virtual ~StackArray();

	void push(const T& e);
	T pop();
	T top();
	bool isEmpty();
	size_t getSize();

private:
	T* array_; // Массив элементов стека (0-й элемент не используется, top_ от 1 до size_)
	size_t top_; // Вершина стека, элемент, занесенный в стек последним
	size_t size_;
	void swap(StackArray<T>& src);
};

template <class T>
StackArray<T>::StackArray(int size) :
	array_(nullptr),
	top_(0),
	size_(size)
{
	try
	{
		array_ = new T[size + 1];
	}
	catch (...)
	{
		throw WrongStackSize();
	}
}

template <class T>
StackArray<T>::StackArray(const StackArray<T>& src) :
	array_(nullptr),
	top_(src.top_),
	size_(src.size_)
{
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
StackArray<T>::StackArray(StackArray<T>&& src) :
	array_(src.array_),
	top_(src.top_),
	size_(src.size_)
{
	src.array_ = nullptr;
	src.top_ = 0;
	src.size_ = 0;
}

template <class T>
StackArray<T>::~StackArray()
{
	delete[] array_;
}

template <class T>
void StackArray<T>::push(const T& a)
{
	if (top_ == size_)
	{
		throw StackOverflow();
	}
	array_[++top_] = a;
}

template <class T>
T StackArray<T>::pop()
{
	if (top_ == 0)
	{
		throw StackUnderflow();
	}
	return array_[top_--];
}

template <class T>
T StackArray<T>::top()
{
	if (top_ == 0)
	{
		throw ("Stack is empty!");
	}
	return array_[top_];
}

template <class T>
bool StackArray<T>::isEmpty()
{
	if (top_ == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
size_t StackArray<T>::getSize()
{
	return top_;
}

#endif
