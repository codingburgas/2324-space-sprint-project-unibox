#include "Includes/Unibox.h"
int main()
{
    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Unibox"); // set screen size and name of .exe file
    load();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawTexture(start, 0, 0, WHITE); // background screen 
        DrawTexture(new_game, 710, 500, WHITE); // new game button
        DrawTexture(quit, 814, 620, WHITE); // quit button


        bool hover_new_game = CheckCollisionPointRec(GetMousePosition(), // checker if new game button is hovered
            { 710, 500, (float)new_game.width, (float)new_game.height }); // 710 is left align, 500 is down align

        bool hover_quit = CheckCollisionPointRec(GetMousePosition(), // checker if quit button is hovered
            { 814, 620, (float)quit.width, (float)quit.height }); // 814 is left align, 620 is down align

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover_new_game)
        {
            break; // continue to the game if the new game button is pressed
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover_quit)
        {
            unload();
            return 0; // end the program if the quit button is pressed
        }
        
        EndDrawing();

    }
    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(BLACK); // black background by default

        DrawTexture(background, 5, 0, WHITE); // galaxy background

        // draw orbit of each
        draw_orbit_all();

        stats_show(blank_info, menu, stats, checker, info, pluton_in_stats);
        functions_menu(functions, Checker, exit_button, checker_exit_button, exit_menu, options_checker, Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune, Sun, pluton, add_planet_menu, cancel_add_planet, cancel_add_planet_blank,black_hole);
      
        EndDrawing();
    }
    unload(); 
}


  


  

    
   
   
    


        


        
  
