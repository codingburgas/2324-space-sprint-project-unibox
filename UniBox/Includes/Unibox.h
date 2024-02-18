#pragma once
#include "raylib.h"
#include <math.h>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#pragma warning(disable: 6387) // remove a C6387 warning which is unnecessary, const char* '0' instead of "0000", we are using only strings not single chars
#pragma warning(disable: 4305) // const double to float data loss warning (unnecessary)
#pragma warning(disable: 4244) // float to int data loss conversion warning (unnecessary)
using namespace std;
const int screenWidth = 1745; //800, 1745
const int screenHeight = 895; //450
/*
 а = avarage distance to sun
 e = warping a planet
 perihelionAngle = closest point of each planet to the sun
*/
namespace sun
{
	const double a = 0.0;
	const double e = 0.0;
	const double perihelionAngle = 0.0;
}
namespace mercury
{
	const double a = 63.9; // 57.9, 50.9
	const double e = 0.2056;
	const double perihelionAngle = 77.46;
}
namespace venus
{
	const double a = 94.2; //108.2,90.2
	const double e = 0.0067;
	const double perihelionAngle = 131.77;
}
namespace earth
{
	const double a = 128.6;  //149.6
	const double e = 0.0167;
	const double perihelionAngle = 102.94;
}
namespace mars
{
	const double a = 178.9;  //227.9,166.9
	const double e = 0.0334;  //0,0934
	const double perihelionAngle = 336.04;
}
namespace jupiter
{
	const double a = 229.6; // 778.6
	const double e = 0.019; //0.049
	const double perihelionAngle = 14.75; //14.75
}
namespace saturn
{
	const double a = 287.5; // 1433.5, 272.5
	const double e = 0.0065; //0.0565, 0.0365
	const double perihelionAngle = 92.43; //92.43
}
namespace uranus
{
	const double a = 370.5; //2872.5, 335.5, 350.5
	const double e = 0.0164; // 0.464, 0.0164, 
	const double perihelionAngle = 170.96; // 170.96
}
namespace neptune
{
	const double a = 435.1; //4495.1, 400.1
	const double e = 0.0106; //0.0106, 0.0106
	const double perihelionAngle = 44.97; //44.97
}

// draw orbit
void draw_orbit(const double, const double, const double);
void draw_orbit_all();
// alignments of different planets and the sun

namespace align_sun
{
	int down = 385;
	int left = 830; // 838
	float angle = 0.f;
}
namespace align_mercury
{
	int down = 390;
	int left = 800;
	float angle = 77.46f;
}
namespace align_venus
{
	int down = 400;
	int left = 759;
	float angle = 0.f;
}
namespace align_earth
{
	int down = 400;
	int left = 718;
	float angle = 0.f;
}
namespace align_mars
{
	int down = 405;
	int left = 659;
	float angle = 0.f;
}
namespace align_jupiter
{
	int down = 405;
	int left = 603;
	float angle = 0.f;
}
namespace align_saturn
{
	int down = 375;
	int left = 494;
	float angle = 0.f;
}
namespace align_uranus
{
	int down = 410;
	int left = 510;
	float angle = 0.f;
}
namespace align_neptune
{
	int down = 410;
	int left = 390;
	float angle = 0.f;
}

// alignments of stats menu and its elements: left is x ,down is y
// average k is 60 ( average difference between all downs), most of them are decremented by 2 to make the text look better
// stats
const int left_stats = 1395;
const int align_stats_down[9] = { 95,153,213,273,333,393,453,513,573 };
// length
const int left_length[9] = { 1458,1450,1450,1446,1450,1443,1442,1443,1442 };
const int align_length_down[9] = { 171,229,290,349,408,469,529,590,650 };
// temperature
const int left_temperature[9] = { 1467,1472,1470,1484,1480,1467,1465,1465,1464 };
const int align_temperature_down[9] = { 108,166,226,286,346,406,465,526,585 };
// speed
const int left_speed[9] = { 1460,1454,1450,1456,1455,1455,1460,1456,1460 };
const int align_speed_down[9] = { 244,302,362,422,482,542,602,662,722 };

// text size in stats
#define text_size 28

// we are using a key value, in this case a string to find each temperature and speed (float value)
// lengths is just const char* to const char*
map<string, float> temperatures =
{
	{"Sun",5500.0f},
	{"Mercury",430.0f},
	{"Venus",470.0f},
	{"Earth",15.0f},
	{"Mars",20.0f},
	{"Jupiter",-145.0f},
	{"Saturn",-178.0f},
	{"Uranus",-224.0f},
	{"Neptune",-220.0f}
};
map <const char*, const char*> lengths =
{
	{"Sun","1.4Mkm"},
	{"Mercury","4880km"},
	{"Venus","12104km"},
	{"Earth","12742km"},
	{"Mars","6779km"},
	{"Jupiter","98982km"},
	{"Saturn","116460km"},
	{"Uranus","50724km"},
	{"Neptune","49244km"}
};
map <const char*, float> speeds =        // theoretical speeds in real life
{
	{"Sun",10000.f},
	{"Mercury", 170503.f},
	{"Venus", 126074.f},
	{"Earth", 107218.f},
	{"Mars", 86667.f},
	{"Jupiter", 47002.f},
	{"Saturn", 34701.f},
	{"Uranus", 24477.f},
	{"Neptune", 19556.f}
};
namespace actual_speed // float value speed
{
	 float mercury_speed =0.7f; // 1
	 float venus_speed = 0.5f; //2
	 float earth_speed = 0.3f; //3
	 float mars_speed = 0.1f; //4
	 float jupiter_speed = 0.07f; //5
         float saturn_speed = 0.03f; //6
	 float uranus_speed = 0.02f; //7
	 float neptune_speed = 0.009f; //8

}
vector <bool> draw_on_orbit(9); // checkers if pluton needs to be in the program
vector <bool> black_hole_disappear(8); // checkers if a planet needs to disappear
bool remove_pluton[8]; // checkers if pluton has been already drawn and if it needs to be removed again(if any of the orbit buttons is clicked twice)

void draw_planet(Texture2D, int&, int&, float&); // draw a texture using DrawTexturePro

Vector2 rotate_point(float&, float, float, float, float);

Vector2 rotate_point_back(float& angle, float a, float e, float perihelionAngle, float speed);

void rotate_planet(float&, float, float, float, float, int&, int&);

void rotate_planet_back(float& angle, float a, float e, float perihelionAngle, float speed, int& left, int& down);

string convert_float_to_str(float); // convert float to string

// void stats_show(Texture2D planet, const char* name,Texture2D Close,const int align_left, const int align_down);

void menu_show(Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D); // show menu if clicked on info button and hover on the planets to see their stats
void functions_menu(Texture2D f_menu, Texture2D Checker, Texture2D exit_button, Texture2D checker_exit_button, Texture2D exit_menu, Texture2D options_checker, Texture2D Mercury, Texture2D Venus, Texture2D Earth, Texture2D Mars, Texture2D Jupiter, Texture2D Saturn, Texture2D Uranus, Texture2D Neptune, Texture2D Sun, Texture2D pluton, Texture2D add_planet_menu, Texture2D cancel_add_planet, Texture2D cancel_add_planet_blank,Texture2D black_hole);
  static bool info_check; // check either to show or close the stats menu, by making chnages with its value under certain conditions
static int check1, check2, check3, check4; // variable used to check if a button is pressed and how many times
 



	
