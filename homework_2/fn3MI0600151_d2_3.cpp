/**
*
* Solution to homework assignment 2
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
const int LOWER_BOUND = 1;
const int UPPER_BOUND = 20;
const int MAX_SIZE = 310;
const char DIGIT_TO_CHAR = '0';

bool isInRange(int n)
{
	return (n >= LOWER_BOUND && n <= UPPER_BOUND);
}

void getTheNMember(int N)
{
	char prev[MAX_SIZE]{};
	char current[MAX_SIZE]{};
	prev[0] = 1;

	for (int i = 1; i < N; i++)
	{
		int index = 0;
		int currentIndex = 0;

		while (prev[index] != 0)
		{
			char currentChar = prev[index];
			int counter = 0;
			while (prev[index] == currentChar)
			{
				counter++;
				index++;
			}

			current[currentIndex] = counter;
			currentIndex++;
			current[currentIndex] = currentChar;
			currentIndex++;
		}

		for (int j = 0; j < currentIndex; j++)
		{
			prev[j] = current[j];
			current[j] = 0;
		}

		for (int j = currentIndex; j < MAX_SIZE; j++)
		{
			prev[j] = current[j] = 0;
		}
	}

	int i = 0;
	while (prev[i] != 0)
	{
		prev[i] += DIGIT_TO_CHAR;
		i++;
	}

	std::cout << prev;
}


int main()
{
	int N;
	std::cin >> N;
	if (!(isInRange(N)))
	{
		std::cout << -1;
		return 0;
	}

	getTheNMember(N);
}

