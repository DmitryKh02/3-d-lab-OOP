#include <iostream>
#include <string>
#include <fstream>
#include "Calculator.h"

void Calculator::addition()
{
	Fraction AddResult;
	AddResult = first + second;
	std::cout << "\nFirst + second = ";
	std::cout << AddResult.ToString();
}

void Calculator::substraction()
{
	Fraction SubResult(first - second);
	std::cout << "\nFirst - second = ";
	std::cout << SubResult.ToString();
}

void Calculator::multiplication()
{
	Fraction MultResult;
	MultResult = first * second;
	std::cout << "\nFirst * second = ";
	std::cout << MultResult.ToString();
}

void Calculator::division()
{
	Fraction MultResult;
	MultResult = first / second;
	std::cout << "\nFirst / second = ";
	std::cout << MultResult.ToString();
}


void Calculator::compare()
{
	if (first == second) 
		std::cout << "\nThey is equal!";
	else
	{
	if (first > second)
		std::cout << "\nThe First is more than the Second!";
	else
		std::cout << "\nThe Second is more than the First!";
	}
}


std::ostream& operator<< (std::ostream& out, Calculator& const object)
{
	out << "\n-----------------------First-----------------------\n";
	out << object.first.ToString();

	out << "\n-----------------------Second-----------------------\n";
	out << object.second.ToString();

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