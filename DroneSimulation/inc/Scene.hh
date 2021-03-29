#pragma once
#include "vector.hh"
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "matrix.hh"
#include "Scene_object.hh"
#include "Drone.hh"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <list>
#include <memory>

//using namespace std;

/*!
 * \file
 * \brief Definicja szablonu klasy Scene
 *
 * Klasa modeluje pojecie sceny
 * Jej atrybutem sa listy zawieraja obiekty sceny i drony
 */

class Scene {

public:
    /*!
* \brief Lista obiektow sceny
*
* Pole zawiera liste wskaznikow na obiekty sceny
*/
std::list<std::shared_ptr<Scene_object>> Objects;
/*!
* \brief Lista dronow bedacych w scenie
*
* Pole zawiera liste wskaznikow na drony bedace w scenie
*/
std::list<std::shared_ptr<Drone>> Drones;



    std::list<std::shared_ptr<Scene_object>>  objects() const {return Objects;}
    std::list<std::shared_ptr<Scene_object>>&  objects() {return Objects;}

    std::shared_ptr<Scene_object> gobjects() const {return Objects.back();}
    std::shared_ptr<Scene_object>&  gobjects() {return Objects.back();}

    std::shared_ptr<Drone> gdrones() const {return Drones.back();}
    std::shared_ptr<Drone>&  gdrones() {return Drones.back();}

    std::list<std::shared_ptr<Drone>>  drones() const {return Drones;}
    std::list<std::shared_ptr<Drone>>& drones() {return Drones;}


};


