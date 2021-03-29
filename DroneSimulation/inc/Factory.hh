#pragma once
#include "vector.hh"
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "matrix.hh"
#include "Scene_object.hh"
#include "Drone.hh"
#include "Obstacle.hh"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <list>
#include <memory>

//using namespace std;
/*!
 * \file
 * \brief Zbior mozliwych typow obiektow
 *
 * enum z mozliwymi typami obiektow
 */
enum TypObiektu { TO_Robot, TO_Przeszkoda };
/*!
 * \file
 * \brief Definicja klasy Factory
 *
 * Klasa modeluje pojecie fabryki
 * Jej atrybutem jest pole DefaultName ktore
 * oznacza nazwe tworzonego obiektu
 */

class Factory {
   /*!
* \brief Nazwa domyslna obiektu
*
* Pole zawiera domyslna nazwe tworzonego obiektu
*/
string  _DomyslnaNazwa;
public:

Factory &Nazwa(const char* sNazwa) { _DomyslnaNazwa = sNazwa; }

shared_ptr<Scene_object> StworzObiekt( TypObiektu  TypOb, Vector3D mid, Vector3D dim, char type )
    {
      switch (TypOb) {
       case TO_Robot: return make_shared<Drone>(_DomyslnaNazwa.c_str(), mid, dim, type);
       case TO_Przeszkoda: return make_shared<Obstacle>(_DomyslnaNazwa.c_str(), mid, dim, type);
      }
      return make_shared<Obstacle>(); // To tylko po to, aby kompilator
                // nie twierdził, że metoda nic nie zwraca. Ta instrukcja
                // i tak nigdy się nie wykona.
    }


};





