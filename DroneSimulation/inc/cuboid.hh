#pragma once
#include "Figure.hh"
#include "vector.hh"
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "matrix.hh"
#include <iostream>

const int Cub_points=8;
/*!
 * \file
 * \brief Definicja klasy Cuboid
 *
 * Klasa modeluje pojecie prostopadloscianu.
 * Dziedziczy po klasie Figure
 */
class Cuboid : public Figure<3, Cub_points>
{

public:
    void Length();
    void OwnRotate(double angle);
    void set_Cub(Vector3D middle_point, Vector3D dimensions);
};


