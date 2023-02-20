/**
*
* Solution to homework assignment 3
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
const char SPACE = ' ';
int getStringLength(const char* string)
{
	int length = 0;
	while (string[length++] != '\0');
	return length - 1;
}

bool isValidLength(const char* string)
{
	return (getStringLength(string) <= MAX_SIZE);
}

void encryption(char* string, char key)
{
	int index = 0;
	while (string[index++] != '\0')
	{
		string[index - 1] ^= key;
	}
}
int main()
{
	char C;
	char S[3*MAX_SIZE]{};

	std::cin >> C;
	std::cin.ignore();
	std::cin.getline(S, MAX_SIZE);

	if (!isValidLength(S))
	{
		std::cout << "Incorrect input";
		return 0;
	}
	encryption(S, C);
	std::cout << S;
	return 0;
}
