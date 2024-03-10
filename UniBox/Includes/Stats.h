#pragma once
#include <map>
#include <string>
using namespace std;

extern const int left_stats;
extern const int align_stats_down[9];

extern const int left_length[9];
extern const int align_length_down[9];

extern const int left_temperature[9];
extern const int align_temperature_down[9];

extern const int left_speed[9];
extern const int align_speed_down[9];

extern const int text_size;

extern map<string, float> temperatures;
extern map<const char*, const char*> lengths;
extern map<const char*, float> speeds;