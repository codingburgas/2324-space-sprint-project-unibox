#include "../Includes/AddPlanet.h"
#include "../Includes/Check.h"
#include "../Includes/Draw.h"
#include "../Includes/Rotate.h"
#include "../Includes/Pluton.h"
void add_planet_show(Texture2D pluton, Texture2D cancel_add_planet, Texture2D add_planet_menu)
{
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