/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radina Ovcharova
* @idnumber 3MI0600151
* @task 6
*
*/

#include <iostream>
const int MIN_SIZE = 1;
const unsigned long long MAX_SIZE = 1 << 31;
const int MAX_DIGITS = 10;
const int MIN_PALINDOROME = 101;


bool isInTheRange(unsigned long long start, unsigned long long end)
{
	return (start >= MIN_SIZE && end <= MAX_SIZE && start <= end);
}

bool isPalindrome(const int* array, int length)
{
	for (int i = 0; i < length / 2; i++)
	{
		if (array[i] != array[length - i - 1])
		{
			return false;
		}
	}
	return true;
}

bool isSemiPalindrome(const int* array, int length)
{
	int digitCount[MAX_DIGITS]{};
	for (int i = 0; i < length; i++)
	{
		digitCount[array[i]]++;
	}

	if ((length & 1) == 0)   
	{
		for (int i = 0; i < MAX_DIGITS; i++)
		{
			if ((digitCount[i] & 1) == 1) 
			{
				return false;
			}
		}
		return true;
	}
	else//с нечетна дължина
	{
		int counterOdd = 0;
		for (int i = 0; i < MAX_DIGITS; i++)
		{
			if ((digitCount[i] & 1) == 1)//ако има нечетен брой срещания
			{
				counterOdd++;
			}
		}

		return (counterOdd == 1 && length - digitCount[0] > 1);//ако има 1 на брой срещане на някоя цифра и 
	}
}

int getNumLength(unsigned long long n)
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

void convertToArray(unsigned long long num, int* numberInArray, int length)
{
	for (int i = length - 1; i >= 0; i--)
	{
		numberInArray[i] = num % 10;
		num /= 10;
	}
}
int countOfPalindromesAndSemiPalindromes(unsigned long long start, unsigned long long end)
{
	int counterForPalindromes = 0;
	int array[MAX_DIGITS];
	int length;

	if (start < MIN_PALINDOROME)
	{
		start = MIN_PALINDOROME;
	}

	for (int i = start; i <= end; i++)
	{
		length = getNumLength(i);
		convertToArray(i, array, length);

		if (isPalindrome(array, length))
		{
			counterForPalindromes++;

		}
		else if (isSemiPalindrome(array, length))
		{
			counterForPalindromes++;
		}
	}

	return counterForPalindromes;
}

int main()
{
	unsigned long long start, end;
	std::cin >> start >> end;

	if (!(isInTheRange(start, end)))
	{
		std::cout << -1;
		return 0;
	}
	std::cout << countOfPalindromesAndSemiPalindromes(start, end);

}


