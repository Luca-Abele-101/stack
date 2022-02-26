#include <iostream>

#include "StackArray.hpp"
#include "StackArrayTesting.hpp"

int main()
{
	std::cout << "-= Brackets Testing: =-\n";
	const char* test1 = "( ) must be OK";
	const char* test2 = "( {} ( [] ) [] ) must be OK";
	const char* test3 = "( ( [ ] ) extra opening bracket ";
	const char* test4 = "( [ ] ) ) extra closing bracket ";
	const char* test5 = "( { ] )  different types of brackets ";
	const char* test6 = ") ) ( ) closing brackets before opening brackets ";
	std::cout << test1 << " : " << (checkBalanceBrackets(test1) ? "right" : "wrong") << std::endl;
	std::cout << test2 << " : " << (checkBalanceBrackets(test2) ? "right" : "wrong") << std::endl;
	std::cout << test3 << " : " << (checkBalanceBrackets(test3) ? "right" : "wrong") << std::endl;
	std::cout << test4 << " : " << (checkBalanceBrackets(test4) ? "right" : "wrong") << std::endl;
	std::cout << test5 << " : " << (checkBalanceBrackets(test5) ? "right" : "wrong") << std::endl;
	std::cout << test6 << " : " << (checkBalanceBrackets(test6) ? "right" : "wrong") << std::endl;
	std::cout << "-=====================-\n\n";

	std::cout << "-= Transforming Infix into Postfix Testing: =-\n";
	std::string post7 = "";
	const char* test7 = "(A+B)*(C+D)-E*F*G+H/I";
	std::string post8 = "";
	const char* test8 = "A*(B+C)/D*(E+F)";
	std::string post9 = "";
	const char* test9 = "A*(B+C)/(D*(E+F))";
	std::string post10 = "";
	const char* test10 = "A+[B+C]*D-";
	std::string post11 = "";
	const char* test11 = "(A-B";
	std::cout << test7 << " : " << (getPostfixFromInfix(test7, post7) ? post7 : "wrong") << std::endl;
	std::cout << test8 << " : " << (getPostfixFromInfix(test8, post8) ? post8 : "wrong") << std::endl;
	std::cout << test9 << " : " << (getPostfixFromInfix(test9, post9) ? post9 : "wrong") << std::endl;
	std::cout << test10 << " : " << (getPostfixFromInfix(test10, post10) ? post10 : "wrong") << std::endl;
	std::cout << test11 << " : " << (getPostfixFromInfix(test11, post11) ? post11 : "wrong") << std::endl;
	std::cout << "-============================================-\n\n";

	std::cout << "-= Calculation Postfix Testing: =-\n";
	const char* test12 = "7+3*5-6";
	std::cout << test12 << ": " << evaluatePostfix(test12) << std::endl;
	const char* test13 = "2*(7+3)/(8-3)*2";
	std::cout << test13 << ": " << evaluatePostfix(test13) << std::endl;
	const char* test14 = "2*(7+3)/((8-3)*2)";
	std::cout << test14 << ": " << evaluatePostfix(test14) << std::endl;
	const char* test15 = ")+5*[(**/)";
	std::cout << test15 << " : ";
	try
	{
		std::cout << evaluatePostfix(test15) << std::endl;
	}
	catch (const char* evaluationError)
	{
		std::cout << evaluationError << std::endl;
	}
	std::cout << "-================================-\n";

	return 0;
}
