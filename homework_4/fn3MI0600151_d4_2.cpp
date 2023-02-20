/**
*
* Solution to homework assignment 4
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
const int MAX_SYMBOLS = 257;
const char MAX_LETTER = 'z';

int getLen(const char* arr)
{
	return *arr != '\0' ? 1 + getLen(arr + 1) : 0;
}

bool isValidInput(int len)
{
	return len <= MAX_SYMBOLS;
}

void printOcurrances(const char* s, const char* w)
{

	if (s == nullptr || w==nullptr)
	{
		return;
	}

	int sLen = getLen(s);
	int wLen = getLen(w);
	bool isFound = false;

	for (int i = 0; i < sLen - wLen + 1; i++)
	{
		int countWLetters[MAX_LETTER + 1]{};
		for (int j = 0; j < wLen; j++)
		{
			countWLetters[w[j]]++;
		}

		int count = 0;
		for (int k = 0; k < wLen; k++)
		{
			if (countWLetters[s[i + k]] > 0)
			{
				countWLetters[s[i + k]]--;
				count++;
			}

			else
			{
				break;
			}
		}
		if (count == wLen)
		{
			if (isFound)
			{
				std::cout << ", ";
			}
			isFound = true;
			std::cout << i;

		}
	}
	if (!isFound)
	{
		std::cout << "\"no anagrams\"" << "  ";
	}
}

int main()
{
	char S[MAX_SYMBOLS * 2]{};
	char W[MAX_SYMBOLS * 2]{};

	std::cin.getline(S, MAX_SYMBOLS * 2);
	std::cin.getline(W, MAX_SYMBOLS * 2);

	if (!(isValidInput(getLen(S)) && isValidInput(getLen(W))))
	{
		std::cout << "Incorrect input";
		return 0;
	}

	printOcurrances(S, W);
	return 0;
}

