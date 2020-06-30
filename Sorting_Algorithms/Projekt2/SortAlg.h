#pragma once
#include <iostream>
#include <algorithm>
#include "SortingTools.h"
using namespace std;

//QUICKSORT
template <typename T>
void quicksort(T Array[], int start, int end)
{
	if (start >= end) return;

	int split = Partition(Array, start, end);
	quicksort(Array, start, split - 1);
	quicksort(Array, split + 1, end);
}


// MERGESORT
template <typename T>
void mergesort(T Array[], T Temp[], int start, int end)
{
	if (start != end)
	{
		int mid = (start + end) / 2;

		mergesort(Array, Temp, start, mid);
		mergesort(Array, Temp, mid + 1, end);
		Merge(Array, Temp, start, mid, end);
	}
}


// INSERTIONSORT
template <typename T>
void insertionsort(T Array[], int start, int end)
{
	int j, temp;
	for (int i = start + 1; i <= end; i++)
	{
		j = i;
		temp = Array[i];
		while (j > start && Array[j - 1] > temp)
		{
			Array[j] = Array[j - 1];
			j--;
		}
		Array[j] = temp;
	}
}


//HEAPSORT
template <typename T>
void heapsort(T* Array, int start, int end)
{
	int Size = end - start + 1;
	T* temp = new T[Size];
	for (int i = 0; i <= end - start; ++i)
	{
		temp[i] = Array[start + i];
	}
	for (int i = (Size - 1) / 2; i >= 0; --i)
	{
		Heapify(temp, Size, i);
	}
	for (int i = Size - 1; i >= 0; --i)
	{
		swap(temp[0], temp[i]);
		Heapify(temp, i, 0);
	}
	for (int i = 0; i <= (end - start); ++i)
	{
		Array[start + i] = temp[i];
	}
	delete[] temp;
}



//INTROSORT
template <typename T>
void introsort(T Array[], int* start, int* end, int maxdepth)
{
	if ((end - start) < 16) 
	{
		insertionsort(Array, start - Array, end - Array);
	}
	else if (maxdepth == 0) 
	{
		heapsort(Array, start-Array, end -Array);
	}
	else
	{
		int split = randPartition(Array, start - Array, end - Array);
		introsort(Array, start, Array + split - 1, maxdepth - 1);
		introsort(Array, Array + split + 1, end, maxdepth - 1);
	}
}
