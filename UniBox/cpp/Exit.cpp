#include "../Includes/Exit.h"
#include "../Includes/Textures.h"
#include "../Includes/Check.h"
#include <cstdlib>
void menu_exit(Texture2D exit_menu,Texture2D options_checker)
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