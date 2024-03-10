#pragma once
#include "raylib.h"
// draw orbit
void draw_orbit(const double, const double, const double);
void draw_orbit_all();
void draw_planet_f(Texture2D, int&, int&, float&); // draw a texture using DrawTexturePro