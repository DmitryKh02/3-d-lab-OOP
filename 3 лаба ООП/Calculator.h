#pragma once
#include "Fraction.h"

class Calculator 
{
protected:
	Fraction first;
	Fraction second;
public:
	Calculator(long long a = 0, unsigned short b = 0, long long c = 0, unsigned short d = 0) :first(a, b), second(c, d) {};

	Fraction addition();
	Fraction substraction();
	Fraction multiplication();
	Fraction division();

	int compare();

	friend std::ostream& operator<< (std::ostream& out, Calculator& const object);
	friend std::istream& operator>> (std::istream& in, Calculator& const object);
};

template <class Type>
Type check(Type left, Type right);