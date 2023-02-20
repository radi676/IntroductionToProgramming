/**
*
* Solution to homework assignment 4
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
const int MAX_SIZE = 257;
const char RIGHT_BRACKET = ')';
const char LEFT_BRACKET = '(';

bool isValidInput(int len)
{
	return len <= MAX_SIZE;
}

int getLen(const char* arr)
{
	if (arr == nullptr)
	{
		return 0;
	}

	return *arr != '\0' ? 1 + getLen(arr + 1) : 0;
}

bool isClosedAndCorrect(char* array)
{
	if (array == nullptr)
	{
		return false;
	}

	int len = getLen(array);
	int currentCount = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == LEFT_BRACKET)
		{
			currentCount++;
		}
		else if (array[i] == RIGHT_BRACKET)
		{
			currentCount--;
		}
	}

	if (currentCount < 0)
	{
		return false;
	}

	if (currentCount == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}
int main()
{
	char input[MAX_SIZE * 3];
	std::cin.getline(input, MAX_SIZE * 3);

	if (!isValidInput(getLen(input)))
	{
		std::cout << "wrong input";
	}

	if (isClosedAndCorrect(input))
	{
		std::cout << "correct";
	}

	else
	{
		std::cout << "incorrect";
	}
}
