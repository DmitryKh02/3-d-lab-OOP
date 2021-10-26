#include <iostream>
#include "Fraction.h"

Fraction::Fraction(long long first, unsigned short second)
{
	whole = first;
	fraction = second;
	
	reduction();
}

Fraction::Fraction(const Fraction& copy)
{
	if (this != &copy)
	{
		whole = copy.whole;
		fraction = copy.fraction;
	}
	else
	{
		whole = 0;
		fraction = 0;
	}
}


void Fraction::reduction()
{
	unsigned short WholePartOfDivision = HOD(whole, fraction);

	if (WholePartOfDivision > 1)
	{
		whole /= WholePartOfDivision;
		fraction /= WholePartOfDivision;
	}
}


Fraction& Fraction::operator=(const Fraction& ObjectToCopy)
{
	if (this != &ObjectToCopy)
	{
		whole = ObjectToCopy.whole;
		fraction = ObjectToCopy.fraction;
	}

	return *this;
}

Fraction& Fraction::operator+(const Fraction& object)
{
	Fraction *result = new Fraction ;
	long long factor = HOK(fraction, object.fraction);

	result->whole = (factor / fraction) * whole + (factor / object.fraction) * object.whole;
	result->fraction = factor;

	result->reduction();

	return *result;
}

Fraction& Fraction::operator-(const Fraction& object)
{
	Fraction *result = new Fraction;
	long long factor = HOK(fraction, object.fraction);

	result->whole = (factor / fraction) * whole - (factor / object.fraction) * object.whole;
	result->fraction = factor;

	result->reduction();

	return *result;
}

Fraction& Fraction::operator*(const Fraction& object)
{
	Fraction *result = new Fraction(whole * object.whole, fraction * object.fraction);
	
	result->reduction();

	return *result;
}

Fraction& Fraction::operator/(const Fraction& object)
{
	Fraction *result = new Fraction(whole* object.fraction, fraction* object.whole);

	if (result->fraction != 0)
		result->reduction();
	else
		result->fraction = 1;

	return *result;
}



bool Fraction::operator==(const Fraction& object)
{
	return whole == object.whole && fraction == object.fraction ? 1 : 0;
}

bool Fraction::operator>=(const Fraction& object)
{
	bool result=false;

	long long factor = HOK(fraction, object.fraction);
	long long newMultiplierToFirstWholePart = factor / fraction;
	long long newMultiplierToSecondWholePart = factor / object.fraction;

	if (whole * newMultiplierToFirstWholePart >= object.fraction * newMultiplierToSecondWholePart) result = true;

	return result;
}

bool Fraction::operator<=(const Fraction& object)
{
	return whole * HOK(fraction, object.fraction) / fraction <= object.whole * HOK(fraction, object.fraction) / object.fraction ? 1 : 0;
}

bool Fraction::operator>(const Fraction& object)
{
	return whole * HOK(fraction, object.fraction) / fraction > object.whole * HOK(fraction, object.fraction) / object.fraction ? 1 : 0;
}

bool Fraction::operator<(const Fraction& object)
{
	return whole * HOK(fraction, object.fraction) / fraction < object.whole * HOK(fraction, object.fraction) / object.fraction ? 1 : 0;
}


void Fraction::setWhole(const long long value)
{
	whole = value;
	
}

void Fraction::setFraction(const unsigned short value)
{
	value == 0 ? fraction = 1 : fraction = value;
}

const long long Fraction::getWhole()
{
	return whole;
}

const unsigned short Fraction::getFraction()
{
	return fraction;
}


std::ostream& operator<<(std::ostream& out, Fraction& const object)
{
	out <<object.whole << "/" << object.fraction;

	return out;
}

long long HOD(long long a, long long b)
{
	long long WholePartOfDivision(1);

	if ((a && b) != 0)
	{
		long long remainder(1);

		a = abs(a);
		b = abs(b);

		if (a < b)
			std::swap(a, b);

		while (remainder != 0)
		{
			WholePartOfDivision = b;
			remainder = a % b;
			a = b;
			b = remainder;
		}
	}

	return WholePartOfDivision;
}

long long HOK(long long a, long long b)
{
	return (abs(a) * abs(b) / HOD(a, b));
}
