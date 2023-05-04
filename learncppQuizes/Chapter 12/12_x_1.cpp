//Final Quiz #1 all a,b,c
#include <iostream>
#include <vector>
#include <array>

/*
* Use const if/when necessary.
a) A function named max() that takes two doubles and returns the larger of the two.
*/

double max(double a, double b)
{
	return (a > b ? a : b);
}

/*
b) A function named swap() that swaps two integers.
*/

void swap(int& x, int&  y)
{
	int temp{ x };
	x = y;
	y = temp;
	std::cout << x << "," << y;
}

/*
c) A function named getLargestElement() that takes a dynamically allocated array of integers 
and returns the largest number in such a way that the caller can change the value of the element returned (don’t forget the length parameter).
*/

using Vector = std::vector<int>;

int& getLargestElement(int* arr, int size)
{
	int smallest{ 0 };
	for (int i{ 0 }; i < size; ++i)
	{
		if (arr[i] > arr[smallest])
		{
			smallest = i;
		}
	}
	return arr[smallest];
}
// This loop returns a element -> can't modify index.
int& brbrb(int* arr, int size)
{
	int smallest{ 0 };
	for (int i{ 0 }; i < size; ++i)
	{
		if (arr[i] > smallest)
		{
			smallest = arr[i];
		}
	}
	return smallest;
}

int main()
{
	double a{ 1.3 };
	double b{ 1.7 };
	
	double bigger{ max(a,b) };

	int c{ 1 };
	int d{ 2 };

	int arr[] { 6,3,4,1,5 };

	int& biggest{ getLargestElement(arr, std::size(arr)) };

	int& bruh{ brbrb(arr, std::size(arr)) };
	
	std::cout << bruh << '\n';

	bruh = 1;

	for (int i : arr)
	{
		std::cout << i << ' ';
	}
	return 0;
}
