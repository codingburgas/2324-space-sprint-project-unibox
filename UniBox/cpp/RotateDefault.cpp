#include "../Includes/Check.h"
#include "../Includes/Align.h"
#include "../Includes/Orbit.h"
#include "../Includes/RotateDefault.h"
#include "../Includes/Rotate.h"
#include "../Includes/Draw.h"
#include "../Includes/Pluton.h"
void rotation_default(Texture2D Mercury, Texture2D Venus, Texture2D Earth, Texture2D Mars, Texture2D Jupiter, Texture2D Saturn, Texture2D Uranus, Texture2D Neptune, Texture2D Sun )
{
    if (check1 == 1) //left (clicked once)
    {
        DrawTexture(Sun, align_sun::left, align_sun::down, YELLOW);

        if (!black_hole_disappear[0])
            draw_planet_f(Mercury, align_mercury::left, align_mercury::down, align_mercury::angle);
        if (!black_hole_disappear[1])
            draw_planet_f(Venus, align_venus::left, align_venus::down, align_venus::angle);
        if (!black_hole_disappear[2])
            draw_planet_f(Earth, align_earth::left, align_earth::down, align_earth::angle);
        if (!black_hole_disappear[3])
            draw_planet_f(Mars, align_mars::left, align_mars::down, align_mars::angle);
        if (!black_hole_disappear[4])
            draw_planet_f(Jupiter, align_jupiter::left, align_jupiter::down, align_jupiter::angle);
        if (!black_hole_disappear[5])
            draw_planet_f(Saturn, align_saturn::left, align_saturn::down, align_saturn::angle);
        if (!black_hole_disappear[6])
            draw_planet_f(Uranus, align_uranus::left, align_uranus::down, align_uranus::angle);
        if (!black_hole_disappear[7])
            draw_planet_f(Neptune, align_neptune::left, align_neptune::down, align_neptune::angle);


        rotate_planet_back(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed, align_mercury::left, align_mercury::down);

        rotate_planet_back(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed, align_venus::left, align_venus::down);

        rotate_planet_back(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed, align_earth::left, align_earth::down);

        rotate_planet_back(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed, align_mars::left, align_mars::down);

        rotate_planet_back(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed, align_jupiter::left, align_jupiter::down);

        rotate_planet_back(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed, align_saturn::left, align_saturn::down);

        rotate_planet_back(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed, align_uranus::left, align_uranus::down);

        rotate_planet_back(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed, align_neptune::left, align_neptune::down);
    }
    if (check1 == 0) // default (not clicked,right direction )
    {
        DrawTexture(Sun, align_sun::left, align_sun::down, YELLOW);

        if (!black_hole_disappear[0])
            draw_planet_f(Mercury, align_mercury::left, align_mercury::down, align_mercury::angle);
        if (!black_hole_disappear[1])
            draw_planet_f(Venus, align_venus::left, align_venus::down, align_venus::angle);
        if (!black_hole_disappear[2])
            draw_planet_f(Earth, align_earth::left, align_earth::down, align_earth::angle);
        if (!black_hole_disappear[3])
            draw_planet_f(Mars, align_mars::left, align_mars::down, align_mars::angle);
        if (!black_hole_disappear[4])
            draw_planet_f(Jupiter, align_jupiter::left, align_jupiter::down, align_jupiter::angle);
        if (!black_hole_disappear[5])
            draw_planet_f(Saturn, align_saturn::left, align_saturn::down, align_saturn::angle);
        if (!black_hole_disappear[6])
            draw_planet_f(Uranus, align_uranus::left, align_uranus::down, align_uranus::angle);
        if (!black_hole_disappear[7])
            draw_planet_f(Neptune, align_neptune::left, align_neptune::down, align_neptune::angle);

        rotate_planet(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed, align_mercury::left, align_mercury::down);

        rotate_planet(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed, align_venus::left, align_venus::down);

        rotate_planet(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed, align_earth::left, align_earth::down);

        rotate_planet(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed, align_mars::left, align_mars::down);

        rotate_planet(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed, align_jupiter::left, align_jupiter::down);

        rotate_planet(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed, align_saturn::left, align_saturn::down);

        rotate_planet(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed, align_uranus::left, align_uranus::down);

        rotate_planet(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed, align_neptune::left, align_neptune::down);


    }
}