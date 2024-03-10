#include "../Includes/Textures.h"

Texture2D background;
Texture2D stats;
Texture2D Sun;
Texture2D Mercury;
Texture2D Venus;
Texture2D Earth;
Texture2D Mars;
Texture2D Jupiter;
Texture2D Saturn;
Texture2D Uranus;
Texture2D Neptune;
Texture2D blank_info;
Texture2D start;
Texture2D new_game;
Texture2D quit;
Texture2D info;
Texture2D menu;
Texture2D functions;
Texture2D checker;
Texture2D Checker;
Texture2D exit_button;
Texture2D checker_exit_button;
Texture2D exit_menu;
Texture2D options_checker;
Texture2D pluton;
Texture2D add_planet_menu;
Texture2D cancel_add_planet;
Texture2D cancel_add_planet_blank;
Texture2D pluton_in_stats;
Texture2D black_hole;


void load() 
{
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