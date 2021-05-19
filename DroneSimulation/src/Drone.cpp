#include "Drone.hh"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
using namespace std;

/*!
* Ustawia drona
*
* Ustawia punkty drona wedlug
* zadanych przy tworzeniu obiektu
* wymiarow i srodka
* \param[in] R - double, promien wirnikow, Thickness - double, grubosc wirnikow, JumpAngle_degrees - double, roznica katu pomiedzy sasiednimi punktami wirnikow
* \param[out]
* Jest ono wyrazone w jednostkach niemianowanych.
*/
void Drone::set_Drone(double R, double Thickness, double JumpAngle_degrees)
{
double Angle_degrees=0;

this->Body.set_Cub(this->middle_point(), this->dimensions());
for (int j=0; j<4; ++j)
{
Angle_degrees=0;
JumpAngle_degrees*=-1;

this->Rotor[j].set_Prism(this->Body[j+4], R, Thickness, Angle_degrees, JumpAngle_degrees);
}
this->r=sqrt(this->dimensions()[0]*this->dimensions()[0]+this->dimensions()[1]*this->dimensions()[1])+R;
}

/*!
* Ustawia przeszkode
*
* Ustawia punkty przeszkody wedlug
* zadanych przy tworzeniu obiektu
* wymiarow i srodka
* \param[in]
* \param[out]
* Jest ono wyrazone w jednostkach niemianowanych.
*/
bool Drone::Collidate(const Drone& object)
{

if ((this->R()+object.R())>sqrt(pow(this->middle_point()[0]-object.middle_point()[0], 2) +pow(this->middle_point()[1]-object.middle_point()[1], 2))
&& (abs(this->middle_point()[2]-object.middle_point()[2])<(this->dimensions()[2]+object.dimensions()[2]))) return 0;


return 1;

}
