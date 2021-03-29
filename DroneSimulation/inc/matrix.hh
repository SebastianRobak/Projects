#pragma once
#include "vector.hh"

#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.14159265
using namespace std;


/*!
 * \file
 * \brief Definicja klasy Matrix
 *
 * Klasa modeluje pojecie macierzy o zadanych wymiarach.
 * Jej atrybutem jest pole zawierajace macierz o zadanych wymiarach NxN.
 * Przyjmuje sie, ze długosc podawana jest w jednostkach
 * niemianowanych.
 */


template <int Dimension>
class Matrix{
/*!
* \brief Macierz
*
* Pole zawiera pola macierzy.
* Przyjmuje sie, ze jest ona podana w jednostkach niemianowanych.
*/
    double array[Dimension][Dimension];


public:
    double operator() (int Ver, int Col) const { return array[Ver][Col]; }
    double& operator() (int Ver, int Col) { return array[Ver][Col]; }

    Vector<Dimension> operator * (const Vector<Dimension>& v) const;
    Matrix<Dimension> operator * (Matrix<Dimension> M2) const;
    void rotation(double angle, char axis);
};



 /*!
* \brief Wypisuje macierz
*
* Wypisuje pola macierzy
*/
template <int Dimension>
inline
ostream& operator << (ostream & StrmOut, const Matrix<Dimension> &matrix)
{
for (int i=0; i<Dimension; ++i)
    {for (int j=0; j<Dimension; ++j)
        {StrmOut << setw(16) << fixed << setprecision(16) << matrix(i,j)<< " ";}
		StrmOut<<endl;
    }
StrmOut << endl;
return StrmOut;
}

/*!
* \brief Mnozy wektor z macierza
*
* Mnozy wektor z macierza
* \param[in] Vector, Matrix - vector ktory bedziemy mnozyc i macierz
* \param[out] Vector - wynik mnozenia
*/
template <int Dimension>
Vector<Dimension> Matrix<Dimension>::operator * (const Vector<Dimension>& v) const
{
Vector<Dimension> v2;
Vector<Dimension> vect0;

for (int i=0; i<Dimension; ++i)
    vect0[i]=0;

v2=vect0;

for (int i=0; i<Dimension; ++i)
    for (int j=0; j<Dimension; ++j)
        v2[i]+=array[i][j]*v[j];

return v2;
}

/*!
* \brief Mnozy wektor z macierza
*
* Mnozy wektor z macierza
* \param[in] Matrix, Matrix2 - macierze ktore bedziemy wymnazac
* \param[out] Vector - wynik mnozenia
*/
template <int Dimension>
Matrix<Dimension> Matrix<Dimension>::operator * (Matrix<Dimension> M2) const
{
Matrix<Dimension> newM;

for (int i=0; i<Dimension; ++i)
    for (int m=0; m<Dimension; ++m)
        {newM(i,m)=0;
        for (int j=0; j<Dimension; ++j)
            newM(i,m)+=this->array[i][j]*M2(j,m);
        }

return newM;
}

/*!
* \brief Tworzy macierz obrotu
*
* Tworzy macierz ktora w swoich polach
* przechowuje wartosci cos i sin danego
* kata potrzebne do obrotu
* \param[in] Matrix
*/
template <int Dimension>
void Matrix<Dimension>::rotation(double angle,char axis)
{
    double x;
    x = (angle*PI)/180;
    switch(axis)
{
case 'z':{
this->array[0][0]=cos(x);
this->array[0][1]=-sin(x);
this->array[0][2]=0;

this->array[1][0]=sin(x);
this->array[1][1]=cos(x);
this->array[1][2]=0;

this->array[2][0]=0;
this->array[2][1]=0;
this->array[2][2]=1;
}
    break;
case 'y':{
this->array[0][0]=cos(x);
this->array[0][1]=0;
this->array[0][2]=sin(x);

this->array[1][0]=0;
this->array[1][1]=1;
this->array[1][2]=0;

this->array[2][0]=-sin(x);
this->array[2][1]=0;
this->array[2][2]=cos(x);
}
    break;
case 'x':{
this->array[0][0]=1;
this->array[0][1]=0;
this->array[0][2]=0;

this->array[1][0]=0;
this->array[1][1]=cos(x);
this->array[1][2]=-sin(x);

this->array[2][0]=0;
this->array[2][1]=sin(x);
this->array[2][2]=cos(x);
}
    break;
}


}
