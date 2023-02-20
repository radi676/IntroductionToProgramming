#include <iostream>
const int MIN_SIZE = 0;
const int MAX_SIZE = 255;

const int MAX_SIZE_BINARY = 8;

const int INITIAL_CAPACITY = 10;
const int RESIZE_FACTOR = 2;
const int TO_DEC_SIZE = 3;


bool isValidNum(int num)
{
	return num >= MIN_SIZE && num <= MAX_SIZE;
}

bool isValidInput(int* arr, int rowLen)
{
	int index = 0;
	int current = 0;
	int sum = 0;
	while (true)
	{
		current = arr[index++];

		if (current == 0 && arr[index] == 0)
		{
			break;
		}
		sum += current;
	}
	return sum % rowLen == 0;//тогава сме запълнили ред
}

void resize(int*& arr, int N) // просто разширяваш масива за да поставяш нови, щото е пълен вече
{
	int* newArr = new int[N * RESIZE_FACTOR];//ппц е 1.6 оптималното

	for (int i = 0; i < N; i++)
	{
		newArr[i] = arr[i];
	}

	arr = newArr;
}

void makeInBin(int* bin, int num)
{
	for (int i = MAX_SIZE_BINARY - 1; i >= 0; i--)
	{
		bin[i] = num % 2;
		num /= 2;
	}
}

void addToDec(int* dec, int* bin, int currentBinsRemaining)
{
	for (int i = 0; i < currentBinsRemaining / TO_DEC_SIZE; i++) //записваме толкова числа, колкото тройни позиции можем да отделим
	{
		dec[i] = bin[i * 3] * 4 + bin[i * 3 + 1] * 2 + bin[i * 3 + 2];//понеже са 3 бита, затова са три събираеми и във всяка клетка се извърпва операция
	}
	//горе сме взели толкова 3ки, колкото можем да отделим, но има и остатък
	for (int i = 0; i < currentBinsRemaining % TO_DEC_SIZE; i++)//или 0 или 1 или 2 може да е остатъка
	{
		bin[i] = bin[i + (currentBinsRemaining / TO_DEC_SIZE) * TO_DEC_SIZE];//дали остатъка е на 0, 1 или 2 позиция в клетката
	}
}

bool checkConsequativeZeros(int* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i + 1] != 0)
		{
			i++;
		}
		else if (arr[i] == 0 && arr[i + 1] == 0)
		{
			return true;
		}
	}

	return false;
}

int* inputArray()
{
	int capacity = INITIAL_CAPACITY;
	int* arr = new int[capacity];//този масив пази числата за принтиране , от 0 до 7

	int currentIndex = 0;

	int currentNum;//текъщоуо число

	int currentBins[MAX_SIZE_BINARY * 2];//като прочетем число директно го превръщаме 
	//после вадим числата от тоя масив и ги представяме по тройки в арр масива пъвривя
	int currentBinsRemaining = 0;//отговаря за останалите битове, които не сме изкарали в тройка

	while (true)
	{
		std::cin >> currentNum;
		makeInBin(currentBins + currentBinsRemaining, currentNum);//указателят ще сочи точно там, където тр да почнем да записваме следващото число 
		currentBinsRemaining += MAX_SIZE_BINARY;//добавяме още 8 бита, щото сме добавили току що числото

		if (currentIndex + currentBinsRemaining / TO_DEC_SIZE >= capacity)//ако се напълни, го рисзйзва
		{
			resize(arr, currentIndex);
			capacity = currentIndex * RESIZE_FACTOR;//тука реално го увеличаваме
		}

		addToDec(arr + currentIndex, currentBins, currentBinsRemaining);

		int oldIndex = currentIndex - 1 < 0 ? 0 : currentIndex - 1;//колко е било преди да сме го адд ту декнали
		currentIndex += currentBinsRemaining / TO_DEC_SIZE;//добавям му на колко позиции ще пишем след последното
		currentBinsRemaining %= TO_DEC_SIZE;

		if (checkConsequativeZeros(arr + oldIndex, currentIndex - oldIndex))//ако има две последователни нули
		{
			break;
		}
	}

	return arr;
}

void print(int* arr, int rowLength)
{
	int row = 0;
	int index = 0;
	int current = 0;
	bool isDot = false;
	while (true)
	{
		if (current == 0)
		{
			current = arr[index++];
			if (current == 0 && arr[index] == 0)
			{
				break;
			}
			isDot = !isDot;
			if (current == 0)
			{
				continue;
			}
		}

		if (isDot)
		{
			std::cout << ".";
		}
		else
		{
			std::cout << "#";
		}

		current--;
		row++;

		if (row == rowLength)//минава на нов ред
		{
			std::cout << std::endl;
			row = 0;
		}
	}
}

int main()
{
	int width = 0;
	std::cin >> width;
	int* sequence = inputArray();
	if (!isValidInput(sequence, width))
	{
		std::cout << "Invalid input";
		delete[]sequence;
		return 0;
	}
	print(sequence, width);
	delete[] sequence;

	return 0;
}
