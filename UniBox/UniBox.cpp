#include "Includes/Unibox.h"
#include "Includes/Unload.h"
int main()
{
    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Unibox"); // set screen size and name of .exe file
    background = LoadTexture("Images/galaxy.png"); // galaxy background
    stats = LoadTexture("Images/stats.png"); // show stats of pressed planet
    Sun = LoadTexture("Images/sun100x100.png"); // sun picture
    Mercury = LoadTexture("Images/mercury45x45.png"); // mercury picture
    Venus = LoadTexture("Images/venus50x50.png"); // venus picture
    Earth = LoadTexture("Images/earth47x47.png"); // earth picture
    Mars = LoadTexture("Images/mars48x48.png"); // mars picture
    Jupiter = LoadTexture("Images/jupiter49x49.png"); // jupiter picture
    Saturn = LoadTexture("Images/saturn121x138.png"); // saturn image
    Uranus = LoadTexture("Images/uranus53x52.png"); // uranus image
    Neptune = LoadTexture("Images/neptune70x128.png"); // neptune image
    blank_info = LoadTexture("Images/blank_info.png"); // cancel stats button blank
    start = LoadTexture("Images/start_screen.png"); // start menu screen
    new_game = LoadTexture("Images/new_game_button.png"); // new game button
    quit = LoadTexture("Images/quit_button.png"); // quit button
    info = LoadTexture("Images/stats_icon.png"); // stats info button
    menu = LoadTexture("Images/stats_menu.png"); // stats menu picture
    functions = LoadTexture("Images/functions_menu.png"); // function options on the left
    checker = LoadTexture("Images/rectangle46.png");
    Checker = LoadTexture("Images/rectangle49.png"); // functions buttons checker
    exit_button = LoadTexture("Images/exit_options.png"); // exit button texture
    checker_exit_button = LoadTexture("Images/checker_exit.png"); // checker to see if exit options are pressed   
    exit_menu = LoadTexture("Images/exit_menu.png"); // exit menu options
    options_checker = LoadTexture("Images/exit_options_checker.png");// checker if any of the exit options are checked
    pluton = LoadTexture("Images/pluton.png"); // pluton picture    
    add_planet_menu = LoadTexture("Images/add_planet_menu2.png"); // add planet menu
    cancel_add_planet = LoadTexture("Images/cancel_button.png");// cancel button
    cancel_add_planet_blank = LoadTexture("Images/add_planet_cancel_blank_button.png"); // blank for cancel button
    pluton_in_stats = LoadTexture("Images/mercury_in_stats_menu.png"); // pluton stats 
    black_hole = LoadTexture("Images/black_hole_menu.png"); // black hole menu with planets to choose
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
void unload()
{
    // unload the textures
    UnloadTexture(background);
    UnloadTexture(stats);
    UnloadTexture(Sun);
    UnloadTexture(Mercury);
    UnloadTexture(Venus);
    UnloadTexture(Earth);
    UnloadTexture(Mars);
    UnloadTexture(Jupiter);
    UnloadTexture(Saturn);
    UnloadTexture(Uranus);
    UnloadTexture(Neptune);
    UnloadTexture(blank_info);
    UnloadTexture(start);
    UnloadTexture(new_game);
    UnloadTexture(quit);
    UnloadTexture(info);
    UnloadTexture(menu);
    UnloadTexture(functions);
    UnloadTexture(checker);
    UnloadTexture(Checker);
    UnloadTexture(exit_button);
    UnloadTexture(checker_exit_button);
    UnloadTexture(exit_menu);
    UnloadTexture(options_checker);
    UnloadTexture(pluton);
    UnloadTexture(add_planet_menu);
    UnloadTexture(cancel_add_planet);
    UnloadTexture(cancel_add_planet_blank);
    UnloadTexture(pluton_in_stats);
    UnloadTexture(black_hole);
}


  


  

    
   
   
    


        


        
  
