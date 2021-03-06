// PRNG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <string>
#include <algorithm>

int get_int(const std::string&, const std::string&, const int, const int);
int* arrayInitialization(const int&, const int, const int);
void getArray(int*, int);

void oddArray(int*, int);		// #1
int negativeSum(int*, int);		// #2
int moduleMax(int*, int);		// #3
void bubbleSort(int*, int);		// #4
void nodArray(int* a, int lenght); // nod 
int nod(int, int);


int main()
{
	int S = get_int("Enter size of array (from 1 to 50)", "", 0, 50);

	int* arr = NULL;
	
	nodArray(arr, S);
     return 0;
}

int get_int(const std::string& message, const std::string& err = "", const int min = INT_MIN, const int max = INT_MAX)
{
	int temp;
	while (std::cout << message << " : " &&
		(!(std::cin >> temp) || temp < min || temp > max))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "Ошибка ввода! " << err << std::endl;
	}
	return temp;
}

int* arrayInitialization(const int& lenght, const int min = INT_MIN, const int max = INT_MAX)
{// initializing array 
	std::random_device rd;
	std::mt19937 random_generator(rd());
	std::uniform_int_distribution<int> range(min, max);

	int* array = new int[lenght];

	for(size_t i = 0; i < lenght; i++)
		array[i] = range(random_generator);

	return array;
}

void oddArray(int* a, int lenght)
{// #1
	a = arrayInitialization(lenght, 0, 50);

	for (size_t i = 0; i < lenght; i++)
		a[i] = a[i] * 2 + 1;
}

int negativeSum(int* a, int lenght)
{// #2
	a = arrayInitialization(lenght, -100, 100);
	int sum = 0;

	for (size_t i = 0; i < lenght; i++)
	{
		if (a[i] < 0)
			sum += a[i];
	}
	return sum;
}

int moduleMax(int* a, int lenght)
{// #3
	a = arrayInitialization(lenght, -100, 100);
	
	int maxElem = 0;
	int result = 0;

	for (size_t i = 0; i < lenght; i++)
	{
		if (a[i] > maxElem)
			maxElem = a[i];
	}

	for (size_t i = 0; i < lenght; i++)
	{
		if (abs(a[i]) > maxElem)
			result++;
	}
	return result;
}

void bubbleSort(int* a, int lenght)
{// #4
	a = arrayInitialization(lenght, -100, 100);

	int temp = 0;
	getArray(a, lenght);
	for (size_t i = 0; i < lenght - 1; i++)
	{
		bool isChange = false;
		for (size_t j = 0; j < lenght - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				isChange = true;
			}
		}
		if (!isChange)
			break;
	}
	getArray(a, lenght);
}

void getArray(int* a, int lenght)
{
	for (size_t i = 0; i < lenght; i++)
		std::cout << a[i] << std::endl;
	std::cout << std::endl;
}

void nodArray(int* a, int lenght)
{
	a = new int[lenght];
	int* b = arrayInitialization(lenght, -100, 100);
	int* c = arrayInitialization(lenght, -100, 100);
	for (size_t i = 0; i < lenght; i++)
	{
		a[i] = nod(b[i], c[i]);
	}
	getArray(b, lenght);
	std::cout << std::endl;
	getArray(c, lenght);
	std::cout << std::endl;
	getArray(a, lenght);
}


int nod(int a, int b) {
	if (b == 0)
		return abs(a);
	else
	return nod(b, a % b);
}