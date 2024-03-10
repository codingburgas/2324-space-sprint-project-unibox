#include "../Includes/Draw.h"
#include "../Includes/Orbit.h"
#include "../Includes/Screen.h"
#include <math.h>
/*theta - calculates radians and radius and then converts them to x and y
radians - convert theta to radians, from agle to radians
radius - stores current distnace from the sun to the planet's position
x - coordinate for horison x
y - ordinate for vertical y
x and y are positioning the 2D texture just like a function(x,y) would be placed in a coordinate system
DrawPixel() - drawing
*/
void draw_orbit(const double a, const double e, const double perihelionAngle)
{

    for (double theta = 0.0; theta <= 360.0; theta++)
    {
        double radians = (theta + perihelionAngle) * DEG2RAD; // angle in radians
        double radius = a * (1 - e * e) / (1 + e * cos(radians - perihelionAngle)); // radius at the given angle
        double x = screenWidth / 2 + radius * cos(radians); // calculates x
        double y = screenHeight / 2 + radius * sin(radians); // calculates y 

        DrawPixel((int)x, (int)y, WHITE); // draws a pixel at the calculated position
    }
}
void draw_orbit_all()
{
    draw_orbit(sun::a, sun::e, sun::perihelionAngle);
    draw_orbit(mercury::a, mercury::e, mercury::perihelionAngle);
    draw_orbit(venus::a, venus::e, venus::perihelionAngle);
    draw_orbit(earth::a, earth::e, earth::perihelionAngle);
    draw_orbit(mars::a, mars::e, mars::perihelionAngle);
    draw_orbit(jupiter::a, jupiter::e, jupiter::perihelionAngle);
    draw_orbit(saturn::a, saturn::e, saturn::perihelionAngle);
    draw_orbit(uranus::a, uranus::e, uranus::perihelionAngle);
    draw_orbit(neptune::a, neptune::e, neptune::perihelionAngle);
}
void draw_planet_f(Texture2D planet, int& left, int& down, float& angle)
{

    DrawTexturePro(planet,
        Rectangle{ 0, 0, float(planet.width), float(planet.height) },
        Rectangle{ float(left), float(down),
        float(planet.width), float(planet.height) },
        Vector2{ planet.width / 2.f, planet.height / 2.f }, angle, WHITE);

}
