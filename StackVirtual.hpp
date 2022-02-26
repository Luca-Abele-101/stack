#ifndef STACK_VIRTUAL_HPP
#define STACK_VIRTUAL_HPP

#include <stddef.h>

template <class T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual void push(const T& e) = 0;
	virtual T pop() = 0;  //  Удаление + возврат верхнего элемента
	virtual T top() = 0;
	virtual bool isEmpty() = 0;
	virtual size_t getSize() = 0;
};

#endif
