#include "Prism.hh"
#include "matrix.hh"
#include "vector.hh"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;





/*!
* Obraca szesciokat wedlug wlasnej osi
*
* \param[in] angle - double, wartosc katu w stopniach, rotate_point - Vector3D, punkt wokol ktorego bedzie wykonywany obrot
* \param[out] Zwraca zmienione wartosci punktow szesciokatu
* Jest ono wyrazone w jednostkach niemianowanych.
*/

void Prism::Point_Rotate(double angle, Vector3D rotate_point)
{
double ang;
ang = (angle*M_PI)/180;

for (int j=0; j<Prism_points; ++j)
    {
    this->points[j][0]=(this->points[j][0]-rotate_point[0])*cos(ang)-(this->points[j][1]-rotate_point[1])*sin(ang)+rotate_point[0];
    this->points[j][1]=(this->points[j][0]-rotate_point[0])*sin(ang)+(this->points[j][1]-rotate_point[1])*cos(ang)+rotate_point[1];
    }
}

/*!
* Tworzy graniastoslup
*
* \param[in] middle_point - Vector3D, wspolrzedne srodka, R- double promien rotora, Angle_degrees - double wartosc kata obrotu
* \param[out]
*/
void Prism::set_Prism(Vector3D middle_bot, double R, double thickness, double Angle_degrees, double JumpAngle_degrees)
{

  for (int i = 0; i < 6; ++i) {
    this->points[i][0] = middle_bot[0]+R*cos(Angle_degrees);
    this->points[i][1] = middle_bot[1]+R*sin(Angle_degrees);
    this->points[i+6][0] = this->points[i][0];
    this->points[i+6][1] = this->points[i][1];
    Angle_degrees += JumpAngle_degrees;
  }

  for (int i=0; i<6; ++i)
  {
      this->points[i][2]=middle_bot[2];
      this->points[i+6][2]=middle_bot[2]+thickness;
  }

}

