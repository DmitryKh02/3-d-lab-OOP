#include <iostream>
#include "Calculator.h"

void menu();


int main()
{
	std::cout << "Welcome to the program \"Calculator\"!";

	Calculator Object;
	std::cin >> Object;

	Fraction Result;

	int menuPointer = 0;
	do
	{
		menu();

		menuPointer = check(0, 8);

		switch (menuPointer)
		{
		case 1://Print
		{
			std::cout << Object;
		}break;
		case 2://New value
		{
			std::cin >> Object;
		}break;
		case 3://+
		{
			Result = Object.addition();
			std::cout << "First + Second = " << Result;
		}break;
		case 4://-
		{
			Result = Object.substraction();
			std::cout << "First - Second = " << Result;
		}break;
		case 5://*
		{
			Result = Object.multiplication();
			std::cout << "First * Second = " << Result;
		}break;
		case 6://"/"
		{
			Result = Object.division();
			std::cout << "First / Second = " << Result;
		}break;
		case 7://>,<,==
		{
			int resultOfCompare = Object.compare();

			if (resultOfCompare == 0)
				std::cout << "\nThey is equal!";
			else
				if (resultOfCompare > 0)
					std::cout << "\nThe First is more than the Second!";
				else
					std::cout << "\nThe Second is more than the First!";
		}break;
		}

	} while (menuPointer != 8);

	return 0;
}


void menu()
{
	std::cout << "\n________________________________________________";
	std::cout << "\n1)Print all numbers";
	std::cout << "\n2)Update values";
	std::cout << "\n3)\"+\"";
	std::cout << "\n4)\"-\"";
	std::cout << "\n5)\"*\"";
	std::cout << "\n6)\"/\"";
	std::cout << "\n7)\">,<,=\"";
	std::cout << "\n8)Out";
	std::cout << "\n_________________________________________________";
}
