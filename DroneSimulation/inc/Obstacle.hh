#pragma once
#include "Figure.hh"
#include "Scene_object.hh"
#include "Drone.hh"
#include "vector.hh"
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "matrix.hh"
#include "cuboid.hh"
#include "Prism.hh"

#include <iostream>

const int Obst_points=8;


/*!
 * \file
 * \brief Definicja klasy Obstacle
 *
 * Klasa modeluje pojecie przeszkoda - prostopadloscianu.
 * Dziedziczy z klasy bazowej Scene_object
 */
class Obstacle :  public Scene_object
{
    /*!
* \brief Prostopadloscian
*
* Pole zawiera prostopadloscian definiujacy przeszkode
* Przyjmuje sie, ze sa one podawane w jednostkach niemianowanych.
*/
Cuboid Obst;


public:

Obstacle()              { cout << "+++ K: Przeszkoda: " << _Nazwa << endl; }
   Obstacle(const char* sNazwa, Vector3D mid, Vector3D dim, char type): Scene_object(sNazwa)  { middle_point()[0]=mid[0]; middle_point()[1]=mid[1]; Middle_point[2]=mid[2]; Dimensions[0]=dim[0]; Dimensions[1]=dim[1]; Dimensions[2]=dim[0]; cout << "+++ K: Przeszkoda: " << _Nazwa << endl; type()=type;}
   Obstacle(const Obstacle &) { cout << "### K:Przeszkoda: " << _Nazwa << endl; }
   ~Obstacle()             { cout << "--- D: Przeszkoda: " << _Nazwa << endl; }

   const char* Typ() const { return "Przeszkoda"; }

    Cuboid obst() const {return Obst;}
    Cuboid& obst() {return Obst;}
    bool Collidate(const Drone& drone);
    Obstacle(double mid_x, double mid_y, double mid_z, double x_dim, double y_dim, double z_dim) {Middle_point[0]=mid_x; Middle_point[1]=mid_y; Middle_point[2]=mid_z; Dimensions[0]=x_dim; Dimensions[1]=y_dim; Dimensions[2]=z_dim; }
    void set_Obstacle();
};
