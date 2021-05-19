#include "cuboid.hh"
#include <iostream>
#include <iomanip>
#include <cmath>
#define POINTS 8
#define PI 3.14159265
using namespace std;



/*!
* Obraca szesciokat wedlug wlasnej osi
*
* \param[in] angle - double, wartosc katu w stopniach
* \param[out] Zwraca zmienione wartosci punktow szesciokatu
* Jest ono wyrazone w jednostkach niemianowanych.
*/
void Cuboid::OwnRotate(double angle)
{
    double ang;
    ang = (angle*PI)/180;
    double x, y;
    x=(this->points[0][0]+this->points[2][0])/2;
    y=(this->points[0][1]+this->points[2][1])/2;

    for (int j=0; j<Cub_points; ++j)
        {this->points[j][0]=(this->points[j][0]-x)*cos(ang)-(this->points[j][1]-y)*sin(ang)+x;
         this->points[j][1]=(this->points[j][0]-x)*sin(ang)+(this->points[j][1]-y)*cos(ang)+y;
}
}

/*!
* Tworzy prostopadloscian
*
* \param[in] middle_point - Vector3D, wspolrzedne srodka ,dimensions - Vector3D, wymiary obiektu
* \param[out]
*/
void Cuboid::set_Cub(Vector3D middle_point, Vector3D dimensions)
{int j=1, xj=-1, yj=1;
for (int i=0; i<4; ++i)
{
if (j%2) xj*=-1;
else yj*=-1;
++j;
this->points[i][0]=middle_point[0]+(xj*dimensions[0]);
this->points[i][1]=middle_point[1]+(yj*dimensions[1]);
this->points[i][2]=middle_point[2]-dimensions[2];

this->points[i+4][0]=middle_point[0]+(xj*dimensions[0]);
this->points[i+4][1]=middle_point[1]+(yj*dimensions[1]);
this->points[i+4][2]=middle_point[2]+dimensions[2];
}
/*
this->points[0][0]=point[0]-x;
this->points[0][1]=point[1]-y;
this->points[0][2]=point[2]-z;

this->points[1][0]=point[0]+x;
this->points[1][1]=point[1]-y;
this->points[1][2]=point[2]-z;

this->points[2][0]=point[0]+x;
this->points[2][1]=point[1]+y;
this->points[2][2]=point[2]-z;

this->points[3][0]=point[0]-x;
this->points[3][1]=point[1]+y;
this->points[3][2]=point[2]-z;


this->points[4][0]=point[0]-x;
this->points[4][1]=point[1]-y;
this->points[4][2]=point[2]+z;

this->points[5][0]=point[0]+x;
this->points[5][1]=point[1]-y;
this->points[5][2]=point[2]+z;

this->points[6][0]=point[0]+x;
this->points[6][1]=point[1]+y;
this->points[6][2]=point[2]+z;

this->points[7][0]=point[0]-x;
this->points[7][1]=point[1]+y;
this->points[7][2]=point[2]+z;*/
}


 /*!
* Liczy dlugosci bokow a nastepnie sprawdza
* czy przeciwlegle boki sa rowne
*
* \return Wypisuje komunikat czy boki sa rowne
*/
void Cuboid::Length()
{double length[4];
Vector3D vect;
double wrong=0.0000000001;

vect=points[0]-points[1];
length[0]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);

vect=points[2]-points[3];
length[1]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);

vect=points[4]-points[5];
length[2]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);

vect=points[6]-points[7];
length[3]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);

if (length[0]-length[1]>wrong && length[1]-length[2]>wrong && length[2]-length[3]>wrong) cout<<"Dluzsze przeciwlegle boki sa sobie rowne. "<<endl;
    else cout<<"Dluzsze przeciwlegle boki nie sa rowne!!!"<<endl;

for (int i=0; i<4; ++i)
cout<<"Dlugosc "<<i+1<<"-tego boku: "<< setw(16) << fixed << setprecision(16) << length[i]<<endl;

vect=points[1]-points[2];
length[0]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);

vect=points[3]-points[0];
length[1]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);

vect=points[5]-points[6];
length[2]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);

vect=points[7]-points[4];
length[3]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);



if (length[0]-length[1]>wrong && length[1]-length[2]>wrong && length[2]-length[3]>wrong) cout<<"Krotsze przeciwlegle boki sa sobie rowne."<<endl;
    else cout<<"Krotsze przeciwlegle boki nie sa rowne!!!"<<endl;

    for (int i=0; i<4; ++i)
cout<<"Dlugosc "<<i+1<<"-tego boku: "<< setw(16) << fixed << setprecision(16) << length[i]<<endl;

vect=points[0]-points[4];
length[0]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);

vect=points[1]-points[5];
length[1]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);

vect=points[2]-points[6];
length[2]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);

vect=points[3]-points[7];
length[3]=sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]);


if (length[0]-length[1]>wrong && length[1]-length[2]>wrong && length[2]-length[3]>wrong) cout<<"Poprzeczne przeciwlegle boki sa sobie rowne."<<endl;
    else cout<<"Poprzeczne przeciwlegle boki nie sa rowne!!!"<<endl;
    for (int i=0; i<4; ++i)
cout<<"Dlugosc "<<i+1<<"-tego boku: "<< setw(16) << fixed << setprecision(16) << length[i]<<endl;

}
