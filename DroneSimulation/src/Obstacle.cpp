#include "Obstacle.hh"
#include "matrix.hh"
#include "vector.hh"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

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
void Obstacle::set_Obstacle()
{
Obst.set_Cub(this->middle_point(), this->dimensions());

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
bool Obstacle::Collidate(const Drone& drone)
{
if (drone.middle_point()[0]>(this->middle_point()[0]-this->dimensions()[0]-drone.dimensions()[0]) &&  drone.middle_point()[0]<(this->middle_point()[0]+this->dimensions()[0]+drone.dimensions()[0])
&& drone.middle_point()[1]>(this->middle_point()[1]-this->dimensions()[1]-drone.dimensions()[1]) &&  drone.middle_point()[1]<(this->middle_point()[1]+this->dimensions()[1]+drone.dimensions()[1])
&& drone.middle_point()[2]>(this->middle_point()[2]-this->dimensions()[2]-drone.dimensions()[2]) &&  drone.middle_point()[2]<(this->middle_point()[2]+this->dimensions()[2]+drone.dimensions()[2])
) return 1;


return 0;
}
