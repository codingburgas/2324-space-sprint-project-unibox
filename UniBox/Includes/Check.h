#pragma once
#include <vector>
bool check_to_show = 0;
std::vector <bool> black_hole_disappear(8); // checkers if a planet needs to disappear
std::vector <bool> draw_on_orbit(9); // checkers if pluton needs to be in the program

bool remove_pluton[8] = {}; // checkers if pluton has been already drawn and if it needs to be removed again(if any of the orbit buttons is clicked twice)
int check1 = 0, check2 = 0, check3 = 0, check4 = 0; // variable used to check if a button is pressed and how many times
bool info_check = 0; // check either to show or close the stats menu, by making chnages with its value under certain conditions

bool show_stats_menu = false;
