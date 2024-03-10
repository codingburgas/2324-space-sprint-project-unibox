#include "../Includes/RemovePlanet.h"
#include "../Includes/Check.h"
void remove_planet(Texture2D black_hole, Texture2D cancel_add_planet)
{
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
}
