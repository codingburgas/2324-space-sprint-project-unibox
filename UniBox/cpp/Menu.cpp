#include "../Includes/Menu.h"
#include "../Includes/Stats.h"
#include "../Includes/Convert.h"
#include "../Includes/Check.h"
#include "../Includes/Unload.h"
#include "../Includes/Align.h"
#include "../Includes/Pluton.h"
#include "../Includes/Rotate.h"
#include "../Includes/Draw.h"
#include <cstdlib>
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

        if (show_stats_menu) // check(return 1) if pluton has been drawn on any of the orbits
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
void functions_menu(Texture2D f_menu, Texture2D Checker, Texture2D exit_button, Texture2D checker_exit_button, Texture2D exit_menu, Texture2D options_checker, Texture2D Mercury, Texture2D Venus, Texture2D Earth, Texture2D Mars, Texture2D Jupiter, Texture2D Saturn, Texture2D Uranus, Texture2D Neptune, Texture2D Sun, Texture2D pluton, Texture2D add_planet_menu, Texture2D cancel_add_planet, Texture2D cancel_add_planet_blank, Texture2D black_hole)
{
    DrawTexture(exit_button, 20, 20, WHITE); // draw exit button
    DrawTexture(checker_exit_button, 20, 20, BLANK); // checker

    bool check_exit = CheckCollisionPointRec(GetMousePosition(), { 20,20,(float)checker_exit_button.width,(float)checker_exit_button.height }); // exit button check if it is hovered

    if (any_of(draw_on_orbit.begin(), draw_on_orbit.end(), [](int a) {return a > 0; }))
    {
        show_stats_menu = true;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_exit && check_to_show == 0) // if the button is clicked and check_to_show is 0 (it hasn't been clicked before) the functions are shown and check_to_show becomes 1
    {
        check_to_show = 1;
    }
    else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_exit && check_to_show == 1) // if the button has already been clicked (info_check is 1), and it is clicked again it becomes 0 and the menu is not shown
    {
        check_to_show = 0;
    }
    if (check_to_show == 1) // if the exit button is clicked
    {
        // draw exit menu and make its options usable if it the exit options button is pressed( check_to_show is bigger than 0)

        DrawTexture(exit_menu, 10, 20, WHITE);

        DrawTexture(options_checker, 10, 72, BLANK);
        DrawTexture(options_checker, 10, 145, BLANK);
        DrawTexture(options_checker, 10, 210, BLANK);

        bool options_hover[3] = {
            CheckCollisionPointRec(GetMousePosition(), {10, 72, (float)options_checker.width, (float)options_checker.height}),
            CheckCollisionPointRec(GetMousePosition(), {10, 145, (float)options_checker.width, (float)options_checker.height}),
            CheckCollisionPointRec(GetMousePosition(), {10, 210, (float)options_checker.width, (float)options_checker.height}),
        };
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && options_hover[0])
        {
            check_to_show = 0; // show functions and terminate this part of ther code (continue the game)
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && options_hover[1])
        {
            //unfinished, how to make a new window
            system("C:\\Users\\User\\Pictures\\2324-space-sprint-project-unibox-main\\x64\\Debug");
            exit(0);
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && options_hover[2])
        {
            unload();
            exit(0); // terminate the program

        }

    }
    if (check_to_show == 0) // if the exit button is not clicked or resume exit option is pressed
    {

        DrawTexture(f_menu, 0, 160, WHITE);
        DrawTexture(Checker, 0, 172, BLANK);
        DrawTexture(Checker, 0, 302, BLANK);
        DrawTexture(Checker, 0, 432, BLANK);
        DrawTexture(Checker, 0, 562, BLANK);

        bool check_hover[4] =
        {
            CheckCollisionPointRec(GetMousePosition(), {0, 172, (float)Checker.width, (float)Checker.height}), // check hover change direction
            CheckCollisionPointRec(GetMousePosition(), {0, 302, (float)Checker.width, (float)Checker.height}), // check hover change temperature
            CheckCollisionPointRec(GetMousePosition(), {0, 432, (float)Checker.width, (float)Checker.height}), // check hover black hole
            CheckCollisionPointRec(GetMousePosition(), {0, 562, (float)Checker.width, (float)Checker.height}), // check hover add planet
        }; // check hover on each function button

        //change direction move states: check1 == 0 (default), check1 == 1 ( move right), check1 == 2 (move left)  
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[0] && check1 == 0) // if the button is clicked and check1 is 0 (it hasn't been clicked before) the function is applied and check1 becomes 1
        {
            check1 = 1;

        }
        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[0] && check1 == 1) // if the function has already been clicked (check1 is 1), and it is clicked again it becomes 0
        {
            check1 = 0;

        }
        if (check1 == 1) //left (clicked once)
        {
            DrawTexture(Sun, align_sun::left, align_sun::down, YELLOW);

            if (!black_hole_disappear[0])
                draw_planet_f(Mercury, align_mercury::left, align_mercury::down, align_mercury::angle);
            if (!black_hole_disappear[1])
                draw_planet_f(Venus, align_venus::left, align_venus::down, align_venus::angle);
            if (!black_hole_disappear[2])
                draw_planet_f(Earth, align_earth::left, align_earth::down, align_earth::angle);
            if (!black_hole_disappear[3])
                draw_planet_f(Mars, align_mars::left, align_mars::down, align_mars::angle);
            if (!black_hole_disappear[4])
                draw_planet_f(Jupiter, align_jupiter::left, align_jupiter::down, align_jupiter::angle);
            if (!black_hole_disappear[5])
                draw_planet_f(Saturn, align_saturn::left, align_saturn::down, align_saturn::angle);
            if (!black_hole_disappear[6])
                draw_planet_f(Uranus, align_uranus::left, align_uranus::down, align_uranus::angle);
            if (!black_hole_disappear[7])
                draw_planet_f(Neptune, align_neptune::left, align_neptune::down, align_neptune::angle);


            rotate_planet_back(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed, align_mercury::left, align_mercury::down);

            rotate_planet_back(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed, align_venus::left, align_venus::down);

            rotate_planet_back(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed, align_earth::left, align_earth::down);

            rotate_planet_back(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed, align_mars::left, align_mars::down);

            rotate_planet_back(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed, align_jupiter::left, align_jupiter::down);

            rotate_planet_back(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed, align_saturn::left, align_saturn::down);

            rotate_planet_back(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed, align_uranus::left, align_uranus::down);

            rotate_planet_back(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed, align_neptune::left, align_neptune::down);
        }
        if (check1 == 0) // default (not clicked,right direction )
        {
            DrawTexture(Sun, align_sun::left, align_sun::down, YELLOW);

            if (!black_hole_disappear[0])
                draw_planet_f(Mercury, align_mercury::left, align_mercury::down, align_mercury::angle);
            if (!black_hole_disappear[1])
                draw_planet_f(Venus, align_venus::left, align_venus::down, align_venus::angle);
            if (!black_hole_disappear[2])
                draw_planet_f(Earth, align_earth::left, align_earth::down, align_earth::angle);
            if (!black_hole_disappear[3])
                draw_planet_f(Mars, align_mars::left, align_mars::down, align_mars::angle);
            if (!black_hole_disappear[4])
                draw_planet_f(Jupiter, align_jupiter::left, align_jupiter::down, align_jupiter::angle);
            if (!black_hole_disappear[5])
                draw_planet_f(Saturn, align_saturn::left, align_saturn::down, align_saturn::angle);
            if (!black_hole_disappear[6])
                draw_planet_f(Uranus, align_uranus::left, align_uranus::down, align_uranus::angle);
            if (!black_hole_disappear[7])
                draw_planet_f(Neptune, align_neptune::left, align_neptune::down, align_neptune::angle);

            rotate_planet(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed, align_mercury::left, align_mercury::down);

            rotate_planet(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed, align_venus::left, align_venus::down);

            rotate_planet(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed, align_earth::left, align_earth::down);

            rotate_planet(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed, align_mars::left, align_mars::down);

            rotate_planet(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed, align_jupiter::left, align_jupiter::down);

            rotate_planet(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed, align_saturn::left, align_saturn::down);

            rotate_planet(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed, align_uranus::left, align_uranus::down);

            rotate_planet(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed, align_neptune::left, align_neptune::down);


        }



        // check2 speed change
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[1] && check2 == 0) // if the button is clicked and check2 is 0 (it hasn't been clicked before) the function is applied and check2 becomes 1 and same for the others
        {
            check2 = 1;
            // first click
            speeds["Sun"] += 500.f;
            speeds["Mercury"] += 500.f;
            speeds["Venus"] += 500.f;
            speeds["Earth"] += 500.f;
            speeds["Mars"] += 500.f;
            speeds["Jupiter"] += 500.f;
            speeds["Saturn"] += 500.f;
            speeds["Uranus"] += 500.f;
            speeds["Neptune"] += 500.f;
        }
        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[1] && check2 == 1)
        {
            check2 = 2;
            // second click
            speeds["Sun"] += 500.f;
            speeds["Mercury"] += 500.f;
            speeds["Venus"] += 500.f;
            speeds["Earth"] += 500.f;
            speeds["Mars"] += 500.f;
            speeds["Jupiter"] += 500.f;
            speeds["Saturn"] += 500.f;
            speeds["Uranus"] += 500.f;
            speeds["Neptune"] += 500.f;
        }
        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[1] && check2 == 2)
        {
            check2 = 3;
            // third click
            speeds["Sun"] += 500.f;
            speeds["Mercury"] += 500.f;
            speeds["Venus"] += 500.f;
            speeds["Earth"] += 500.f;
            speeds["Mars"] += 500.f;
            speeds["Jupiter"] += 500.f;
            speeds["Saturn"] += 500.f;
            speeds["Uranus"] += 500.f;
            speeds["Neptune"] += 500.f;
        }
        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[1] && check2 == 3)
        {
            check2 = 0;
            // fourth click(return to default)
            speeds["Sun"] -= 1500.f;
            speeds["Mercury"] -= 1500.f;
            speeds["Venus"] -= 1500.f;
            speeds["Earth"] -= 1500.f;
            speeds["Mars"] -= 1500.f;
            speeds["Jupiter"] -= 1500.f;
            speeds["Saturn"] -= 1500.f;
            speeds["Uranus"] -= 1500.f;
            speeds["Neptune"] -= 1500.f;
        }


        if (check2 == 0)
        {
            //default 

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////fix all////////////////////////////////////////////// and pluton//////////////////////////////////
            if (check1 == 0)// if not clicked right direction, use rotate_point
            {
                rotate_planet(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed, align_mercury::left, align_mercury::down);

                rotate_planet(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed, align_venus::left, align_venus::down);

                rotate_planet(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed, align_earth::left, align_earth::down);

                rotate_planet(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed, align_mars::left, align_mars::down);

                rotate_planet(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed, align_jupiter::left, align_jupiter::down);

                rotate_planet(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed, align_saturn::left, align_saturn::down);

                rotate_planet(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed, align_uranus::left, align_uranus::down);

                rotate_planet(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed, align_neptune::left, align_neptune::down);
            }
            if (check1 == 1) // if clicked left direction, use rotate_point_back 
            {
                rotate_planet_back(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed, align_mercury::left, align_mercury::down);

                rotate_planet_back(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed, align_venus::left, align_venus::down);

                rotate_planet_back(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed, align_earth::left, align_earth::down);

                rotate_planet_back(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed, align_mars::left, align_mars::down);

                rotate_planet_back(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed, align_jupiter::left, align_jupiter::down);

                rotate_planet_back(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed, align_saturn::left, align_saturn::down);

                rotate_planet_back(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed, align_uranus::left, align_uranus::down);

                rotate_planet_back(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed, align_neptune::left, align_neptune::down);
            }

        }

        if (check2 == 1)
        {
            //first click
            if (check1 == 0)
            {
                rotate_planet(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.1f, align_mercury::left, align_mercury::down);

                rotate_planet(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.1f, align_venus::left, align_venus::down);

                rotate_planet(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.1f, align_earth::left, align_earth::down);

                rotate_planet(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.1f, align_mars::left, align_mars::down);

                rotate_planet(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.1f, align_jupiter::left, align_jupiter::down);

                rotate_planet(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.1f, align_saturn::left, align_saturn::down);

                rotate_planet(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.1f, align_uranus::left, align_uranus::down);

                rotate_planet(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.1f, align_neptune::left, align_neptune::down);

            }
            if (check1 == 1)
            {

                rotate_planet_back(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.1f, align_mercury::left, align_mercury::down);

                rotate_planet_back(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.1f, align_venus::left, align_venus::down);

                rotate_planet_back(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.1f, align_earth::left, align_earth::down);

                rotate_planet_back(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.1f, align_mars::left, align_mars::down);

                rotate_planet_back(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.1f, align_jupiter::left, align_jupiter::down);

                rotate_planet_back(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.1f, align_saturn::left, align_saturn::down);

                rotate_planet_back(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.1f, align_uranus::left, align_uranus::down);

                rotate_planet_back(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.1f, align_neptune::left, align_neptune::down);
            }
        }
        if (check2 == 2)
        {
            //first click

            if (check1 == 0)// if not clicked right direction, use rotate_point
            {
                rotate_planet(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.3f, align_mercury::left, align_mercury::down);

                rotate_planet(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.3f, align_venus::left, align_venus::down);

                rotate_planet(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.3f, align_earth::left, align_earth::down);

                rotate_planet(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.3f, align_mars::left, align_mars::down);

                rotate_planet(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.3f, align_jupiter::left, align_jupiter::down);

                rotate_planet(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.3f, align_saturn::left, align_saturn::down);

                rotate_planet(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.3f, align_uranus::left, align_uranus::down);

                rotate_planet(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.3f, align_neptune::left, align_neptune::down);
            }
            if (check1 == 1) // if clicked left direction, use rotate_point_back 
            {
                rotate_planet_back(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.3f, align_mercury::left, align_mercury::down);

                rotate_planet_back(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.3f, align_venus::left, align_venus::down);

                rotate_planet_back(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.3f, align_earth::left, align_earth::down);

                rotate_planet_back(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.3f, align_mars::left, align_mars::down);

                rotate_planet_back(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.3f, align_jupiter::left, align_jupiter::down);

                rotate_planet_back(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.3f, align_saturn::left, align_saturn::down);

                rotate_planet_back(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.3f, align_uranus::left, align_uranus::down);

                rotate_planet_back(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.3f, align_neptune::left, align_neptune::down);

            }

        }

        if (check2 == 3)
        {
            //third click

            if (check1 == 0)// if not clicked right direction, use rotate_point
            {
                rotate_planet(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.5f, align_mercury::left, align_mercury::down);

                rotate_planet(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.5f, align_venus::left, align_venus::down);

                rotate_planet(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.5f, align_earth::left, align_earth::down);

                rotate_planet(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.5f, align_mars::left, align_mars::down);

                rotate_planet(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.5f, align_jupiter::left, align_jupiter::down);

                rotate_planet(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.5f, align_saturn::left, align_saturn::down);

                rotate_planet(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.5f, align_uranus::left, align_uranus::down);

                rotate_planet(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.5f, align_neptune::left, align_neptune::down);
            }
            if (check1 == 1) // if clicked left direction, use rotate_point_back 
            {
                rotate_planet_back(align_mercury::angle, mercury::a, mercury::e, mercury::perihelionAngle, actual_speed::mercury_speed + 0.5f, align_mercury::left, align_mercury::down);

                rotate_planet_back(align_venus::angle, venus::a, venus::e, venus::perihelionAngle, actual_speed::venus_speed + 0.5f, align_venus::left, align_venus::down);

                rotate_planet_back(align_earth::angle, earth::a, earth::e, earth::perihelionAngle, actual_speed::earth_speed + 0.5f, align_earth::left, align_earth::down);

                rotate_planet_back(align_mars::angle, mars::a, mars::e, mars::perihelionAngle, actual_speed::mars_speed + 0.5f, align_mars::left, align_mars::down);

                rotate_planet_back(align_jupiter::angle, jupiter::a, jupiter::e, jupiter::perihelionAngle, actual_speed::jupiter_speed + 0.5f, align_jupiter::left, align_jupiter::down);

                rotate_planet_back(align_saturn::angle, saturn::a, saturn::e, saturn::perihelionAngle, actual_speed::saturn_speed + 0.5f, align_saturn::left, align_saturn::down);

                rotate_planet_back(align_uranus::angle, uranus::a, uranus::e, uranus::perihelionAngle, actual_speed::uranus_speed + 0.5f, align_uranus::left, align_uranus::down);

                rotate_planet_back(align_neptune::angle, neptune::a, neptune::e, neptune::perihelionAngle, actual_speed::neptune_speed + 0.5f, align_neptune::left, align_neptune::down);

            }
        }




        // black hole, check3 and check_hover[2]
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[2] && check3 == 0)
        {// first click
            check3 = 1;
        }
        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[2] && check3 == 1) // if the button is clicked and check4 is 0 (it hasn't been clicked before) the function is applied and check4 becomes 1 
        {
            check3 = 0;
            // second click (close)
        }
        if (check3 == 1)
        {
            DrawTexture(black_hole, 50, 750, WHITE); // black hole menu

            DrawTexture(cancel_add_planet, 60, 780, BLANK); // checker 1
            DrawTexture(cancel_add_planet, 113, 780, BLANK); // checker 2
            DrawTexture(cancel_add_planet, 165, 780, BLANK); // checker 3
            DrawTexture(cancel_add_planet, 219, 780, BLANK); // checker 4
            DrawTexture(cancel_add_planet, 273, 780, BLANK); // checker 5
            DrawTexture(cancel_add_planet, 326, 780, BLANK); // checker 6
            DrawTexture(cancel_add_planet, 378, 780, BLANK); // checker 7
            DrawTexture(cancel_add_planet, 432, 780, BLANK); // checker 8

            bool check_hov[8] = { // checkers for the buttons
                 CheckCollisionPointRec(GetMousePosition(), { 60, 780, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 113, 780, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 165, 780, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 219, 780, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 273, 780, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 326, 780, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 378, 780, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 432, 780, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            };

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hov[0]) // if mercury is selected
            {
                black_hole_disappear[0] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hov[1])
            {
                black_hole_disappear[1] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hov[2])
            {
                black_hole_disappear[2] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hov[3])
            {
                black_hole_disappear[3] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hov[4])
            {
                black_hole_disappear[4] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hov[5])
            {
                black_hole_disappear[5] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hov[6])
            {
                black_hole_disappear[6] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hov[7])
            {
                black_hole_disappear[7] = 1;
            }

        }
        if (all_of(black_hole_disappear.begin(), black_hole_disappear.end(), [](int a) {return a == 1; })) // if all planets are removed(one is left) , all return back
        {
            transform(black_hole_disappear.begin(), black_hole_disappear.end(), black_hole_disappear.begin(), [](int a) { return 0; }); // all return back
        }




        // add planet
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[3] && check4 == 0) // if the button is clicked and check4 is 0 (it hasn't been clicked before) the function is applied and check4 becomes 1 
        {
            check4 = 1;
            // first click
        }
        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[3] && check4 == 1) // if the button is clicked and check4 is 0 (it hasn't been clicked before) the function is applied and check4 becomes 1 
        {
            check4 = 0;
            // second click (close)
        }
        bool check_hover_orbits[8] =
        {
            CheckCollisionPointRec(GetMousePosition(), { 1351, 860, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 1402, 860, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 1453, 860, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 1502, 860, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 1553, 860, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 1603, 860, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 1653, 860, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
            CheckCollisionPointRec(GetMousePosition(), { 1703, 860, (float)cancel_add_planet.width, (float)cancel_add_planet.height }),
        }; // check hover on orbits from 1 to 8

        if (check4 == 1)
        {
            // menu show, add_planet_menu etcetera
            DrawTexture(add_planet_menu, 1346, 376, WHITE); // menu
            DrawTexture(cancel_add_planet, 1705, 379, BLANK); // cancel button
            DrawTexture(cancel_add_planet, 1351, 860, BLANK); // checker 1 orbit
            DrawTexture(cancel_add_planet, 1402, 860, BLANK); // checker 2 orbit         
            DrawTexture(cancel_add_planet, 1453, 860, BLANK); // checker 3 orbit
            DrawTexture(cancel_add_planet, 1502, 860, BLANK); // checker 4 orbit
            DrawTexture(cancel_add_planet, 1553, 860, BLANK); // checker 5 orbit
            DrawTexture(cancel_add_planet, 1603, 860, BLANK); // checker 6 orbit
            DrawTexture(cancel_add_planet, 1653, 860, BLANK); // checker 7 orbit
            DrawTexture(cancel_add_planet, 1703, 860, BLANK); // checker 8 orbit
            DrawText("-173", 1622, 704, 30, WHITE);
            DrawText("2773", 1620, 744, 30, WHITE);
            DrawText("100", 1630, 792, 30, WHITE);
            bool check_hover_cancel = CheckCollisionPointRec(GetMousePosition(), { 1705, 379, (float)cancel_add_planet.width, (float)cancel_add_planet.height }); // check hover cancel button
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_cancel)
            {
                check4 = 0;

            }
            if (info_check == 1) // close add planet menu if info menu(stats menu) is opened 
            {
                check4 = 0;

            }
            //checkers for all the orbit buttons(check if to draw pluton and on each orbit)
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[0] && remove_pluton[0] == 0)
            {
                draw_on_orbit[0] = 1;
                remove_pluton[0] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[0] && remove_pluton[0] == 1)
            {
                draw_on_orbit[0] = 0;
                remove_pluton[0] = 0;
            }


            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[1] && remove_pluton[1] == 0)
            {
                draw_on_orbit[1] = 1;
                remove_pluton[1] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[1] && remove_pluton[1] == 1)
            {
                draw_on_orbit[1] = 0;
                remove_pluton[1] = 0;
            }


            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[2] && remove_pluton[2] == 0)
            {
                draw_on_orbit[2] = 1;
                remove_pluton[2] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[2] && remove_pluton[2] == 1)
            {
                draw_on_orbit[2] = 0;
                remove_pluton[2] = 0;
            }

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[3] && remove_pluton[3] == 0)
            {
                draw_on_orbit[3] = 1;
                remove_pluton[3] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[3] && remove_pluton[3] == 1)
            {
                draw_on_orbit[3] = 0;
                remove_pluton[3] = 0;
            }


            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[4] && remove_pluton[4] == 0)
            {
                draw_on_orbit[4] = 1;
                remove_pluton[4] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[4] && remove_pluton[4] == 1)
            {
                draw_on_orbit[4] = 0;
                remove_pluton[4] = 0;
            }


            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[5] && remove_pluton[5] == 0)
            {
                draw_on_orbit[5] = 1;
                remove_pluton[5] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[5] && remove_pluton[5] == 1)
            {
                draw_on_orbit[5] = 0;
                remove_pluton[5] = 0;
            }


            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[6] && remove_pluton[6] == 0)
            {
                draw_on_orbit[6] = 1;
                remove_pluton[6] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[6] && remove_pluton[6] == 1)
            {
                draw_on_orbit[6] = 0;
                remove_pluton[6] = 0;
            }


            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[7] && remove_pluton[7] == 0)
            {
                draw_on_orbit[7] = 1;
                remove_pluton[7] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_orbits[7] && remove_pluton[7] == 1)
            {
                draw_on_orbit[7] = 0;
                remove_pluton[7] = 0;
            }
        }

        // draw pluton if orbit is clicked
        if (draw_on_orbit[0] == 1)
        {

            draw_planet_f(pluton, left_pluton::left_1, down_pluton::down_1, angle_pluton::angle_1);
            if (check1 == 1) // rotate backward if change direction is pressed
            {
                //change speed if needed, just like in the check2 ifs above but it is put here
                if (check2 == 0)
                    rotate_planet_back(angle_pluton::angle_1, a_pluton::a_1, e_pluton::e_1, peri_pluton::peri_1, speed_pluton::speed_1 / 2, left_pluton::left_1, down_pluton::down_1);
                else if (check2 == 1)
                    rotate_planet_back(angle_pluton::angle_1, a_pluton::a_1, e_pluton::e_1, peri_pluton::peri_1, speed_pluton::speed_1 / 2 + 0.5f, left_pluton::left_1, down_pluton::down_1);
                else if (check2 == 2)
                    rotate_planet_back(angle_pluton::angle_1, a_pluton::a_1, e_pluton::e_1, peri_pluton::peri_1, speed_pluton::speed_1 / 2 + 1.f, left_pluton::left_1, down_pluton::down_1);
                else if (check2 == 3)
                    rotate_planet_back(angle_pluton::angle_1, a_pluton::a_1, e_pluton::e_1, peri_pluton::peri_1, speed_pluton::speed_1 / 2 + 1.5f, left_pluton::left_1, down_pluton::down_1);
            }
            if (check1 == 0) // rotate forward if change direction is pressed
            {
                if (check2 == 0)
                    rotate_planet(angle_pluton::angle_1, a_pluton::a_1, e_pluton::e_1, peri_pluton::peri_1, speed_pluton::speed_1 / 2, left_pluton::left_1, down_pluton::down_1);
                else if (check2 == 1)
                    rotate_planet(angle_pluton::angle_1, a_pluton::a_1, e_pluton::e_1, peri_pluton::peri_1, speed_pluton::speed_1 / 2 + 0.5f, left_pluton::left_1, down_pluton::down_1);
                else if (check2 == 2)
                    rotate_planet(angle_pluton::angle_1, a_pluton::a_1, e_pluton::e_1, peri_pluton::peri_1, speed_pluton::speed_1 / 2 + 1.f, left_pluton::left_1, down_pluton::down_1);
                else if (check2 == 3)
                    rotate_planet(angle_pluton::angle_1, a_pluton::a_1, e_pluton::e_1, peri_pluton::peri_1, speed_pluton::speed_1 / 2 + 1.5f, left_pluton::left_1, down_pluton::down_1);
            }

        }
        if (draw_on_orbit[1] == 1)
        {

            draw_planet_f(pluton, left_pluton::left_2, down_pluton::down_2, angle_pluton::angle_2);
            if (check1 == 1) // rotate backward if change direction is pressed
            {
                if (check2 == 0)
                    rotate_planet_back(angle_pluton::angle_2, a_pluton::a_2, e_pluton::e_2, peri_pluton::peri_2, speed_pluton::speed_2 / 2, left_pluton::left_2, down_pluton::down_2);
                else if (check2 == 1)
                    rotate_planet_back(angle_pluton::angle_2, a_pluton::a_2, e_pluton::e_2, peri_pluton::peri_2, speed_pluton::speed_2 / 2 + 0.5f, left_pluton::left_2, down_pluton::down_2);
                else if (check2 == 2)
                    rotate_planet_back(angle_pluton::angle_2, a_pluton::a_2, e_pluton::e_2, peri_pluton::peri_2, speed_pluton::speed_2 / 2 + 1.f, left_pluton::left_2, down_pluton::down_2);
                else if (check2 == 3)
                    rotate_planet_back(angle_pluton::angle_2, a_pluton::a_2, e_pluton::e_2, peri_pluton::peri_2, speed_pluton::speed_2 / 2 + 1.5f, left_pluton::left_2, down_pluton::down_2);
            }
            if (check1 == 0) // rotate forward if change direction is pressed
            {
                if (check2 == 0)
                    rotate_planet(angle_pluton::angle_2, a_pluton::a_2, e_pluton::e_2, peri_pluton::peri_2, speed_pluton::speed_2 / 2, left_pluton::left_2, down_pluton::down_2);
                else if (check2 == 1)
                    rotate_planet(angle_pluton::angle_2, a_pluton::a_2, e_pluton::e_2, peri_pluton::peri_2, speed_pluton::speed_2 / 2 + 0.5f, left_pluton::left_2, down_pluton::down_2);
                else if (check2 == 2)
                    rotate_planet(angle_pluton::angle_2, a_pluton::a_2, e_pluton::e_2, peri_pluton::peri_2, speed_pluton::speed_2 / 2 + 1.f, left_pluton::left_2, down_pluton::down_2);
                else if (check2 == 3)
                    rotate_planet(angle_pluton::angle_2, a_pluton::a_2, e_pluton::e_2, peri_pluton::peri_2, speed_pluton::speed_2 / 2 + 1.5f, left_pluton::left_2, down_pluton::down_2);
            }

        }
        if (draw_on_orbit[2] == 1)
        {


            draw_planet_f(pluton, left_pluton::left_3, down_pluton::down_3, angle_pluton::angle_3);
            if (check1 == 1) // rotate backward if change direction is pressed
            {
                if (check2 == 0)
                    rotate_planet_back(angle_pluton::angle_3, a_pluton::a_3, e_pluton::e_3, peri_pluton::peri_3, speed_pluton::speed_3 / 2, left_pluton::left_3, down_pluton::down_3);
                else if (check2 == 1)
                    rotate_planet_back(angle_pluton::angle_3, a_pluton::a_3, e_pluton::e_3, peri_pluton::peri_3, speed_pluton::speed_3 / 2 + 0.5f, left_pluton::left_3, down_pluton::down_3);
                else if (check2 == 2)
                    rotate_planet_back(angle_pluton::angle_3, a_pluton::a_3, e_pluton::e_3, peri_pluton::peri_3, speed_pluton::speed_3 / 2 + 1.f, left_pluton::left_3, down_pluton::down_3);
                else if (check2 == 3)
                    rotate_planet_back(angle_pluton::angle_3, a_pluton::a_3, e_pluton::e_3, peri_pluton::peri_3, speed_pluton::speed_3 / 2 + 1.5f, left_pluton::left_3, down_pluton::down_3);
            }
            if (check1 == 0) // rotate forward if change direction is pressed
            {
                if (check2 == 0)
                    rotate_planet(angle_pluton::angle_3, a_pluton::a_3, e_pluton::e_3, peri_pluton::peri_3, speed_pluton::speed_3 / 2, left_pluton::left_3, down_pluton::down_3);
                else if (check2 == 1)
                    rotate_planet(angle_pluton::angle_3, a_pluton::a_3, e_pluton::e_3, peri_pluton::peri_3, speed_pluton::speed_3 / 2 + 0.5f, left_pluton::left_3, down_pluton::down_3);
                else if (check2 == 2)
                    rotate_planet(angle_pluton::angle_3, a_pluton::a_3, e_pluton::e_3, peri_pluton::peri_3, speed_pluton::speed_3 / 2 + 1.f, left_pluton::left_3, down_pluton::down_3);
                else if (check2 == 3)
                    rotate_planet(angle_pluton::angle_3, a_pluton::a_3, e_pluton::e_3, peri_pluton::peri_3, speed_pluton::speed_3 / 2 + 1.5f, left_pluton::left_3, down_pluton::down_3);
            }
        }
        if (draw_on_orbit[3] == 1)
        {


            draw_planet_f(pluton, left_pluton::left_4, down_pluton::down_4, angle_pluton::angle_4);
            if (check1 == 1) // rotate backward if change direction is pressed
            {

                if (check2 == 0)
                    rotate_planet_back(angle_pluton::angle_4, a_pluton::a_4, e_pluton::e_4, peri_pluton::peri_4, speed_pluton::speed_4 / 2, left_pluton::left_4, down_pluton::down_4);
                else if (check2 == 1)
                    rotate_planet_back(angle_pluton::angle_4, a_pluton::a_4, e_pluton::e_4, peri_pluton::peri_4, speed_pluton::speed_4 / 2 + 0.5f, left_pluton::left_4, down_pluton::down_4);
                else if (check2 == 2)
                    rotate_planet_back(angle_pluton::angle_4, a_pluton::a_4, e_pluton::e_4, peri_pluton::peri_4, speed_pluton::speed_4 / 2 + 1.f, left_pluton::left_4, down_pluton::down_4);
                else if (check2 == 3)
                    rotate_planet_back(angle_pluton::angle_4, a_pluton::a_4, e_pluton::e_4, peri_pluton::peri_4, speed_pluton::speed_4 / 2 + 1.5f, left_pluton::left_4, down_pluton::down_4);
            }
            if (check1 == 0) // rotate forward if change direction is pressed
            {
                if (check2 == 0)
                    rotate_planet(angle_pluton::angle_4, a_pluton::a_4, e_pluton::e_4, peri_pluton::peri_4, speed_pluton::speed_4 / 2, left_pluton::left_4, down_pluton::down_4);
                else if (check2 == 1)
                    rotate_planet(angle_pluton::angle_4, a_pluton::a_4, e_pluton::e_4, peri_pluton::peri_4, speed_pluton::speed_4 / 2 + 0.5f, left_pluton::left_4, down_pluton::down_4);
                else if (check2 == 2)
                    rotate_planet(angle_pluton::angle_4, a_pluton::a_4, e_pluton::e_4, peri_pluton::peri_4, speed_pluton::speed_4 / 2 + 1.f, left_pluton::left_4, down_pluton::down_4);
                else if (check2 == 3)
                    rotate_planet(angle_pluton::angle_4, a_pluton::a_4, e_pluton::e_4, peri_pluton::peri_4, speed_pluton::speed_4 / 2 + 1.5f, left_pluton::left_4, down_pluton::down_4);
            }
        }
        if (draw_on_orbit[4] == 1)
        {


            draw_planet_f(pluton, left_pluton::left_5, down_pluton::down_5, angle_pluton::angle_5);
            if (check1 == 1) // rotate backward if change direction is pressed
            {

                if (check2 == 0)
                    rotate_planet_back(angle_pluton::angle_5, a_pluton::a_5, e_pluton::e_5, peri_pluton::peri_5, speed_pluton::speed_5 / 2, left_pluton::left_5, down_pluton::down_5);
                else if (check2 == 1)
                    rotate_planet_back(angle_pluton::angle_5, a_pluton::a_5, e_pluton::e_5, peri_pluton::peri_5, speed_pluton::speed_5 / 2 + 0.5f, left_pluton::left_5, down_pluton::down_5);
                else if (check2 == 2)
                    rotate_planet_back(angle_pluton::angle_5, a_pluton::a_5, e_pluton::e_5, peri_pluton::peri_5, speed_pluton::speed_5 / 2 + 1.f, left_pluton::left_5, down_pluton::down_5);
                else if (check2 == 3)
                    rotate_planet_back(angle_pluton::angle_5, a_pluton::a_5, e_pluton::e_5, peri_pluton::peri_5, speed_pluton::speed_5 / 2 + 1.5f, left_pluton::left_5, down_pluton::down_5);
            }
            if (check1 == 0) // rotate forward if change direction is pressed
            {
                if (check2 == 0)
                    rotate_planet(angle_pluton::angle_5, a_pluton::a_5, e_pluton::e_5, peri_pluton::peri_5, speed_pluton::speed_5 / 2, left_pluton::left_5, down_pluton::down_5);
                else if (check2 == 1)
                    rotate_planet(angle_pluton::angle_5, a_pluton::a_5, e_pluton::e_5, peri_pluton::peri_5, speed_pluton::speed_5 / 2 + 0.5f, left_pluton::left_5, down_pluton::down_5);
                else if (check2 == 2)
                    rotate_planet(angle_pluton::angle_5, a_pluton::a_5, e_pluton::e_5, peri_pluton::peri_5, speed_pluton::speed_5 / 2 + 1.f, left_pluton::left_5, down_pluton::down_5);
                else if (check2 == 3)
                    rotate_planet(angle_pluton::angle_5, a_pluton::a_5, e_pluton::e_5, peri_pluton::peri_5, speed_pluton::speed_5 / 2 + 1.5f, left_pluton::left_5, down_pluton::down_5);
            }
        }

        if (draw_on_orbit[5] == 1)
        {


            draw_planet_f(pluton, left_pluton::left_6, down_pluton::down_6, angle_pluton::angle_6);
            if (check1 == 1) // rotate backward if change direction is pressed
            {

                if (check2 == 0)
                    rotate_planet_back(angle_pluton::angle_6, a_pluton::a_6, e_pluton::e_6, peri_pluton::peri_6, speed_pluton::speed_6 / 2, left_pluton::left_6, down_pluton::down_6);
                else if (check2 == 1)
                    rotate_planet_back(angle_pluton::angle_6, a_pluton::a_6, e_pluton::e_6, peri_pluton::peri_6, speed_pluton::speed_6 / 2 + 0.5f, left_pluton::left_6, down_pluton::down_6);
                else if (check2 == 2)
                    rotate_planet_back(angle_pluton::angle_6, a_pluton::a_6, e_pluton::e_6, peri_pluton::peri_6, speed_pluton::speed_6 / 2 + 1.f, left_pluton::left_6, down_pluton::down_6);
                else if (check2 == 3)
                    rotate_planet_back(angle_pluton::angle_6, a_pluton::a_6, e_pluton::e_6, peri_pluton::peri_6, speed_pluton::speed_6 / 2 + 1.5f, left_pluton::left_6, down_pluton::down_6);

            }
            if (check1 == 0) // rotate forward if change direction is pressed
            {
                if (check2 == 0)
                    rotate_planet(angle_pluton::angle_6, a_pluton::a_6, e_pluton::e_6, peri_pluton::peri_6, speed_pluton::speed_6 / 2, left_pluton::left_6, down_pluton::down_6);
                else if (check2 == 1)
                    rotate_planet(angle_pluton::angle_6, a_pluton::a_6, e_pluton::e_6, peri_pluton::peri_6, speed_pluton::speed_6 / 2 + 0.5f, left_pluton::left_6, down_pluton::down_6);
                else if (check2 == 2)
                    rotate_planet(angle_pluton::angle_6, a_pluton::a_6, e_pluton::e_6, peri_pluton::peri_6, speed_pluton::speed_6 / 2 + 1.f, left_pluton::left_6, down_pluton::down_6);
                else if (check2 == 3)
                    rotate_planet(angle_pluton::angle_6, a_pluton::a_6, e_pluton::e_6, peri_pluton::peri_6, speed_pluton::speed_6 / 2 + 1.5f, left_pluton::left_6, down_pluton::down_6);
            }
        }
        if (draw_on_orbit[6] == 1)
        {


            draw_planet_f(pluton, left_pluton::left_7, down_pluton::down_7, angle_pluton::angle_7);
            if (check1 == 1) // rotate backward if change direction is pressed
            {

                if (check2 == 0)
                    rotate_planet_back(angle_pluton::angle_7, a_pluton::a_7, e_pluton::e_7, peri_pluton::peri_7, speed_pluton::speed_7, left_pluton::left_7, down_pluton::down_7);
                else if (check2 == 1)
                    rotate_planet_back(angle_pluton::angle_7, a_pluton::a_7, e_pluton::e_7, peri_pluton::peri_7, speed_pluton::speed_7 + 0.5f, left_pluton::left_7, down_pluton::down_7);
                else if (check2 == 2)
                    rotate_planet_back(angle_pluton::angle_7, a_pluton::a_7, e_pluton::e_7, peri_pluton::peri_7, speed_pluton::speed_7 + 1.f, left_pluton::left_7, down_pluton::down_7);
                else if (check2 == 3)
                    rotate_planet_back(angle_pluton::angle_7, a_pluton::a_7, e_pluton::e_7, peri_pluton::peri_7, speed_pluton::speed_7 + 1.5f, left_pluton::left_7, down_pluton::down_7);
            }
            if (check1 == 0) // rotate forward if change direction is pressed
            {
                if (check2 == 0)
                    rotate_planet(angle_pluton::angle_7, a_pluton::a_7, e_pluton::e_7, peri_pluton::peri_7, speed_pluton::speed_7, left_pluton::left_7, down_pluton::down_7);
                else if (check2 == 1)
                    rotate_planet(angle_pluton::angle_7, a_pluton::a_7, e_pluton::e_7, peri_pluton::peri_7, speed_pluton::speed_7 + 0.5f, left_pluton::left_7, down_pluton::down_7);
                else if (check2 == 2)
                    rotate_planet(angle_pluton::angle_7, a_pluton::a_7, e_pluton::e_7, peri_pluton::peri_7, speed_pluton::speed_7 + 1.f, left_pluton::left_7, down_pluton::down_7);
                else if (check2 == 3)
                    rotate_planet(angle_pluton::angle_7, a_pluton::a_7, e_pluton::e_7, peri_pluton::peri_7, speed_pluton::speed_7 + 1.5f, left_pluton::left_7, down_pluton::down_7);
            }

        }
        if (draw_on_orbit[7] == 1)
        {


            draw_planet_f(pluton, left_pluton::left_8, down_pluton::down_8, angle_pluton::angle_8);
            if (check1 == 1) // rotate backward if change direction is pressed
            {
                if (check2 == 0)
                    rotate_planet_back(angle_pluton::angle_8, a_pluton::a_8, e_pluton::e_8, peri_pluton::peri_8, speed_pluton::speed_8 / 2, left_pluton::left_8, down_pluton::down_8);
                else if (check2 == 1)
                    rotate_planet_back(angle_pluton::angle_8, a_pluton::a_8, e_pluton::e_8, peri_pluton::peri_8, speed_pluton::speed_8 / 2 + 0.5f, left_pluton::left_8, down_pluton::down_8);
                else if (check2 == 2)
                    rotate_planet_back(angle_pluton::angle_8, a_pluton::a_8, e_pluton::e_8, peri_pluton::peri_8, speed_pluton::speed_8 / 2 + 1.f, left_pluton::left_8, down_pluton::down_8);
                else if (check2 == 3)
                    rotate_planet_back(angle_pluton::angle_8, a_pluton::a_8, e_pluton::e_8, peri_pluton::peri_8, speed_pluton::speed_8 / 2 + 1.5f, left_pluton::left_8, down_pluton::down_8);
            }
            if (check1 == 0) // rotate forward if change direction is pressed
            {
                if (check2 == 0)
                    rotate_planet(angle_pluton::angle_8, a_pluton::a_8, e_pluton::e_8, peri_pluton::peri_8, speed_pluton::speed_8 / 2, left_pluton::left_8, down_pluton::down_8);
                else if (check2 == 1)
                    rotate_planet(angle_pluton::angle_8, a_pluton::a_8, e_pluton::e_8, peri_pluton::peri_8, speed_pluton::speed_8 / 2 + 0.5f, left_pluton::left_8, down_pluton::down_8);
                else if (check2 == 2)
                    rotate_planet(angle_pluton::angle_8, a_pluton::a_8, e_pluton::e_8, peri_pluton::peri_8, speed_pluton::speed_8 / 2 + 1.f, left_pluton::left_8, down_pluton::down_8);
                else if (check2 == 3)
                    rotate_planet(angle_pluton::angle_8, a_pluton::a_8, e_pluton::e_8, peri_pluton::peri_8, speed_pluton::speed_8 / 2 + 1.5f, left_pluton::left_8, down_pluton::down_8);
            }

        }

    }
}


