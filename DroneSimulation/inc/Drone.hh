#pragma once
#include "Scene_object.hh"
#include "Figure.hh"
#include "Prism.hh"
#include "cuboid.hh"
#include "vector.hh"
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "matrix.hh"

#include <iostream>

const int Drone_points=8;

/*!
 * \file
 * \brief Definicja klasy Drone
 *
 * Klasa modeluje pojecie Drona skladajacego
 * sie z ciala i 4 wirnikow
 * Dziedziczy po klasie Scene_object
 */
class Drone : public Scene_object
{
    /*!
* \brief Glowny czlon drona
*
* Pole zawiera prostopadloscian definiujacy glowna kadlub drona
* Przyjmuje sie, ze sa one podawane w jednostkach niemianowanych.
*/
Cuboid Body;
/*!
* \brief Wirniki
*
* Pole zawiera tablice 4 graniastoslupow definiujacch wirniki drona
* Przyjmuje sie, ze sa one podawane w jednostkach niemianowanych.
*/
Prism Rotor[4];
/*!
* \brief Promien wirnikow
*
* Pole zawiera liczbe oznaczajaca promien wirnikow
* Przyjmuje sie, ze sa one podawane w jednostkach niemianowanych.
*/
double r;


public:

Drone()              { cout << "+++ K: Robot: " << _Nazwa << endl; }
  //Drone(const char* sNazwa): Scene_object(sNazwa)  { cout << "+++ K: Robot: " << _Nazwa << endl; }
  // Drone(const Drone &) { cout << "### K:Robot: " << _Nazwa << endl; this}
   ~Drone()             { cout << "--- D: Robot: " << _Nazwa << endl; }

   Drone(const char* sNazwa, Vector3D mid, Vector3D dim, char type): Scene_object(sNazwa)  { middle_point()[0]=mid[0]; middle_point()[1]=mid[1]; Middle_point[2]=mid[2]; Dimensions[0]=dim[0]; Dimensions[1]=dim[1]; Dimensions[2]=dim[0]; cout << "+++ K: Robot: " << _Nazwa << endl; type()=type;}

   const char* Typ() const { return "Robot"; }

    Cuboid body() const {return Body;}
    Cuboid& body() {return Body;}
    Prism rotor(int i) const {return Rotor[i];}
    Prism& rotor(int i) {return Rotor[i];}
    double R() const {return r;}
    double& R() {return r;}
	bool Collidate(const Drone& drone2);
    Drone(double mid_x, double mid_y, double mid_z, double x_dim, double y_dim, double z_dim) {middle_point()[0]=mid_x; middle_point()[1]=mid_y; Middle_point[2]=mid_z; Dimensions[0]=x_dim; Dimensions[1]=y_dim; Dimensions[2]=z_dim; }
    void set_Drone(double R, double Thickness, double JumpAngle_degrees);
};


