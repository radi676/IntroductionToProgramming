/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radina Ovcharova
* @idnumber 3MI0600151
* @task 3
*
*/

#include <iostream>

const int LOWER_BOUND = 2;
const int UPPER_BOUND = 9;
const int CONSOLE_WIDTH = 80;
const int CONSOLE_HEIGHT = 25;

int main()
{
	int n;
	std::cin >> n;

	if (n < LOWER_BOUND || n > UPPER_BOUND) {
		std::cout << "Incorrect input";
		return 0;
	}

	for (int outerRows = 0; outerRows < (CONSOLE_HEIGHT - (2 * n - 1)) / 2; outerRows++)
	{
		std::cout << std::endl;
	}

	for (int upperRow = 1; upperRow <= n; upperRow++)
	{
		for (int OuterSpaces = 0; OuterSpaces < (CONSOLE_WIDTH - 3 * n) / 2; OuterSpaces++)
		{
			std::cout << " ";
		}

		for (int leftUpperColumn = 1; leftUpperColumn <= upperRow; leftUpperColumn++)
		{
			std::cout << leftUpperColumn;
		}

		for (int spacesOrDashes = 1; spacesOrDashes <= n + (n - upperRow) * 2; spacesOrDashes++) {
			if (upperRow != n)
			{
				std::cout << " ";
			}
			else
			{
				std::cout << "-";
			}
		}

		for (int rightUpperColumn = upperRow; rightUpperColumn >= 1; rightUpperColumn--)
		{
			std::cout << rightUpperColumn;
		}

		std::cout << std::endl;
	}

	for (int BottomRow = n - 1; BottomRow > 0; BottomRow--)
	{
		for (int OuterSpaces = 0; OuterSpaces < (CONSOLE_WIDTH - 3 * n) / 2; OuterSpaces++)
		{
			std::cout << " ";
		}

		for (int leftNumber = 1; leftNumber <= BottomRow; leftNumber++)
		{
			std::cout << leftNumber;
		}

		for (int space = 1; space <= n + (n - BottomRow) * 2; space++) {
			std::cout << " ";
		}

		for (int rightNumber = BottomRow; rightNumber >= 1; rightNumber--)
		{
			std::cout << rightNumber;
		}

		std::cout << std::endl;
	}
	for (int outerRows = 0; outerRows < (CONSOLE_HEIGHT - (2 * n - 1)) / 2; outerRows++)
	{
		std::cout << std::endl;
	}

	return 0;
}