#pragma once

#include <iostream>
#include <iomanip>
using namespace std;
/*!
 * \file
 * \brief Definicja klasy Vector
 *
 * Klasa modeluje pojecie wektora o zadanych wymiarach.
 * Jej atrybutem jest pole zawierajace wspolrzedne wektora.
 * Przyjmuje sie, ze długosc podawana jest w jednostkach
 * niemianowanych.
 */

template <int Dimension>
class Vector {
/*!
* \brief Wspolrzedne wektora
*
* Pole zawiera wspolrzedne wektora Przyjmuje
* sie, ze jest ona podana w jednostkach niemianowanych.
*/
double coords[Dimension];

public:

double operator [ ] (int i) const { return coords[i]; }
double& operator [ ] (int i) { return coords[i]; }

Vector operator + (const Vector& V) const;

Vector operator - (const Vector& V) const;

Vector operator = (const Vector& V);

Vector operator * (double scale);

 /*!
* \brief Stala liczaca ilosc stworzonych wektorow
*
*/
inline static int created_amount=0;

 /*!
* \brief Stala liczaca ilosc istniejacych wektorow
*
*/
inline static int exist_amount=0;

 /*!
* \brief Konstruktor wektora
* Powieksza liczbe istniejacych i stworzonych wektorow, gdyz powstaje nowy wektor
*/
Vector() {exist_amount++; created_amount++;}
//Vector(const Vector& V) {exist_amount++; coords[Dimension]=V.coords[Dimension];}

 /*!
* \brief Destruktor wektora
* Zmniejsza liczbe istniejacych wektorow gdyz wektor jest usuwany
*/
~Vector() {exist_amount--;}
};

 /*!
* \brief Wczytuje wspolrzedne wektora
*
* Wczytuje wspolrzedne wektora
* Przyjmuje jedynie liczby rzeczywiste
* Powinny byc rozdzielone spacja
*/

template <int Dimension>
inline
istream& operator >> (istream & StrmIn, Vector<Dimension> &vector)
{
    for (int i=0; i<Dimension; ++i)
        StrmIn >> vector[i];

return StrmIn;
}


 /*!
* \brief Wypisuje wspolrzedne wektora
*
* Wypisuje wspolrzedne wektora
*/
template <int Dimension>
inline
ostream& operator << (ostream & StrmOut, const Vector<Dimension> &vector)
{
    for (int i=0; i<Dimension; ++i)
   {StrmOut <<  setw(16) << fixed << setprecision(16) << vector[i]<<" ";
   }

return StrmOut;
}

/*!
* \brief Dodaje wektory
*
* Dodaje do siebie dwa wektory
* \param[in] Vector1, Vector2 - dwa wektory, z czego do pierwszego dodajemy drugi
*  \param[out] Zsumowany wektor
*/
template <int Dimension>
Vector<Dimension> Vector<Dimension>::operator + (const Vector<Dimension>& V) const
{
    Vector<Dimension> v2;
    for (int i=0; i<Dimension; ++i)
        v2[i]=coords[i]+V[i];

return v2;
}
/*!
* \brief Odejmuje wektory
*
* Dodaje do siebie dwa wektory
* \param[in] Vector1, Vector2 - dwa wektory, z czego od pierwszego odejmujemy drugi
*  \param[out] Roznica wektorow
*/
template <int Dimension>
Vector<Dimension> Vector<Dimension>::operator - (const Vector<Dimension>& V) const
{
    Vector<Dimension> v2;
    for (int i=0; i<Dimension; ++i)
        v2[i]=coords[i]-V[i];


return v2;
}

/*!
* \brief Przypisuje wartosc wektorowi wartosc innego wektora
*
* Przypisuje jednemu wektorowi wartosc drugiego
*
* \param[in] Vector1, Vector2 - dwa wektory, z czego pierwszemu przypisujemy wartosc drugiego
*  \param[out] Przypisany wektor
*/
template <int Dimension>
Vector<Dimension> Vector<Dimension>::operator = (const Vector<Dimension>& V)
{
for (int i=0; i<Dimension; ++i)
    coords[i]=V[i];

return V;
}

/*!
* \brief Przypisuje wartosc wektorowi wartosc innego wektora
*
* Przypisuje jednemu wektorowi wartosc drugiego
*
* \param[in] scale - double, skala zmiany wektora
*  \param[out] Zmieniony wektor
*/
template <int Dimension>
Vector<Dimension> Vector<Dimension>::operator * (double scale)
{
Vector<Dimension> V;
for (int i=0; i<Dimension; ++i)
    V[i]=coords[i]*scale;

return V;
}
