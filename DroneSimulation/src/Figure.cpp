
#include "Figure.hh"
#include <iostream>
#include <iomanip>
#include <cmath>
#define POINTS 8
#define PI 3.14159265
using namespace std;

 /*!
* Wykorzystuje macierz rotacji, rotuje figury geometrycznej
* wokol srodka ukladu wspolrzednych i zmienia wartosci punktow figury geometrycznej.
*
* \param[in] Rotate_matrix - macierz rotacji
* \param[out] Zwraca zmienione wartosci punktow figury geometrycznej.
* Jest ono wyrazone w jednostkach niemianowanych.
*/
void Figure::Rotate( Matrix3x3 Rotate_Matrix)
{
    for (int j=0; j<POINTS; ++j)
        this->points[j]=Rotate_Matrix * this->points[j];
}

 /*!
* Przesuwa figury geometrycznej dodajac
* do nich zadany wektor
*
* param[in] V- vector translacji
* \param[out] Zwraca zmienione wartosci punktow figury geometrycznej.
* Jest ono wyrazone w jednostkach niemianowanych.
*/
void Figure::Translate(Vector3D V)
{
for (int j=0; j<POINTS; ++j)
    this->points[j]=this->points[j]+V;

}
 /*!
* \brief Wypisuje wspolrzedne punktow figury geometrycznej
*
* Wypisuje wspolrzedne punktow figury geometrycznej z pewna dokladnoscia
*/
ostream& operator << (ostream & StrmOut, const Figure & fig)
{
for (int i=0; i<POINTS; ++i)
 {StrmOut <<  setw(16) << fixed << setprecision(16) << fig[i]<<endl;}

return StrmOut;
}

 /*!
* Przesuwa figure geometryczna o dana odleglosc i wedlug katu
*
* /param[in] distance - double, wartosc odleglosci, angle - double, wartosc katu ruchu
* /param[out] Zwraca zmienione wartosci punktow figury geometrycznej
* Jest ono wyrazone w jednostkach niemianowanych.
*/
void Figure::fly(double distance, double angle)
{   double x;
    x = (angle*PI)/180;
    for (int j=0; j<POINTS; ++j)
    {this->points[j][0]+=distance;
    this->points[j][1]+=(tan(x)*distance);
    }
}

/*!
* Obraca szesciokat wedlug wlasnej osi
*
* \param[in] angle - double, wartosc katu w stopniach
* \param[out] Zwraca zmienione wartosci punktow szesciokatu
* Jest ono wyrazone w jednostkach niemianowanych.
*/
void Figure::OwnRotate(double angle)
{
    double ang;
    ang = (angle*PI)/180;
    double x, y;
    x=(this->points[0][0]+this->points[2][0])/2;
    y=(this->points[0][1]+this->points[2][1])/2;

    for (int j=0; j<POINTS; ++j)
        {this->points[j][0]=(this->points[j][0]-x)*cos(ang)-(this->points[j][1]-y)*sin(ang)+x;
         this->points[j][1]=(this->points[j][0]-x)*sin(ang)+(this->points[j][1]-y)*cos(ang)+y;
}
}
