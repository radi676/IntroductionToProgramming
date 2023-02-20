/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radina Ovcharova
* @idnumber 3MI0600151
* @task 4
*
*/

#include <iostream>
const int MIN_SIZE = 2;
const int MAX_SIZE = 1024;

const long long LOWER_BOUND = 1;
const long long UPPER_BOUND = 10000000000;

bool isWithinBoundaries(int length)
{
	return(length >= MIN_SIZE && length <= MAX_SIZE);
}

long long gcd(long long x, long long y)
{
	long long result = y;
	if (x < y)
	{
		result = x;
	}

	while (result > 0)
	{
		if (x % result == 0 && y % result == 0)
		{
			break;
		}
		result--;
	}

	return result;
}

void readArray(long long* numbers, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cin >> numbers[i];
	}
}

bool isInTheRangeOfNumbers(const long long* numbers, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (!(numbers[i] >= LOWER_BOUND && numbers[i] <= UPPER_BOUND))
		{
			return false;
		}
	}
	return true;
}

void incrementNum(bool num[MAX_SIZE], int length)
{
	int i = length - 1;

	if (num[i] == 0)
	{
		num[i] = 1;
		return;
	}

	bool carry = 1;
	num[i] = 0;
	i--;

	while (i >= 0)
	{
		if (num[i] && carry)
		{
			num[i] = 0;
			carry = 1;
		}
		else {
			num[i] = num[i] || carry;
			carry = 0;
		}

		i--;
	}
}

bool isMagicalArray(const long long* numbers, int length)
{
	int includedElements = 0;
	bool currentSubset[MAX_SIZE]{};
	while (includedElements != length)
	{
		includedElements = 0;
		incrementNum(currentSubset, length);
		int index = 0;
		while (currentSubset[index] == 0)
		{
			index++;
		}

		long long gcdCurrent = numbers[index];

		for (; index < length; index++)
		{
			if (currentSubset[index])
			{
				includedElements++;
				gcdCurrent = gcd(gcdCurrent, numbers[index]);
				if (gcdCurrent == 1)
				{
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	int length;
	std::cin >> length;

	if (!isWithinBoundaries(length))
	{
		std::cout << -1;
		return 0;
	}

	long long numbers[MAX_SIZE];
	readArray(numbers, length);
	if (!isInTheRangeOfNumbers(numbers, length))
	{
		std::cout << -1;
		return 0;
	}

	std::cout << isMagicalArray(numbers, length);

}
