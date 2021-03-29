#pragma once
#include "Figure.hh"
#include "vector.hh"
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "matrix.hh"
#include "cuboid.hh"
#include <iostream>

const int Prism_points=12;

/*!
 * \file
 * \brief Definicja klasy Hexagon
 *
 * Klasa modeluje pojecie wirnika - szesciokata.
 * Dziedziczy z klasy bazowej Figure
 */
class Prism : public Figure<3, Prism_points>
{

public:

    void Point_Rotate(double angle, Vector3D rotate_point);
    void set_Prism(Vector3D middle_bot, double R, double thickness, double Angle_degrees, double JumpAngle_degrees);

};
