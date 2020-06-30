#pragma once
#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

// Function to split array, using split element thats at the end
template <typename T>
int Partition(T Array[], int start, int end)
{
	int split = Array[end];
	int Isplit = start;

	for (int i = start; i < end; ++i)
	{
		if (Array[i] <= split)
		{
			swap(Array[i], Array[Isplit]);
			++Isplit;
		}
	}
	swap(Array[Isplit], Array[end]);
	return Isplit;
}

// Function that randomly chooses splitting element and then calls Partition function
template <typename T>
int randPartition(T Array[], int start, int end)
{
	int split = rand() % (end - start + 1) + start;
	swap(Array[split], Array[end]);
	return Partition(Array, start, end);
}

// Function to merge two sorted arrays
template <typename T>
void Merge(T Array[], int Temp[], int start, int mid, int end)
{
	int k = start, i = start, j = mid + 1;

	while (i <= mid && j <= end)
	{
		if (Array[i] <= Array[j])
			Temp[k++] = Array[i++];
		else
			Temp[k++] = Array[j++];
	}

	while (i <= mid)
		Temp[k++] = Array[i++];

	for (int i = start; i <= end; i++)
		Array[i] = Temp[i];
}

// Function that checks if array is sorted (from smallest to biggest number)
template <typename T>
int Sorted(T Array[], int length)
{
	int previous = Array[0];
	for (int i = 1; i < length; ++i) {
		if (previous > Array[i]) {
			cout << "Elements are not sorted\n";
			return 0;
		}
		previous = Array[i];
	}
	return 1;
}

//Function to heapify/sort array
template <typename T>
void Heapify(T* Array, int Size, int Root)
{
	int biggest = Root, lefty = 2 * Root, righty = 2 * Root + 1;
	if (lefty < Size && Array[lefty] > Array[biggest])	biggest = lefty;
	if (righty < Size && Array[righty] > Array[biggest]) biggest = righty;
	if (biggest != Root)
	{
		swap(Array[Root], Array[biggest]);
		Heapify(Array, Size, biggest);
	}
}