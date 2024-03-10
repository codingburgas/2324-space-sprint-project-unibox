#include "../Includes/Rotate.h"
#include "../Includes/Screen.h"
#include <math.h>
Vector2 rotate_point(float& angle, float a, float e, float perihelionAngle, float speed)
{

    float radians = (angle + perihelionAngle) * DEG2RAD; // calculates the angle in radians
    float radius = a * (1 - e * e) / (1 + e * cos(radians - perihelionAngle)); // calculates the radius
    angle += speed; // increments the angle by adding the rotation speed
    if (angle > 360.f)
        angle = 0.f;
    return Vector2{ screenWidth / 2.f + radius * float(cos(radians)), screenHeight / 2.f + radius * float(sin(radians)) }; // returns x and y

}
Vector2 rotate_point_back(float& angle, float a, float e, float perihelionAngle, float speed)
{
    float radians = (angle + perihelionAngle) * DEG2RAD; // calculates the angle in radians
    float radius = a * (1 - e * e) / (1 + e * cos(radians - perihelionAngle)); // calculates the radius
    angle -= speed; // increments the angle by adding the rotation speed
    if (angle < 0.f)
        angle = 360.f + angle;
    return Vector2{ screenWidth / 2.f + radius * float(cos(radians)), screenHeight / 2.f + radius * float(sin(radians)) }; // returns x and y
}
void rotate_planet(float& angle, float a, float e, float perihelionAngle, float speed, int& left, int& down)
{
    Vector2 newp = rotate_point(angle, a, e, perihelionAngle, speed); // calculate the new position
    left = newp.x; // assign x
    down = newp.y; // assign y
    //rotate mercury example
    //  Vector2 newp = rotate_point(align_mercury::angle, mercury::a, mercury::e,mercury::perihelionAngle, 10.f);
    //  align_mercury::left = newp.x ;
    // align_mercury::down = newp.y ;
}
void rotate_planet_back(float& angle, float a, float e, float perihelionAngle, float speed, int& left, int& down)
{
    Vector2 newp = rotate_point_back(angle, a, e, perihelionAngle, speed);
    left = newp.x;
    down = newp.y;

}