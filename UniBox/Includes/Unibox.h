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
bool remove_pluton[8] = {}; // checkers if pluton has been already drawn and if it needs to be removed again(if any of the orbit buttons is clicked twice)

void draw_planet(Texture2D, int&, int&, float&); // draw a texture using DrawTexturePro

Vector2 rotate_point(float&, float, float, float, float);

Vector2 rotate_point_back(float&, float, float, float, float);

void rotate_planet(float&, float, float, float, float, int&, int&);

void rotate_planet_back(float&, float, float, float, float, int&, int&);

string convert_float_to_str(float); // convert float to string

void unload();
void menu_show(Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D); // show menu if clicked on info button and hover on the planets to see their stats
void functions_menu(Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D);
    bool info_check = 0; // check either to show or close the stats menu, by making chnages with its value under certain conditions
int check1 = 0, check2 = 0, check3 = 0, check4 = 0; // variable used to check if a button is pressed and how many times
bool check_to_show = 0;

// pluton data to make it spin and draw properly
namespace speed_pluton
{
 float speed_1 = 2.f;
 float speed_2 = 1.8f;
 float speed_3 = 1.6f;
 float speed_4 = 1.4f;
 float speed_5 = 1.2f;
 float speed_6 = 0.9f;
 float speed_7 = 0.3f; // 0.7f
 float speed_8 = 0.21f; // 0.5f
}
namespace a_pluton
{
 double a_1 = mercury::a;
 double a_2 = venus::a;
 double a_3 = earth::a;
 double a_4 = mars::a;
 double a_5 = jupiter::a;
 double a_6 = saturn::a;
 double a_7 = uranus::a;
 double a_8 = neptune::a;
}
namespace e_pluton
{
 double e_1 = mercury::e;
 double e_2 = venus::e;
 double e_3 = earth::e;
 double e_4 = mars::e;
 double e_5 = jupiter::e;
 double e_6 = saturn::e;
 double e_7 = uranus::e;
 double e_8 = neptune::e;
}
namespace peri_pluton
{
 double peri_1 = mercury::perihelionAngle;
 double peri_2 = venus::perihelionAngle;
 double peri_3 = earth::perihelionAngle;
 double peri_4 = mars::perihelionAngle;
 double peri_5 = jupiter::perihelionAngle;
 double peri_6 = saturn::perihelionAngle;
 double peri_7 = uranus::perihelionAngle;
 double peri_8 = neptune::perihelionAngle;
}
namespace angle_pluton
{
 float angle_1 = 0.f;
 float angle_2 = 0.f;
 float angle_3 = 0.f;
 float angle_4 = 1.3f;
 float angle_5 = 1.3f;
 float angle_6 = 1.3f;
 float angle_7 = 1.3f;
 float angle_8 = 1.2f;
}
namespace left_pluton
{
 int left_1 = 830;
 int left_2 = 800;
 int left_3 = 700;
 int left_4 = 659;
 int left_5 = 603;
 int left_6 = 494;
 int left_7 = 510;
 int left_8 = 390;
}
namespace down_pluton
{
 int down_1 = 385; 
 int down_2 = 390;
 int down_3 = 400;
 int down_4 = 405;
 int down_5 = 405;
 int down_6 = 375;           
 int down_7 = 410;
 int down_8 = 410; 
}
Texture2D background; // galaxy background
Texture2D stats; // show stats of pressed planet
Texture2D Sun; // sun picture
Texture2D Mercury; // mercury picture
Texture2D Venus; // venus picture
Texture2D Earth; // earth picture
Texture2D Mars; // mars picture
Texture2D Jupiter; // jupiter picture
Texture2D Saturn; // saturn image
Texture2D Uranus; // uranus image
Texture2D Neptune; // neptune image
Texture2D blank_info; // cancel stats button blank
Texture2D start; // start menu screen
Texture2D new_game; // new game button
Texture2D quit; // quit button
Texture2D info; // stats info button
Texture2D menu; // stats menu picture
Texture2D functions; // function options on the left
Texture2D checker;
Texture2D Checker; // functions buttons checker
Texture2D exit_button; // exit button texture
Texture2D checker_exit_button; // checker to see if exit options are pressed   
Texture2D exit_menu; // exit menu options
Texture2D options_checker;// checker if any of the exit options are checked
Texture2D pluton; // pluton picture    
Texture2D add_planet_menu; // add planet menu
Texture2D cancel_add_planet;// cancel button
Texture2D cancel_add_planet_blank; // blank for cancel button
Texture2D pluton_in_stats; // pluton stats 
Texture2D black_hole; // black hole menu with planets to choose 


	
