/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radina Ovcharova
* @idnumber 3MI0600151
* @task 1
*
*/

#include <iostream>
const int MAX_SIZE = 1024;
const int MIN_SIZE = 1;
const char DIGIT_TO_CHAR = '0';

bool isInRange(int n)
{
	return(n >= MIN_SIZE && n <= MAX_SIZE);
}

bool isGreater(char numberOne[MAX_SIZE], char numberTwo[MAX_SIZE], int N, int K)
{
	if (N != K)
	{
		return N > K;
	}

	for (int i = 0; i < N; i++)
	{
		if (numberOne[i] < numberTwo[i])
		{
			return false;
		}
	}

	return true;
}

void sum(char numberOne[MAX_SIZE], char numberTwo[MAX_SIZE], int N, int K)
{
	char sum[MAX_SIZE + 1]{};

	int i = N - 1;
	int j = K - 1;
	int indexResult = MAX_SIZE - 1;
	int carry = 0;

	while (i >= 0 && j >= 0)
	{
		int s = numberOne[i] - DIGIT_TO_CHAR + numberTwo[j] - DIGIT_TO_CHAR + carry;
		sum[indexResult] = s % 10 + DIGIT_TO_CHAR;
		carry = 0;
		if (s > 9)
		{
			carry = 1;
		}
		i--;
		j--;
		indexResult--;
	}

	while (i >= 0)
	{
		int s = numberOne[i] - DIGIT_TO_CHAR + carry;
		sum[indexResult] = s % 10 + DIGIT_TO_CHAR;
		carry = 0;
		if (s > 9)
		{
			carry = 1;
		}
		i--;
		indexResult--;

	}

	while (j >= 0)
	{
		int s = numberOne[j] - DIGIT_TO_CHAR + carry;
		sum[indexResult] = s % 10 + DIGIT_TO_CHAR;
		carry = 0;
		if (s > 9)
		{
			carry = 1;
		}
		j--;
		indexResult--;

	}

	if (carry > 0)
	{
		sum[indexResult] = carry + DIGIT_TO_CHAR;
		indexResult--;
	}

	std::cout << sum + indexResult + 1 << std::endl;
}


void subtract(const char numberOne[MAX_SIZE], const char numberTwo[MAX_SIZE], const int N, int K)
{
	char subtract[MAX_SIZE + 1]{};
	int i = N - 1;
	int j = K - 1;
	int indexResult = MAX_SIZE - 1;
	int carry = 0;
	char num1Copy[MAX_SIZE]{};

	for (int k = 0; k < N; k++)
	{
		num1Copy[k] = numberOne[k];
	}

	while (i >= 0 && j >= 0)
	{
		if (num1Copy[i] < numberTwo[j])
		{
			num1Copy[i] += 10;
			int index = i - 1;
			while (num1Copy[index] - DIGIT_TO_CHAR == 0) {
				num1Copy[index] = '9';
				--index;
			}
			--num1Copy[index];
		}
		subtract[indexResult] = num1Copy[i] - numberTwo[j] + DIGIT_TO_CHAR;
		i--;
		j--;
		indexResult--;
	}

	while (i >= 0)
	{
		subtract[indexResult] = num1Copy[i];
		i--;
		indexResult--;
	}

	while (indexResult + 1 < MAX_SIZE - 1 && subtract[indexResult + 1] == '0')
	{
		indexResult++;
	}

	std::cout << subtract + indexResult + 1 << std::endl;
}

void printSumAndSubtractTwoNumbers
(char numberOne[MAX_SIZE], char numberTwo[MAX_SIZE], int N, int K)
{
	if (numberOne[0] == '-' && numberTwo[0] != '-')
	{
		if (isGreater(numberTwo, numberOne + 1, K, N))
		{
			subtract(numberTwo, numberOne + 1, K, N);
		}
		else
		{
			std::cout << "-";
			subtract(numberOne + 1, numberTwo, N, K);
		}
		std::cout << "-";
		sum(numberOne + 1, numberTwo, N , K);

	}
	else if (numberOne[0] != '-' && numberTwo[0] == '-')
	{
		if (isGreater(numberOne, numberTwo + 1, N, K))
		{
			subtract(numberOne, numberTwo + 1, N, K);
		}
		else
		{
			std::cout << "-";
			subtract(numberTwo + 1, numberOne, K, N);
		}

		sum(numberOne, numberTwo + 1, N, K);

	}
	else if (numberOne[0] != '-' && numberTwo[0] != '-')
	{
		sum(numberOne, numberTwo, N, K);
		if (isGreater(numberOne, numberTwo, N, K))
		{
			subtract(numberOne, numberTwo, N, K);
		}
		else
		{
			std::cout << "-";
			subtract(numberTwo, numberOne, K, N);
		}

	}
	else
	{
		std::cout << "-";
		sum(numberOne + 1, numberTwo + 1, N, K);
		if (isGreater(numberTwo + 1, numberOne + 1, K, N))
		{
			subtract(numberTwo + 1, numberOne + 1, K, N);
		}
		else
		{
			std::cout << "-";
			subtract(numberOne + 1, numberTwo + 1, N, K);
		}
	}
}

int main()
{
	int N;
	std::cin >> N;
	char numberOne[MAX_SIZE];
	std::cin >> numberOne;

	int K;
	std::cin >> K;
	char numberTwo[MAX_SIZE];
	std::cin >> numberTwo;

	if (!(isInRange(N)))
	{
		std::cout << -1;
		return 0;
	}

	if (!(isInRange(K)))
	{
		std::cout << -1;
		return 0;
	}

	printSumAndSubtractTwoNumbers(numberOne, numberTwo, N, K);
}

