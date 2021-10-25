#include <iostream>
#include "Calculator.h"

void menu();


int main()
{
	std::cout << "Welcome to the program \"Calculator\"!";

	Calculator Object;
	std::cin >> Object;

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
			Object.addition();
		}break;
		case 4://-
		{
			Object.substraction();
		}break;
		case 5://*
		{
			Object.multiplication();
		}break;
		case 6://"/"
		{
			Object.division();
		}break;
		case 7://>,<,==
		{
			Object.compare();
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
	std::cout << "\n_________________________________________________";
}
