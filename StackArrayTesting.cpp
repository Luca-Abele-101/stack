#include "StackArrayTesting.hpp"

#include <memory>

#include "StackArray.hpp"

bool checkBalanceBrackets(const std::string& text, int maxDeep)
{
	std::shared_ptr<Stack<char>> bracketsStack(new StackArray<char>(maxDeep));
	for (size_t i = 0; i < text.size(); i++)
	{
		switch (text[i])
		{
		case '(':
			bracketsStack->push('(');
			break;
		case '[':
			bracketsStack->push('[');
			break;
		case '{':
			bracketsStack->push('{');
			break;
		case ')':
			if ((bracketsStack->isEmpty()) || (bracketsStack->pop() != '('))
			{
				return false;
			}
			break;
		case ']':
			if ((bracketsStack->isEmpty()) || (bracketsStack->pop() != '['))
			{
				return false;
			}
			break;
		case '}':
			if ((bracketsStack->isEmpty()) || (bracketsStack->pop() != '{'))
			{
				return false;
			}
			break;
		}
	}
	if (bracketsStack->isEmpty())
	{
		return true;
	}
	else  //  Не все скобки закрыты
	{
		return false;
	}
}

bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize)
{
	if (!checkBalanceBrackets(infix, stackSize))
	{
		return false;
	}

	int countOfOperands = 0;
	int countOfOperators = 0;
	std::shared_ptr<Stack<char>> stack(new StackArray<char>(stackSize));

	for (size_t i = 0; i < infix.size(); i++)
	{
		switch (infix[i])
		{
		case '(':
			stack->push(infix[i]);
			break;
		case ')':
			while (stack->top() != '(')
			{
				postfix += stack->pop();
			}
			if (stack->top() == '(')
			{
				stack->pop();
			}
			break;
		case '+':
			countOfOperators++;
			while ((!stack->isEmpty()) && ((stack->top() == '*') || (stack->top() == '/') || (stack->top() == '+') || (stack->top() == '-')))
			{
				postfix += stack->pop();
			}
			stack->push(infix[i]);
			break;
		case '-':
			countOfOperators++;
			while ((!stack->isEmpty()) && ((stack->top() == '*') || (stack->top() == '/') || (stack->top() == '+') || (stack->top() == '-')))
			{
				postfix += stack->pop();
			}
			stack->push(infix[i]);
			break;
		case '*':
			countOfOperators++;
			while ((!stack->isEmpty()) && ((stack->top() == '*') || (stack->top() == '/')))
			{
				postfix += stack->pop();
			}
			stack->push(infix[i]);
			break;
		case '/':
			countOfOperators++;
			while ((!stack->isEmpty()) && ((stack->top() == '*') || (stack->top() == '/')))
			{
				postfix += stack->pop();
			}
			stack->push(infix[i]);
			break;
		default:
			postfix += infix[i];
			countOfOperands++;
			break;
		}
	}
	while (!stack->isEmpty())
	{
		postfix += stack->pop();
	}
	if ((countOfOperands - countOfOperators) != 1)
	{
		return false;
	}
	return true;
}

int evaluatePostfix(const std::string& infix, size_t stackSize)
{
	int a = 0;
	int b = 0;
	int res = 0;
	std::string postfix;
	if (!getPostfixFromInfix(infix, postfix, stackSize))
	{
		throw("Failed getting postfix form!");
	}
	std::shared_ptr<Stack<int>> stack(new StackArray<int>(stackSize));
	for (size_t i = 0; i < postfix.size(); i++)
	{
		if ((postfix[i] >= '0') && (postfix[i] <= '9'))
		{
			stack->push(static_cast<int>(postfix[i]) - static_cast<int>('0'));
		}
		else
		{
			if (stack->isEmpty())
			{
				throw ("Incorrect postix notation! Not enough operands.");
			}
			b = stack->pop();
			if (stack->isEmpty())
			{
				throw ("Incorrect postix notation! Not enough operands.");
			}
			a = stack->pop();
			switch (postfix[i])
			{
			case '+':
				stack->push(a + b);
				break;
			case '-':
				stack->push(a - b);
				break;
			case '*':
				stack->push(a * b);
				break;
			case '/':
				stack->push(a / b);
				break;
			default:
				throw("Unknown char in postfix string!");
				break;
			}
		}
	}
	if (stack->isEmpty())
	{
		throw("Incorrect postfix notation! No answer.");
	}
	res = stack->pop();
	if (!stack->isEmpty())
	{
		throw("Incorrect postfix notation! Not enough operators.");
	}
	return res;
}
