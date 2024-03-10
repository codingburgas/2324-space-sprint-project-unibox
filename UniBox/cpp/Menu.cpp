#include "../Includes/Menu.h"
#include "../Includes/Stats.h"
#include "../Includes/Check.h"
#include "../Includes/Textures.h"
#include "../Includes/Exit.h"
#include "../Includes/RotateDefault.h"
#include "../Includes/ChangeSpeed.h"
#include "../Includes/RemovePlanet.h"
#include "../Includes/AddPlanet.h"
#include <cstdlib>
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
        menu_exit(exit_menu,options_checker);
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
        //change direction move states: check1 == 0 (default), check1 == 1 ( move right), check1 == 2 (move left)  
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[0] && check1 == 0) // if the button is clicked and check1 is 0 (it hasn't been clicked before) the function is applied and check1 becomes 1
        {
            check1 = 1;

        }
        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover[0] && check1 == 1) // if the function has already been clicked (check1 is 1), and it is clicked again it becomes 0
        {
            check1 = 0;

        }

        rotation_default(Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune, Sun);
        change_speed();
        remove_planet(black_hole, cancel_add_planet);

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
        add_planet_show(pluton,cancel_add_planet, add_planet_menu);

    }
}



