/**
*
* Solution to homework assignment 1
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

const int LOWER_BOUND = 1;
const int UPPER_BOUND = 1000000;
const int SQUARE_DIGIT_LOWER_BOUND = 16;
const int SQUARE_DIGIT_UPPER_BOUND = 81;

int main()
{
	long long num;
	long long reversedNum = 0;
	std::cin >> num;

	if (num < LOWER_BOUND || num > UPPER_BOUND) {
		std::cout << "Incorrect input" << std::endl;
		return 0;
	}

	while (num != 0) {
		int lastDigitSquare = (num % 10) * (num % 10);
		num /= 10;

		if (lastDigitSquare >= SQUARE_DIGIT_LOWER_BOUND && lastDigitSquare <= SQUARE_DIGIT_UPPER_BOUND) {
			reversedNum = reversedNum * 100 + (lastDigitSquare % 10) * 10 + lastDigitSquare / 10;
		}
		else
		{
			reversedNum = reversedNum * 10 + lastDigitSquare;
		}
	}

	std::cout << reversedNum + 1;
	return 0;
}
