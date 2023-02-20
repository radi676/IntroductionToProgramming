/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radina Ovcharova
* @idnumber 3MI0600151
* @task 2
*
*/

#include <iostream>;

const int LOWER_BOUND = 1;
const int UPPER_BOUND = 2000;

int printRomanNum(int number, int specialRomanNum, char romanSymbol1, char romanSymbol2) 
{
	int specialRomanNumsCount = number / specialRomanNum;
	for (int i = 0; i < specialRomanNumsCount; i++)
	{
		std::cout << romanSymbol1;
		if (romanSymbol2 != ' ')
		{
			std::cout << romanSymbol2;
		}
	}

	return number % specialRomanNum;
}

int main()
{

	int number = 0;
	std::cin >> number;

	if (number < LOWER_BOUND || number > UPPER_BOUND)
	{
		std::cout << "Incorrect input";
		return 0;
	}

	number = printRomanNum(number, 1000, 'M', ' ');
	number = printRomanNum(number, 900, 'C', 'M');
	number = printRomanNum(number, 500, 'D', ' ');
	number = printRomanNum(number, 400, 'C', 'D');
	number = printRomanNum(number, 100, 'C', ' ');
	number = printRomanNum(number, 90, 'X', 'C');
	number = printRomanNum(number, 50, 'L', ' ');
	number = printRomanNum(number, 40, 'X', 'L');
	number = printRomanNum(number, 10, 'X', ' ');
	number = printRomanNum(number, 9, 'I', 'X');
	number = printRomanNum(number, 5, 'V', ' ');
	number = printRomanNum(number, 4, 'I', 'V');
	number = printRomanNum(number, 1, 'I', ' ');

	return 0;
}