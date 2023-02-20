/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radina Ovcharova
* @idnumber 3MI0600151
* @task 5
*
*/

#include <iostream>
const long long UPPER_BOUND = 10000000000;
const long long LOWER_BOUND = 1;
const int MAX_SIZE = 10;

bool isInTheRange(long long number)
{
	return(number >= LOWER_BOUND && number <= UPPER_BOUND);
}

bool isPrime(long long number)
{

	if (number == 0 || number == 1)
	{
		return false;
	}

	for (long long i = 2; i <= number / 2; i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

int getNumLength(long long n)
{
	int length = 0;
	if (n == 0)
	{
		return 1;
	}

	while (n > 0)
	{
		length++;
		n /= 10;
	}

	return length;
}

void convertToArray(long long num, int* numberInArray, int length)
{
	for (int i = length - 1; i >= 0; i--)
	{
		numberInArray[i] = num % 10;
		num /= 10;
	}
}

int convertToNum(int* numberInArray, int length)
{
	int number = 0;
	for (int i = 0; i < length; i++)
	{
		number = number * 10 + numberInArray[i];
	}
	return number;
}

int minOperations(long long number)
{
	if (isPrime(number))
	{
		return 0;
	}

	int numberInArray[MAX_SIZE];
	int* numArr = numberInArray;
	int length = getNumLength(number);
	convertToArray(number, numberInArray, length);

	int counter = 0;
	bool found = 0;
	int minOperation = length;

	while (length > 0)
	{
		int localCounter = counter;
		for (int i = 0; i <= length - 1; i += 2)
		{
			if (isPrime(convertToNum(numArr, length - i)))
			{
				minOperation = minOperation > localCounter ? localCounter : minOperation;
				found = true;
			}
			localCounter++;
		}

		do {
			counter++;
			numArr++;
			length--;
		}
		while (*numArr == 0 && length > 0);
	}

	return found ? minOperation : -1;
}

int main()
{

	long long number;
	std::cin >> number;
	if (!(isInTheRange(number)))
	{
		std::cout << -2;
		return 0;
	}
	std::cout << minOperations(number);

}

