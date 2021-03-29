#pragma once
#include "vector.hh"
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "matrix.hh"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>


using namespace std;
/*!
 * \file
 * \brief Definicja szablonu klasy Scene_object
 *
 * Klasa modeluje pojecie sceny obiektu
 * Jej atrybutem sa: wektor Middle_point oznaczajacy srodek obiektu
 * wektor Dimensions oznaczajacy wymiary obiektu
 * string name oznaczajacy nazwe obiektu
 * char type oznaczajacy typ obiektu
 *
 */

class Scene_object {

protected:
    /*!
* \brief Wektor srodka
*
* Pole zawiera wspolrzedne punktu srodkowego
* Przyjmuje sie, ze sa one podawane w jednostkach niemianowanych.
*/
Vector3D Middle_point;
/*!
* \brief Wektor wymiarow
*
* Pole zawiera wymiary obiektu
* Przyjmuje sie, ze sa one podawane w jednostkach niemianowanych.
*/
Vector3D Dimensions;
/*!
* \brief Nazwa obiektu
*
* Pole zawiera nazwe obiektu
* Przyjmuje sie, ze sa one podawane w jednostkach niemianowanych.
*/
string  _Nazwa;
/*!
* \brief Typ obiektu
*
* Pole zawiera rodzaj obiektu czy to dron czy przeszkoda
* Przyjmuje sie, ze sa one podawane w jednostkach niemianowanych.
*/
char type;
public:

   Scene_object(): _Nazwa("ObiektX")  { cout << "+++ K: ObiektSceny: " << _Nazwa << endl; }
  Scene_object(const char* sNazwa): _Nazwa(sNazwa)  { cout << "+++ K: ObiektSceny: " << _Nazwa << endl; }
   Scene_object(const Scene_object &) { cout << "### K: ObiektSceny: "  << _Nazwa << endl; }
   virtual ~Scene_object()          { cout << "--- D: ObiektSceny: "  << _Nazwa << endl; }

   virtual const char* Typ() const { return "ObiektSceny"; }
   const string& Nazwa() const { return _Nazwa; }

char type() const {return type;}
char& type() {return type;}
    Vector3D middle_point() const {return Middle_point;}
    Vector3D& middle_point() {return Middle_point;}
    Vector3D dimensions() const {return Dimensions;}
    Vector3D& dimensions() {return Dimensions;}
    virtual bool Collidate() {return 0;}
   //Scene_object() = default;
    Scene_object(double mid_x, double mid_y, double mid_z, double x_dim, double y_dim, double z_dim) {Middle_point[0]=mid_x; Middle_point[1]=mid_y; Middle_point[2]=mid_z; Dimensions[0]=x_dim; Dimensions[1]=y_dim; Dimensions[2]=z_dim; }


};


