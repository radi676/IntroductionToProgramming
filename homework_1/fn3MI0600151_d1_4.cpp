/**
*
* Solution to homework assignment 1
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

const long long LOWER_BOUND = 1;
const long long UPPER_BOUND = 1000000000;

bool isPrime(long long number) {
	for (long long i = 2; i <= number / 2; i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

bool hasDublicateDigits(long long number) {
	long long numberCopy = number;
	while (number != 0)
	{
		int lastDigit = number % 10;
		number /= 10;
		numberCopy = number;
		while (numberCopy != 0)
		{
			int lastCurrentDigit = numberCopy % 10;
			numberCopy /= 10;
			if (lastCurrentDigit == lastDigit)
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	long long number;
	std::cin >> number;

	if (number < LOWER_BOUND || number > UPPER_BOUND)
	{
		std::cout << "Incorrect input";
		return 0;
	}

	long long specialNumberLeft = 0;
	long long specialNumberRight = 0;

	for (long long i = number; i > LOWER_BOUND; i--)
	{
		if (!hasDublicateDigits(i) && isPrime(i)) {
			specialNumberLeft = i;
			break;
		}
	}

	for (long long i = number; i <= UPPER_BOUND; i++)
	{
		if (!hasDublicateDigits(i) && isPrime(i)) {
			specialNumberRight = i;
			break;
		}
	}

	if (specialNumberRight == 0)
	{
		std::cout << specialNumberLeft;
	}
	else if (number - specialNumberLeft == specialNumberRight - number)
	{
		std::cout << specialNumberLeft;
	}
	else if (number - specialNumberLeft < specialNumberRight - number)
	{
		std::cout << specialNumberLeft;
	}
	else
	{
		std::cout << specialNumberRight;
	}
}