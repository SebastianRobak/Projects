// Projekt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SortAlg.h"
#include "SortingTools.h"
#include "stdafx.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>


#define EXAMPLE_SIZE 10
#define PERCENTAGE 0
#define EXAMPLE_MAX 100
#define EXAMPLE_NUM 2
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	ofstream results;
	results.open("results.txt");
	double totalTime = 0;
	char sorting_choice;
	bool end = true;
	int size[5] = { 10000, 50000, 100000,500000, 1000000 };
	double percent[8] = { 0, 25, 50, 75, 95, 99, 99.7, 100 };
	int* Array;
	int* Temp;
	int lastSorted;
	int maxdepth;
	const int Experiments = 100;
	while (end)
	{
		cout << "Please, enter the correct letter to choose which algorythm you want to use\n" << "q - quicksort\n" << "m - mergesort\n" << "i - introsort\n" << "a - quicksort example\n" << "b - mergesort example\n" << "c - introsort example\n" << "e - end\n";
		cin >> sorting_choice;
		switch (sorting_choice)
		{
		case 'q':
		{
			results << "Sortowanie szybkie\n";
			for (int j = 0; j < 1; ++j)
			{
				results << "Sredni czas sortowania dla tablicy o rozmiarze " << size[j] << endl;
				int arr[size[j]];
				Array = new int[size[j]];
				for (int n = 0; n < 8; ++n)
				{

					totalTime = 0;
					for (int i = 0; i < Experiments; ++i)
					{
						for (int z = 0; z < size[j]; ++z)
							Array[z] = rand() % INT_MAX;
						if (percent[n] != 0) {
							lastSorted = static_cast<int>(size[j] * percent[n] / 100);
							if (percent[n] != 100) sort(Array, Array + lastSorted, less<int>());// od najm do najw
							else sort(Array, Array + lastSorted, greater<int>()); //od najw do najm
						}

						auto start = std::chrono::system_clock::now();
						quicksort<int>(Array, 0, size[j] - 1);

						auto end = std::chrono::system_clock::now();
						std::chrono::duration<double, milli> diff = end - start;
						double durationTime = diff.count();
						totalTime += durationTime;
						//if (!(Sorted<int>(Array, size[j]))) cout << "Nieposortowane\n";
					}
					results << "Dla " << percent[n] << "% posortowania: " << totalTime / Experiments << " milliseconds" << endl;
				}
				cout << j;
				delete[] Array;
			}
			cout << "Testing completed\n";
		}
		break;
		case 'm':
		{
			results << "Sortowanie szybkie\n";
			for (int j = 0; j < 1; ++j)
			{
				results << "Sredni czas sortowania dla tablicy o rozmiarze " << size[j] << endl;

				Array = new int[size[j]];
				Temp = new int[size[j]];
				for (int n = 0; n < 8; ++n)
				{

					//Przygotowanie tablic o rozmiarze n:
					//•wszystkie elementy tablicy losowe,
					//• 25%, 50%, 75%, 95%, 99%, 99,7% pocz¹tkowych elementów tablicy jest ju¿ posortowanych,
					//• wszystkie elementy tablicy ju¿ posortowane ale w odwrotnej kolejnoœci.
					//Mozna uzyc metody std::generate do zapelnienia swojej tablicy wejsciowej.

					//Wykonanie eksperymentu nbOfExperiments razy dla tablic o rozmiarze n
					totalTime = 0;
					for (int i = 0; i < Experiments; ++i)
					{
						for (int z = 0; z < size[j]; ++z)
							Temp[z] = Array[z] = rand() % INT_MAX;
						if (percent[n] != 0) {
							lastSorted = static_cast<int>(size[j] * percent[n] / 100);
							if (percent[n] != 100) sort(Array, Array + lastSorted, less<int>());// od najm do najw
							else sort(Array, Array + lastSorted, greater<int>()); //od najw do najm
						}
						// Mierzenie czasu trwania jednego eksperymentu
						//Poni¿szy fragment wykonywany jest wielokrotnie
						//osobno dla ka¿dej kombinacji algorytmu i tablicy wejœciowej
						auto start = std::chrono::system_clock::now();
						mergesort<int>(Array, Temp, 0, size[j] - 1);
						//pojedyncze wykonanie jednego algorytmu sortowania dla jednej tablicy
						//swoje implementacje sortowania na kopii tablic wejœciowych
						auto end = std::chrono::system_clock::now();
						std::chrono::duration<double, milli> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
						double durationTime = diff.count(); // zmierzony czas zapisaæ do pliku lub zagregowaæ, zapisaæ liczbê badanych elementów
						totalTime += durationTime;
						//Sprawdzenie poprawnoœci dzia³ania algorytmu, juz po pomiarze czasu
						//checkIfCorrect(tablica_nieposortowana, tablica_posortowana_algorytmem);
						//if (!(Sorted<int>(Array, size[j]))) cout << "Nieposortowane\n";
					}
					results << "Dla " << percent[n] << "% posortowania: " << totalTime / Experiments << " milliseconds" << endl;
				}
				cout << j;
				delete[] Array;
				delete[] Temp;
			}
			cout << "Testing completed\n";
		}
		break;
		case 'i':
		{//Badanie dla ka¿dego rozmiaru tablicy n
			results << "Sortowanie szybkie\n";
			for (int j = 0; j < 1; ++j)
			{
				results << "Sredni czas sortowania dla tablicy o rozmiarze " << size[j] << endl;

				Array = new int[size[j]];
				for (int n = 0; n < 8; ++n)
				{

					//Przygotowanie tablic o rozmiarze n:
					//•wszystkie elementy tablicy losowe,
					//• 25%, 50%, 75%, 95%, 99%, 99,7% pocz¹tkowych elementów tablicy jest ju¿ posortowanych,
					//• wszystkie elementy tablicy ju¿ posortowane ale w odwrotnej kolejnoœci.
					//Mozna uzyc metody std::generate do zapelnienia swojej tablicy wejsciowej.

					//Wykonanie eksperymentu nbOfExperiments razy dla tablic o rozmiarze n
					totalTime = 0;
					for (int i = 0; i < Experiments; ++i)
					{
						for (int z = 0; z < size[j]; ++z)
							Array[z] = rand() % INT_MAX;
						if (percent[n] != 0) {
							lastSorted = static_cast<int>(size[j] * percent[n] / 100);
							if (percent[n] != 100) sort(Array, Array + lastSorted, less<int>());// od najm do najw
							else sort(Array, Array + lastSorted, greater<int>()); //od najw do najm
						}
						// Mierzenie czasu trwania jednego eksperymentu
						//Poni¿szy fragment wykonywany jest wielokrotnie
						//osobno dla ka¿dej kombinacji algorytmu i tablicy wejœciowej
						maxdepth = static_cast<int>(log(EXAMPLE_SIZE) * 2);
						auto start = std::chrono::system_clock::now();
						//introsort<int>(Array, Array, Array + size[j] - 1, maxdepth);
						//pojedyncze wykonanie jednego algorytmu sortowania dla jednej tablicy
						//swoje implementacje sortowania na kopii tablic wejœciowych
						auto end = std::chrono::system_clock::now();
						std::chrono::duration<double, milli> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
						double durationTime = diff.count(); // zmierzony czas zapisaæ do pliku lub zagregowaæ, zapisaæ liczbê badanych elementów
						totalTime += durationTime;
						//Sprawdzenie poprawnoœci dzia³ania algorytmu, juz po pomiarze czasu
						//checkIfCorrect(tablica_nieposortowana, tablica_posortowana_algorytmem);
						//if (!(Sorted<int>(Array, size[j]))) cout << "Nieposortowane\n";
					}
					results << "Dla " << percent[n] << "% posortowania: " << totalTime / Experiments << " milliseconds" << endl;
				}
				cout << j;
				delete[] Array;
			}
			cout << "Testing completed\n";
		}
		break;
		case 'a':
		{
			
			Array = new int[EXAMPLE_SIZE];
			totalTime = 0;
			for (int j = 0; j < EXAMPLE_NUM; ++j)
			{
				for (int i = 0; i < EXAMPLE_SIZE; ++i)
					Array[i] = rand() % EXAMPLE_MAX;
				cout << "Nieposortowana tablica:\n";
				for (int i = 0; i < EXAMPLE_SIZE; i++)
					cout << Array[i] << " ";
				cout << endl << endl;
				if (PERCENTAGE != 0) {
					lastSorted = EXAMPLE_SIZE * PERCENTAGE / 100;
					if (PERCENTAGE != 100) sort(Array, Array + lastSorted, less<int>());// od najm do najw
					else sort(Array, Array + lastSorted, greater<int>()); //od najw do najm
				}
				/*cout << "Nieposortowana tablica po wstepnym sortowaniu:\n";
				for (int i = 0; i < EXAMPLE_SIZE; i++)
					cout << Array[i] << " ";
				cout << endl << endl;*/
				auto start = std::chrono::system_clock::now();
				quicksort<int>(Array, 0, EXAMPLE_SIZE - 1);
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double, milli> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
				double durationTime = diff.count(); // zmierzony czas zapisaæ do pliku lub zagregowaæ, zapisaæ liczbê badanych elementów
				totalTime += durationTime;
				if (Sorted<int>(Array, EXAMPLE_SIZE))
				{
					cout << "Posortowana tablica:\n";
					for (int i = 0; i < EXAMPLE_SIZE; i++)
						cout << Array[i] << " ";
					cout << endl << endl;
				}
			}
			cout << "Dla " << PERCENTAGE << "% posortowania: " << totalTime / EXAMPLE_NUM << endl;
			delete[] Array;
		}
		break;
		case 'b':
		{
			Array = new int[EXAMPLE_SIZE];
			Temp = new int[EXAMPLE_SIZE];
			totalTime = 0;
			for (int j = 0; j < EXAMPLE_NUM; ++j)
			{
				for (int i = 0; i < EXAMPLE_SIZE; ++i)
					Temp[i] = Array[i] = rand() % EXAMPLE_MAX;
				cout << "Nieposortowana tablica:\n";
				for (int i = 0; i < EXAMPLE_SIZE; i++)
					cout << Array[i] << " ";
				cout << endl << endl;
				if (PERCENTAGE != 0) {
					lastSorted = EXAMPLE_SIZE * PERCENTAGE / 100;
					if (PERCENTAGE != 100) sort(Array, Array + lastSorted, less<int>());// od najm do najw
					else sort(Array, Array + lastSorted, greater<int>()); //od najw do najm
				}
				/*cout << "Nieposortowana tablica po wstepnym sortowaniu:\n";
				for (int i = 0; i < EXAMPLE_SIZE; i++)
					cout << Array[i] << " ";
				cout << endl << endl;*/
				auto start = std::chrono::system_clock::now();
				mergesort<int>(Array, Temp, 0, EXAMPLE_SIZE - 1);
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double, milli> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
				double durationTime = diff.count(); // zmierzony czas zapisaæ do pliku lub zagregowaæ, zapisaæ liczbê badanych elementów
				totalTime += durationTime;

				if (Sorted<int>(Array, EXAMPLE_SIZE))
				{
					cout << "Posortowana tablica:\n";
					for (int i = 0; i < EXAMPLE_SIZE; i++)
						cout << Array[i] << " ";
					cout << endl << endl;
				}
			}
			cout << "Dla " << PERCENTAGE << "% posortowania: " << totalTime / EXAMPLE_NUM << endl;
			delete[] Array;
			delete[] Temp;
			
		}
		break;
		case 'c':
		{
			Array = new int[EXAMPLE_SIZE];
			totalTime = 0;
			for (int j = 0; j < EXAMPLE_NUM; ++j)
			{
				for (int i = 0; i < EXAMPLE_SIZE; ++i)
					Array[i] = rand() % EXAMPLE_MAX;
				cout << "Nieposortowana tablica:\n";
				for (int i = 0; i < EXAMPLE_SIZE; i++)
					cout << Array[i] << " ";
				cout << endl << endl;
				if (PERCENTAGE != 0) {
					lastSorted = EXAMPLE_SIZE * PERCENTAGE / 100;
					if (PERCENTAGE != 100) sort(Array, Array + lastSorted, less<int>());// od najm do najw
					else sort(Array, Array + lastSorted, greater<int>()); //od najw do najm
				}
				/*cout << "Nieposortowana tablica po wstepnym sortowaniu:\n";
				for (int i = 0; i < EXAMPLE_SIZE; i++)
					cout << Array[i] << " ";
				cout << endl << endl;*/
				auto start = std::chrono::system_clock::now();
				maxdepth = static_cast<int>(log(EXAMPLE_SIZE) * 2);
				introsort<int>(Array, Array, Array + (EXAMPLE_SIZE - 1), maxdepth);
				//introsort<int>(Array, 0, (EXAMPLE_SIZE - 1), maxdepth);
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double, milli> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
				double durationTime = diff.count(); // zmierzony czas zapisaæ do pliku lub zagregowaæ, zapisaæ liczbê badanych elementów
				totalTime += durationTime;
				if (Sorted<int>(Array, EXAMPLE_SIZE))
				{
					cout << "Posortowana tablica:\n";
					for (int i = 0; i < EXAMPLE_SIZE; i++)
						cout << Array[i] << " ";
					cout << endl << endl;
				}
			}
			cout << "Dla " << PERCENTAGE << "% posortowania: " << totalTime / EXAMPLE_NUM << endl;
			delete[] Array;
			
		}
		break;
		case 'e':
		{
			end = false;
		}
		break;
		default:
			cout << "Please choose correct letter\n";
		}
	}
	results.close();
	return 0;
}

