#pragma once
#include "vector.hh"
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "matrix.hh"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
/*!
 * \file
 * \brief Definicja szablonu klasy Figure
 *
 * Klasa modeluje pojecie figury geometrycznej.
 * Jej atrybutem jest pole zawierajace odpowiednia liczbe wektorow.
 * Przyjmuje sie, ze d³ugosc podawana jest w jednostkach
 * niemianowanych.
 */
 template<int Dimension, int Points>
class Figure {
   /*!
* \brief Punkty figury geometrycznej
*
* Pole zawiera wspolrzedne punktow figury geometrycznej
* Przyjmuje sie, ze sa one podawane w jednostkach niemianowanych.
*/
protected:
Vector<Dimension> points[Points];

public:
    Vector<Dimension> operator [] (int i) const { return points[i]; }
    Vector<Dimension> & operator [] (int i) { return points[i]; }
    void fly(double distance, double fly_angle, double front_angle);
    void Axis_Rotate(double angle, char axis);


};


 /*!
* Wykorzystuje macierz rotacji, rotuje figury geometrycznej
* wokol srodka ukladu wspolrzednych i zmienia wartosci punktow figury geometrycznej.
*
* \param[in] angle - double, kat obrotu, axis - char, os obrotu
* \param[out] Zwraca zmienione wartosci punktow figury geometrycznej.
* Jest ono wyrazone w jednostkach niemianowanych.
*/
template <int Dimension, int Points>
void Figure<Dimension,Points>::Axis_Rotate( double angle, char axis)
{
Matrix3x3 Rotate_matrix;
Rotate_matrix.rotation(angle, axis);

    for (int j=0; j<Points; ++j)
        this->points[j]=Rotate_matrix * this->points[j];
}
 /*!
* \brief Wypisuje wspolrzedne punktow figury geometrycznej
*
* Wypisuje wspolrzedne punktow figury geometrycznej z pewna dokladnoscia
*/
template <int Dimension, int Points>
inline
ostream& operator << (ostream & StrmOut, const Figure<Dimension, Points> & fig)
{
for (int i=0; i<Points; ++i)
    {StrmOut <<  setw(16) << fixed << setprecision(16) << fig[i]<<endl;}

return StrmOut;
}

 /*!
* Przesuwa figure geometryczna o dana odleglosc i wedlug katu
*
* /param[in] distance - double, wartosc odleglosci, angle - double, wartosc katu ruchu, front_angle - double, kat o ktory dron sie obrocil wczesniej
* /param[out] Zwraca zmienione wartosci punktow figury geometrycznej
* Jest ono wyrazone w jednostkach niemianowanych.
*/
template <int Dimension, int Points>
void Figure<Dimension,Points>::fly(double distance, double fly_angle, double front_angle)
{
    double fly_ang, front_ang;
    int amount_T;

    amount_T=front_angle/360;
    front_angle-=(360*amount_T);
    front_ang=(front_angle*M_PI)/180;

    amount_T=fly_angle/360;
    fly_angle-=(360*amount_T);

    if (fly_angle==90)
    for (int j=0; j<Points; ++j)
        this->points[j][2]+=distance;
        else if (fly_angle==-90)
            for (int j=0; j<Points; ++j)
                this->points[j][2]-=distance;
            else {
                fly_ang = (fly_angle*M_PI)/180;
                for (int j=0; j<Points; ++j)
                {this->points[j][0]+=(distance*cos(front_ang));
                this->points[j][1]+=(distance*sin(front_ang));
                this->points[j][2]+=(tan(fly_ang)*distance);}
                }
}
