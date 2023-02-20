/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radina Ovcharova
* @idnumber 3MI0600151
* @task 2
*
*/

#include <iostream>

const int MIN_SIZE_LENGTH = 1;
const int MAX_SIZE_LENGTH = 15;
const int MIN_NUM = 1;
const int MAX_NUM = 9999;
const int MAX_DIGITS = 4;
const char DIGIT_TO_CHAR = '0';

bool isValidLength(int length)
{
	return length >= MIN_SIZE_LENGTH && length <= MAX_SIZE_LENGTH;
}

bool isValidNumArray(const int* arrayNumbers, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (arrayNumbers[i] < MIN_NUM || arrayNumbers[i] > MAX_NUM)
		{
			return false;
		}
	}
	return true;
}

int getNumLength(int num)
{
	int numLength = 0;
	while (num > 0)
	{
		numLength++;
		num /= 10;
	}
	return numLength;
}

char* toString(int num)//parse from int to String
{
	int numLength = getNumLength(num);
	char* result = new char[numLength + 1];
	for (int i = numLength - 1; i >= 0; i--)
	{
		result[i] = num % 10 + DIGIT_TO_CHAR;
		num /= 10;
	}
	result[numLength] = '\0';
	return result;
}

bool areSameDigits(const char* first, const char* second)
{
	char check = first[0];
	int i = 0;

	while (first[i] != '\0')
	{
		if (first[i++] != check)
		{
			return false;
		}
	}

	i = 0;

	while (second[i] != '\0')
	{
		if (second[i++] != check)
		{
			return false;
		}
	}

	return true;
}

bool isOnTheLeft(const char* first, const char* second)
{
	int i = 0;
	while (first[i] != '\0' && second[i] != '\0')
	{
		if (first[i] != second[i])
		{
			return first[i] > second[i];
		}
		i++;
	}

	if (areSameDigits(first, second))
	{
		return first[i] == '\0';
	}

	if (first[i] == '\0')
	{
		return second[i] < second[0];
	}

	if (second[i] == '\0')
	{
		return first[i] >= first[0];
	}

	return false;
}

void swap(char*& first, char*& second)
{
	char* temp = first;
	first = second;
	second = temp;
}

void sortNums(char** numInArr, int length)
{
	int minIndex;

	for (int i = 0; i < length; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (isOnTheLeft(numInArr[j], numInArr[minIndex]))
			{
				minIndex = j;
			}
		}

		if (i != minIndex)
		{
			swap(numInArr[i], numInArr[minIndex]);
		}
	}
}

void freeDynamicArr(char** array, int N)
{
	for (int i = 0; i < N; i++)
	{
		delete[] array[i];
	}
	delete[]array;
}

int main()
{
	int length = 0;
	std::cin >> length;
	if (!isValidLength(length))
	{
		std::cout << -1;
		return 0;
	}

	int arrayNumbers[MAX_SIZE_LENGTH];
	for (int i = 0; i < length; i++)
	{
		std::cin >> arrayNumbers[i];
	}

	if (!isValidNumArray(arrayNumbers, length))
	{
		std::cout << -1;
		return 0;
	}

	char** charNumArr = new char* [length];//така правим масив от стрингове
	for (int i = 0; i < length; i++)
	{
		charNumArr[i] = toString(arrayNumbers[i]);
	}
	sortNums(charNumArr, length);
	for (int i = 0; i < length; i++)
	{
		std::cout << charNumArr[i] << " ";
	}

	freeDynamicArr(charNumArr, length);
	return 0;
}

