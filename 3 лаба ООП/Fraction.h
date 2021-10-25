#pragma once

class Fraction
{
	long long whole;
	unsigned short fraction;
public:
	Fraction (long long first = 0, unsigned short second = 1);
	Fraction (const Fraction &copy);

	void reduction ();

	Fraction& operator= (const Fraction& ObjectToCopy);
	Fraction& operator+ (const Fraction& object);
	Fraction& operator- (const Fraction& object);
	Fraction& operator* (const Fraction& object);
	Fraction& operator/ (const Fraction& object);

	bool operator==(const Fraction& object);
	bool operator>=(const Fraction& object);
	bool operator<=(const Fraction& object);
	bool operator>(const Fraction& object);
	bool operator<(const Fraction& object);

	void setWhole(const long long value);
	void setFraction(const unsigned short value);

	const long long getWhole();
	const unsigned short getFraction();

	std::string ToString();
};

long long HOD(long long a, long long b);
long long HOK(long long a, long long b);
