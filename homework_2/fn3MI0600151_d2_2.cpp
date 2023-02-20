/**
*
* Solution to homework assignment 2
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
double const EPSILON = 1e-6;
double getAbsoluteValue(double x)
{
	return x < 0 ? -x : x;
}


bool equalsDoubles(double x, double y)
{
	return abs(x - y) < EPSILON;
}

bool isInRectangle(double lowerLeftX, double lowerLeftY, double upperRightX, double upperRightY, double x, double y)
{
	return((x > lowerLeftX && x < upperRightX)
		&& (y > lowerLeftY && y < upperRightY));
}

bool isOnRectangleBorder(double lowerLeftX, double lowerLeftY, double upperRightX, double upperRightY, double x, double y)
{
	return(equalsDoubles(x, lowerLeftX) || equalsDoubles(x, upperRightX))
		&& (equalsDoubles(y, lowerLeftY) || equalsDoubles(y, upperRightY));
}

bool isOnCircleBorder(double centerX, double centerY, double radius, double x, double y)
{
	return equalsDoubles((centerX - x) * (centerX - x) + (centerY - y) * (centerY - y), radius * radius);
}

bool isInCircle(double centerX, double centerY, double radius, double x, double y)
{
	return (centerX - x) * (centerX - x) + (centerY - y) * (centerY - y) < radius * radius;
}

int main()
{
	double x, y;
	std::cin >> x;
	std::cin >> y;
	if (!isInRectangle(-10, -10, 10, 10, x, y))
	{
		if (isOnRectangleBorder(-10, -10, 10, 10, x, y))
		{
			std::cout << "Border";
		}
		else
		{
			std::cout << "Miss";
		}
		return 0;
	}

	if (!isInCircle(0, 0, 10, x, y))
	{
		if (isOnCircleBorder(0, 0, 10, x, y))
		{
			std::cout << "Border";
		}
		else
		{
			std::cout << "Background";
		}
		return 0;
	}

	if (isInCircle(-4, 4, 2, x, y) || isInCircle(4, 4, 2, x, y))
	{
		std::cout << "Eye";
	}
	else if (isInCircle(0, 0, 1, x, y))
	{
		std::cout << "Nose";
	}
	else if (isInRectangle(-5, -6, 5, -4, x, y))
	{
		std::cout << "Mouth";
	}
	else if (isOnCircleBorder(-4, 4, 2, x, y) ||
		isOnCircleBorder(4, 4, 2, x, y) ||
		isOnCircleBorder(0, 0, 1, x, y) ||
		isOnRectangleBorder(-5, -6, 5, -4, x, y))
	{
		std::cout << "Border";
	}
	else
	{
		std::cout << "Face";
	}
}

