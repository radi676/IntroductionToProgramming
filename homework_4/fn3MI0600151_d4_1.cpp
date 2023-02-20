/**
*
* Solution to homework assignment 4
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
const int UPPER_BOUND = 50;
const int LOWER_BOUND = 3;
const int MAX_SIZE_STRINGS = 1024;
const char NUM_LOWER_BOUND = '0';
const char NUM_UPPER_BOUND = '9';
const char DASH = '-';
const char POINT = '.';
const char COMMA = ',';
const char CHAR_TO_DIGIT = '0';


bool isValidInput(int inputNum)
{
	return inputNum >= LOWER_BOUND && inputNum <= UPPER_BOUND;
}

char** initializeMatrix(int rows, int cols)
{
	char** matrix = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new char[1024];
	}
	return matrix;
}

void inputData(char** array, int rows, int countMaxSymbols)
{
	for (int r = 0; r < rows; r++)
	{
		std::cin.getline(array[r], countMaxSymbols);
	}
}

void freeMatrix(char** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void swap(double& first, double& second)
{
	double temp = first;
	first = second;
	second = temp;
}

void sort(double* array, int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < count; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		swap(array[i], array[minIndex]);
	}
}

bool isDigit(char symbol)
{
	return symbol >= NUM_LOWER_BOUND && symbol <= NUM_UPPER_BOUND;
}

bool isValidDouble(const char* string)
{
	int indx = 0;
	if ((string[indx] == DASH && isDigit(string[indx + 1]))
		|| (isDigit(string[indx])))
	{
		indx++;
	}
	else
	{
		return false;
	}

	bool foundPointOrComma = false;
	while (string[indx] != '\0')
	{
		if (string[indx] == POINT || string[indx] == COMMA)
		{
			if (foundPointOrComma)//ако има повече от една точка или минус
			{
				return false;
			}

			foundPointOrComma = true;
		}
		else if (!isDigit(string[indx]))
		{
			return false;
		}
		indx++;
	}
	return true;
}

double toDouble(char* string)
{
	int indx = 0;
	int isNegative = 1;
	if (string[indx] == DASH)
	{
		indx++;
		isNegative = -1;
	}

	double num = 0;
	while (string[indx] != POINT && string[indx] != COMMA && string[indx] != '\0')
	{
		num = num * 10 + string[indx] - CHAR_TO_DIGIT;
		indx++;
	}

	if (string[indx] == '\0')
	{
		return num * isNegative;
	}

	indx++;
	double decPower = 0.1;
	while (string[indx] != '\0')
	{
		num += (string[indx] - CHAR_TO_DIGIT) * decPower;
		decPower /= 10;
		indx++;
	}

	return num * isNegative;
}

void printSorted(char** strings, int len)
{
	double* array = new double[len];
	int indxDoubleArr = 0;
	for (int i = 0; i < len; i++)
	{
		if (isValidDouble(strings[i]))
		{
			array[indxDoubleArr++] = toDouble(strings[i]);
		}
	}

	if (indxDoubleArr == 0)
	{
		std::cout << "no valid numbers";
	}

	sort(array, indxDoubleArr);
	for (int i = 0; i < indxDoubleArr; i++)
	{
		std::cout << array[i] << " ";
	}
	delete[]array;
}

int main()
{
	int inputNum;
	std::cin >> inputNum;
	std::cin.ignore();
	if (!isValidInput(inputNum))
	{
		std::cout << "Incorrect input";
		return 0;
	}
	char** strings = initializeMatrix(inputNum, MAX_SIZE_STRINGS);
	inputData(strings, inputNum, MAX_SIZE_STRINGS);
	printSorted(strings, inputNum);
	freeMatrix(strings, inputNum, MAX_SIZE_STRINGS);
	return 0;
}

