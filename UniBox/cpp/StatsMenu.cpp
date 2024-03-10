#include "../Includes/Stats.h"
#include "../Includes/StatsMenu.h"
#include "../Includes/Check.h"
#include "../Includes/Convert.h"
void stats_show(Texture2D blank_info, Texture2D menu, Texture2D Stats, Texture2D checker, Texture2D info, Texture2D pluton_in_stats)
{
    // checker is a rectangle texture which is used to check if we are hovering on the following options

    bool check_hover_info = CheckCollisionPointRec(GetMousePosition(), { 1665, 20, (float)blank_info.width, (float)blank_info.height });

    DrawTexture(info, 1665, 20, WHITE); // draw info button, 1665 is left(x) and 20 is down(y)

    DrawTexture(blank_info, 1665, 20, BLANK); // use this texture as an invisible filler, so that the info button works

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_info && info_check == 0) // if the button is clicked and info_check is 0 (it hasn't been clicked before) the menu is shown and info_check becomes 1
    {
        info_check = 1;
    }
    else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_info && info_check == 1) // if the button has already been clicked (info_check is 1), and it is clicked again it becomes 0 and the menu is not shown
    {
        info_check = 0;
    }
    if (info_check == 1)
    {
        DrawTexture(menu, 1530, 95, WHITE);

        DrawTexture(checker, 1557, 97, BLANK); // checker sun 1

        DrawTexture(checker, 1557, 155, BLANK); //checker mercury 2

        DrawTexture(checker, 1557, 215, BLANK); // checker venus 3

        DrawTexture(checker, 1557, 275, BLANK); // checker earth 4

        DrawTexture(checker, 1557, 335, BLANK); // checker mars 5

        DrawTexture(checker, 1557, 395, BLANK); // cheker jupiter 6

        DrawTexture(checker, 1557, 445, BLANK); // checker saturn 7

        DrawTexture(checker, 1557, 505, BLANK); // checker uranus 8

        DrawTexture(checker, 1557, 565, BLANK); // checker neptune 9

        if (any_of(draw_on_orbit.begin(), draw_on_orbit.end(), [](int a) {return a > 0; })) // check(return 1) if pluton has been drawn on any of the orbits
        {
            DrawTexture(pluton_in_stats, 1557, 625, WHITE);
            bool hover_pluton = CheckCollisionPointRec(GetMousePosition(), { 1557, 625, (float)pluton_in_stats.width, (float)pluton_in_stats.height });
            if (hover_pluton)
            {
                if (check2 == 0)
                {
                    DrawTexture(Stats, left_stats, align_stats_down[8] + 51, RAYWHITE);
                    DrawText("-173", left_temperature[7] + 5, align_temperature_down[7] + 60 + 51, text_size, WHITE);
                    DrawText("2337km", left_length[7] + 10, align_length_down[7] + 60 + 51, text_size, WHITE);
                    DrawText("100", left_speed[7] + 20, align_speed_down[7] + 60 + 51, text_size, WHITE);
                }
                if (check2 == 1)
                {
                    DrawTexture(Stats, left_stats, align_stats_down[8] + 51, RAYWHITE);
                    DrawText("-173", left_temperature[7] + 5, align_temperature_down[7] + 60 + 51, text_size, WHITE);
                    DrawText("2337km", left_length[7] + 10, align_length_down[7] + 60 + 51, text_size, WHITE);
                    DrawText("600", left_speed[7] + 20, align_speed_down[7] + 60 + 51, text_size, WHITE);
                }
                if (check2 == 2)
                {
                    DrawTexture(Stats, left_stats, align_stats_down[8] + 51, RAYWHITE);
                    DrawText("-173", left_temperature[7] + 5, align_temperature_down[7] + 60 + 51, text_size, WHITE);
                    DrawText("2337km", left_length[7] + 10, align_length_down[7] + 60 + 51, text_size, WHITE);
                    DrawText("1100", left_speed[7] + 16, align_speed_down[7] + 60 + 51, text_size, WHITE);
                }
                if (check2 == 3)
                {
                    DrawTexture(Stats, left_stats, align_stats_down[8] + 51, RAYWHITE);
                    DrawText("-173", left_temperature[7] + 5, align_temperature_down[7] + 60 + 51, text_size, WHITE);
                    DrawText("2337km", left_length[7] + 10, align_length_down[7] + 60 + 51, text_size, WHITE);
                    DrawText("1600", left_speed[7] + 12, align_speed_down[7] + 60 + 51, text_size, WHITE);
                }

            }
        }
        bool hover[9] = {
        CheckCollisionPointRec(GetMousePosition(), {1557, 97, (float)checker.width, (float)checker.height}), // check hover sun
        CheckCollisionPointRec(GetMousePosition(), {1557, 155, (float)checker.width, (float)checker.height}), // check hover mercury
        CheckCollisionPointRec(GetMousePosition(), {1557, 215, (float)checker.width, (float)checker.height}), // check hover venus
        CheckCollisionPointRec(GetMousePosition(), {1557, 275, (float)checker.width, (float)checker.height}), // check hover earth
        CheckCollisionPointRec(GetMousePosition(), {1557, 335, (float)checker.width, (float)checker.height}), // check hover mars
        CheckCollisionPointRec(GetMousePosition(), {1557, 395, (float)checker.width, (float)checker.height}), // check hover jupiter
        CheckCollisionPointRec(GetMousePosition(), {1557, 445, (float)checker.width, (float)checker.height}), // check hover saturn
        CheckCollisionPointRec(GetMousePosition(), {1557, 505, (float)checker.width, (float)checker.height}), // check hover uranus
        CheckCollisionPointRec(GetMousePosition(), {1557, 565, (float)checker.width, (float)checker.height}), // check hover neptune
        };
        if (hover[0]) // hover on sun
        {
            DrawTexture(Stats, left_stats, align_stats_down[0], RAYWHITE);
            DrawText(convert_float_to_str(temperatures["Sun"]).c_str(), left_temperature[0], align_temperature_down[0], text_size, WHITE); // c_str converts string to const char* 
            DrawText(lengths["Sun"], left_length[0], align_length_down[0], text_size, WHITE);
            DrawText(convert_float_to_str(speeds["Sun"]).c_str(), left_speed[0], align_speed_down[0], text_size, WHITE);

        }
        else if (hover[1]) // hover on mercury
        {
            DrawTexture(Stats, left_stats, align_stats_down[1], RAYWHITE);
            DrawText(convert_float_to_str(temperatures["Mercury"]).c_str(), left_temperature[1], align_temperature_down[1], text_size, WHITE);
            DrawText(lengths["Mercury"], left_length[1], align_length_down[1], text_size, WHITE);
            DrawText(convert_float_to_str(speeds["Mercury"]).c_str(), left_speed[1], align_speed_down[1], text_size, WHITE);
        }
        else if (hover[2]) // hover on venus
        {
            DrawTexture(Stats, left_stats, align_stats_down[2], RAYWHITE);
            DrawText(convert_float_to_str(temperatures["Venus"]).c_str(), left_temperature[2], align_temperature_down[2], text_size, WHITE);
            DrawText(lengths["Venus"], left_length[2], align_length_down[2], text_size, WHITE);
            DrawText(convert_float_to_str(speeds["Venus"]).c_str(), left_speed[2], align_speed_down[2], text_size, WHITE);
        }
        else if (hover[3]) // hover on earth
        {
            DrawTexture(Stats, left_stats, align_stats_down[3], RAYWHITE);
            DrawText(convert_float_to_str(temperatures["Earth"]).c_str(), left_temperature[3], align_temperature_down[3], text_size, WHITE);
            DrawText(lengths["Earth"], left_length[3], align_length_down[3], text_size, WHITE);
            DrawText(convert_float_to_str(speeds["Earth"]).c_str(), left_speed[3], align_speed_down[3], text_size, WHITE);
        }
        else if (hover[4]) // hover on mars
        {
            DrawTexture(Stats, left_stats, align_stats_down[4], RAYWHITE);
            DrawText(convert_float_to_str(temperatures["Mars"]).c_str(), left_temperature[4], align_temperature_down[4], text_size, WHITE);
            DrawText(lengths["Mars"], left_length[4], align_length_down[4], text_size, WHITE);
            DrawText(convert_float_to_str(speeds["Mars"]).c_str(), left_speed[4], align_speed_down[4], text_size, WHITE);
        }
        else if (hover[5]) // hover on jupiter
        {
            DrawTexture(Stats, left_stats, align_stats_down[5], RAYWHITE);
            DrawText(convert_float_to_str(temperatures["Jupiter"]).c_str(), left_temperature[5], align_temperature_down[5], text_size, WHITE);
            DrawText(lengths["Jupiter"], left_length[5], align_length_down[5], text_size, WHITE);
            DrawText(convert_float_to_str(speeds["Jupiter"]).c_str(), left_speed[5], align_speed_down[5], text_size, WHITE);
        }
        else if (hover[6]) // hover on saturn
        {
            DrawTexture(Stats, left_stats, align_stats_down[6], RAYWHITE);
            DrawText(convert_float_to_str(temperatures["Saturn"]).c_str(), left_temperature[6], align_temperature_down[6], text_size, WHITE);
            DrawText(lengths["Saturn"], left_length[6], align_length_down[6], text_size, WHITE);
            DrawText(convert_float_to_str(speeds["Saturn"]).c_str(), left_speed[6], align_speed_down[6], text_size, WHITE);

        }
        else if (hover[7]) // hover on uranus
        {
            DrawTexture(Stats, left_stats, align_stats_down[7], RAYWHITE);
            DrawText(convert_float_to_str(temperatures["Uranus"]).c_str(), left_temperature[7], align_temperature_down[7], text_size, WHITE);
            DrawText(lengths["Uranus"], left_length[7], align_length_down[7], text_size, WHITE);
            DrawText(convert_float_to_str(speeds["Uranus"]).c_str(), left_speed[7], align_speed_down[7], text_size, WHITE);
        }
        else if (hover[8]) // hover on neptune
        {
            DrawTexture(Stats, left_stats, align_stats_down[8], RAYWHITE);
            DrawText(convert_float_to_str(temperatures["Neptune"]).c_str(), left_temperature[8], align_temperature_down[8], text_size, WHITE);
            DrawText(lengths["Neptune"], left_length[8], align_length_down[8], text_size, WHITE);
            DrawText(convert_float_to_str(speeds["Neptune"]).c_str(), left_speed[8], align_speed_down[8], text_size, WHITE);
        }
    }

}