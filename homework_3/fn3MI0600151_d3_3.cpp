#include<iostream>
const int HOUR_LENGTH = 4;


bool isValidInput(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (!((arr[i] % 100 >= 0 && arr[i] % 100 <= 59) && (arr[i] / 100 >= 0 && arr[i] / 100 <= 23)))
		{
			return false;
		}
	}
	return true;
}
int* readHours(int N)
{
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}

	return arr;
}

void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

void sort(int* arr, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			swap(arr[i], arr[minIndex]);
		}
	}
}

int** initializeMatrix(int N)
{
	int** arr = new int* [N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = 0;
		}
	}

	return arr;
}

void freeMatrix(int** arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
}

void printWithLeadingZeros(int num, int CELLS)
{
	int numLength = 0;
	int numCopy = num;
	while (numCopy > 0)
	{
		numCopy /= 10;
		numLength++;
	}

	for (int i = 0; i < CELLS - numLength; i++
	{
		std::cout << "0";
	}

	if (num != 0)
	{
		std::cout << num;
	}
}

void printRushHours(const int* arrivals, const int* departures, int N)
{
	int maxRunwaysRequired = 0;
	int currentRunwaysRequired = 0;
	int** rushHourStarts = initializeMatrix(N + 1);
	int** rushHourEnds = initializeMatrix(N + 1);

	int arriveIndex = 0;
	int departIndex = 0;

	int currentTime = 0;

	while (arriveIndex < N)
	{
     	currentTime = arrivals[arriveIndex];
		currentRunwaysRequired++;

		while (departIndex < N && departures[departIndex] <= currentTime)
		{
			currentRunwaysRequired--;
			departIndex++;
		}

		if (currentRunwaysRequired >= maxRunwaysRequired)
		{
			maxRunwaysRequired = currentRunwaysRequired;
			int index = ++rushHourStarts[maxRunwaysRequired][0]; 

			rushHourStarts[maxRunwaysRequired][index] = arrivals[arriveIndex];
			rushHourEnds[maxRunwaysRequired][index] = departures[departIndex];
		}

		arriveIndex++;
	}

	std::cout << maxRunwaysRequired << std::endl;

	for (int i = 1; i < rushHourStarts[maxRunwaysRequired][0] + 1; i++)
	{
		printWithLeadingZeros(rushHourStarts[maxRunwaysRequired][i], HOUR_LENGTH);
		std::cout << "-";
		printWithLeadingZeros(rushHourEnds[maxRunwaysRequired][i], HOUR_LENGTH);
		std::cout << std::endl;
	}
}

int main()
{
	int N;
	std::cin >> N;

	int* arrivals = readHours(N);
	int* departures = readHours(N);

	sort(arrivals, N);
	sort(departures, N);

	printRushHours(arrivals, departures, N);
}
