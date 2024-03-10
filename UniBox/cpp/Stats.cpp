#include "../Includes/Stats.h"
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
const int text_size = 28;

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