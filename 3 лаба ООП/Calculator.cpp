#include <iostream>
#include <string>
#include <fstream>
#include "Calculator.h"

Fraction Calculator::addition()
{
	return Fraction (first + second);
}

Fraction Calculator::substraction()
{
	return Fraction(first - second);
}

Fraction Calculator::multiplication()
{
	return Fraction(first * second);
}

Fraction Calculator::division()
{
	return Fraction(first / second);
}


int Calculator::compare()
{
	int result = -1;
	if (first == second)
		result = 0;
	else
		if (first > second)
			result = 1;

	return result;
}


std::ostream& operator<< (std::ostream& out, Calculator& const object)
{
	out << "\n-----------------------First-----------------------\n";
	out << object.first;

	out << "\n-----------------------Second-----------------------\n";
	out << object.second;

	return out;
}

std::istream& operator>>(std::istream& in, Calculator& const object)
{
	long long firstW, secondW;
	unsigned short firstF, secondF;

	std::cout << "\nEnter first whole part:";
	std::cin >> firstW;
	object.first.setWhole(firstW);

	std::cout << "\nEnter first fraction part:";
	firstF = check(1, 65535);
	object.first.setFraction(firstF);

	object.first.reduction();

	std::cout << "\nEnter second whole part:";
	std::cin >> secondW;
	object.second.setWhole(secondW);

	std::cout << "\nEnter second fraction part:";
	secondF = check(1, 65535);
	object.second.setFraction(secondF);

	object.second.reduction();

	return in;
}

template<class Type>
Type check(Type left, Type right)
{
	Type result;
	std::cout << "\nEnter meaning from " << left << " to " << right << ": ";
	std::cin >> result;

	while (result < left || result > right)
	{
		std::cin.clear();
		std::cout << "\nEnter right meaning: ";
		std::cin >> result;
		std::cin.ignore();
	}

	return result;
}