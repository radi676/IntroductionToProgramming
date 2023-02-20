/**
*
* Solution to homework assignment 4
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
const int LOWER_BOUND = 1;
const int UPPER_BOUND = 20;

bool isValidInput(int input)
{
	return input >= LOWER_BOUND && input <= UPPER_BOUND;
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int countOperations(int firstCapacity, int secondCapacity, int required)
{
	int currentFirst = firstCapacity;
	int currentSecond = 0;
	int count = 1;

	while (currentFirst != required && currentSecond != required)
	{
		if (currentFirst == 0)
		{
			currentFirst = firstCapacity;
			count++;
		}

		if (currentSecond == secondCapacity)
		{
			currentSecond = 0;
			count++;
		}

		int changeAmount = secondCapacity - currentSecond;
		if (currentFirst < changeAmount) {
			changeAmount = currentFirst;
		}

		currentFirst -= changeAmount;
		currentSecond += changeAmount;

		count++;
	}

	return count;
}

int findMinOperations(int firstCapacity, int secondCapacity, int required)
{
	if ((required > firstCapacity && required > secondCapacity)
		|| (required % gcd(firstCapacity, secondCapacity)) != 0)
	{
		return -1;
	}

	int startFirstOperations = countOperations(firstCapacity, secondCapacity, required);
	int startSecondOperations = countOperations(secondCapacity, firstCapacity, required);
	return startFirstOperations < startSecondOperations ?
		startFirstOperations : startSecondOperations;
}

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	if (!isValidInput(n) || !isValidInput(m))
	{
		std::cout << "Invalid input";
	}

	std::cout << findMinOperations(n, m, k);
	return 0;
}


