#pragma once
#include <vector>
extern bool check_to_show;
extern std::vector <bool> black_hole_disappear; // checkers if a planet needs to disappear
extern std::vector <bool> draw_on_orbit; // checkers if pluton needs to be in the program

extern bool remove_pluton[8]; // checkers if pluton has been already drawn and if it needs to be removed again(if any of the orbit buttons is clicked twice)
extern int check1, check2, check3, check4; // variable used to check if a button is pressed and how many times
extern bool info_check; // check either to show or close the stats menu, by making chnages with its value under certain conditions

