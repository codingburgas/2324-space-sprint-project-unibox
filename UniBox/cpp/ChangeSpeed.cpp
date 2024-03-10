#include "../Includes/ChangeSpeed.h"
#include "../Includes/Check.h"
#include "../Includes/Rotate.h"
#include "../Includes/Align.h"
#include "../Includes/Orbit.h"
#include "../Includes/Pluton.h"
void change_speed()
{
    if (check2 == 0)
    {
        //default 

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////fix all////////////////////////////////////////////// and pluton//////////////////////////////////
        if (check1 == 0)// if not clicked right direction, use rotate_point
        {
            rotate_planet(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed, align_mercury::left, align_mercury::down);

            rotate_planet(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed, align_venus::left, align_venus::down);

            rotate_planet(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed, align_earth::left, align_earth::down);

            rotate_planet(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed, align_mars::left, align_mars::down);

            rotate_planet(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed, align_jupiter::left, align_jupiter::down);

            rotate_planet(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed, align_saturn::left, align_saturn::down);

            rotate_planet(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed, align_uranus::left, align_uranus::down);

            rotate_planet(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed, align_neptune::left, align_neptune::down);
        }
        if (check1 == 1) // if clicked left direction, use rotate_point_back 
        {
            rotate_planet_back(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed, align_mercury::left, align_mercury::down);

            rotate_planet_back(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed, align_venus::left, align_venus::down);

            rotate_planet_back(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed, align_earth::left, align_earth::down);

            rotate_planet_back(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed, align_mars::left, align_mars::down);

            rotate_planet_back(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed, align_jupiter::left, align_jupiter::down);

            rotate_planet_back(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed, align_saturn::left, align_saturn::down);

            rotate_planet_back(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed, align_uranus::left, align_uranus::down);

            rotate_planet_back(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed, align_neptune::left, align_neptune::down);
        }

    }

    if (check2 == 1)
    {
        //first click
        if (check1 == 0)
        {
            rotate_planet(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.1f, align_mercury::left, align_mercury::down);

            rotate_planet(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.1f, align_venus::left, align_venus::down);

            rotate_planet(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.1f, align_earth::left, align_earth::down);

            rotate_planet(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.1f, align_mars::left, align_mars::down);

            rotate_planet(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.1f, align_jupiter::left, align_jupiter::down);

            rotate_planet(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.1f, align_saturn::left, align_saturn::down);

            rotate_planet(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.1f, align_uranus::left, align_uranus::down);

            rotate_planet(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.1f, align_neptune::left, align_neptune::down);

        }
        if (check1 == 1)
        {

            rotate_planet_back(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.1f, align_mercury::left, align_mercury::down);

            rotate_planet_back(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.1f, align_venus::left, align_venus::down);

            rotate_planet_back(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.1f, align_earth::left, align_earth::down);

            rotate_planet_back(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.1f, align_mars::left, align_mars::down);

            rotate_planet_back(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.1f, align_jupiter::left, align_jupiter::down);

            rotate_planet_back(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.1f, align_saturn::left, align_saturn::down);

            rotate_planet_back(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.1f, align_uranus::left, align_uranus::down);

            rotate_planet_back(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.1f, align_neptune::left, align_neptune::down);
        }
    }
    if (check2 == 2)
    {
        //first click

        if (check1 == 0)// if not clicked right direction, use rotate_point
        {
            rotate_planet(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.3f, align_mercury::left, align_mercury::down);

            rotate_planet(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.3f, align_venus::left, align_venus::down);

            rotate_planet(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.3f, align_earth::left, align_earth::down);

            rotate_planet(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.3f, align_mars::left, align_mars::down);

            rotate_planet(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.3f, align_jupiter::left, align_jupiter::down);

            rotate_planet(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.3f, align_saturn::left, align_saturn::down);

            rotate_planet(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.3f, align_uranus::left, align_uranus::down);

            rotate_planet(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.3f, align_neptune::left, align_neptune::down);
        }
        if (check1 == 1) // if clicked left direction, use rotate_point_back 
        {
            rotate_planet_back(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.3f, align_mercury::left, align_mercury::down);

            rotate_planet_back(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.3f, align_venus::left, align_venus::down);

            rotate_planet_back(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.3f, align_earth::left, align_earth::down);

            rotate_planet_back(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.3f, align_mars::left, align_mars::down);

            rotate_planet_back(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.3f, align_jupiter::left, align_jupiter::down);

            rotate_planet_back(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.3f, align_saturn::left, align_saturn::down);

            rotate_planet_back(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.3f, align_uranus::left, align_uranus::down);

            rotate_planet_back(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.3f, align_neptune::left, align_neptune::down);

        }

    }

    if (check2 == 3)
    {
        //third click

        if (check1 == 0)// if not clicked right direction, use rotate_point
        {
            rotate_planet(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.5f, align_mercury::left, align_mercury::down);

            rotate_planet(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.5f, align_venus::left, align_venus::down);

            rotate_planet(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.5f, align_earth::left, align_earth::down);

            rotate_planet(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.5f, align_mars::left, align_mars::down);

            rotate_planet(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.5f, align_jupiter::left, align_jupiter::down);

            rotate_planet(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.5f, align_saturn::left, align_saturn::down);

            rotate_planet(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.5f, align_uranus::left, align_uranus::down);

            rotate_planet(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.5f, align_neptune::left, align_neptune::down);
        }
        if (check1 == 1) // if clicked left direction, use rotate_point_back 
        {
            rotate_planet_back(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.5f, align_mercury::left, align_mercury::down);

            rotate_planet_back(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.5f, align_venus::left, align_venus::down);

            rotate_planet_back(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.5f, align_earth::left, align_earth::down);

            rotate_planet_back(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.5f, align_mars::left, align_mars::down);

            rotate_planet_back(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.5f, align_jupiter::left, align_jupiter::down);

            rotate_planet_back(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.5f, align_saturn::left, align_saturn::down);

            rotate_planet_back(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.5f, align_uranus::left, align_uranus::down);

            rotate_planet_back(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.5f, align_neptune::left, align_neptune::down);

        }
    }
}