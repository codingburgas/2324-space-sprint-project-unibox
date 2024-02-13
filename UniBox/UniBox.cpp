#include "Includes/Unibox.h"

int main()
{
    SetTargetFPS(60);

    InitWindow(screenWidth, screenHeight, "Unibox"); // set screen size and name of .exe file
    Texture2D background = LoadTexture("Images/galaxy.png"); // galaxy background
    Texture2D stats = LoadTexture("Images/stats.png"); // show stats of pressed planet
    Texture2D Sun = LoadTexture("Images/sun100x100.png"); // sun picture
    Texture2D Mercury = LoadTexture("Images/mercury45x45.png"); // mercury picture
    Texture2D Venus = LoadTexture("Images/venus50x50.png"); // venus picture
    Texture2D Earth = LoadTexture("Images/earth47x47.png"); // earth picture
    Texture2D Mars = LoadTexture("Images/mars48x48.png"); // mars picture
    Texture2D Jupiter = LoadTexture("Images/jupiter49x49.png"); // jupiter picture
    Texture2D Saturn = LoadTexture("Images/saturn121x138.png"); // saturn image
    Texture2D Uranus = LoadTexture("Images/uranus53x52.png"); // uranus image
    Texture2D Neptune = LoadTexture("Images/neptune70x128.png"); // neptune image
    Texture2D blank_info = LoadTexture("Images/blank_info.png"); // cancel stats button blank
    Texture2D start = LoadTexture("images/start_screen.png"); // start menu screen
    Texture2D new_game = LoadTexture("Images/new_game_button.png"); // new game button
    Texture2D quit = LoadTexture("Images/quit_button.png"); // quit button
    Texture2D info = LoadTexture("Images/stats_icon.png"); // stats info button
    Texture2D menu = LoadTexture("Images/stats_menu.png"); // stats menu picture
    Texture2D functions = LoadTexture("Images/functions_menu.png"); // function options on the left
    Texture2D checker = LoadTexture("Images/rectangle46.png");
    Texture2D Checker = LoadTexture("Images/rectangle49.png"); // functions buttons checker
    Texture2D exit_button = LoadTexture("Images/exit_options.png"); // exit button texture
    Texture2D checker_exit_button = LoadTexture("Images/checker_exit.png"); // checker to see if exit options are pressed   
    Texture2D exit_menu = LoadTexture("Images/exit_menu.png"); // exit menu options
    Texture2D options_checker = LoadTexture("Images/exit_options_checker.png");// checker if any of the exit options are checked

    Texture2D pluton = LoadTexture("Images/pluton.png"); // pluton picture    
    Texture2D add_planet_menu = LoadTexture("Images/add_planet_menu2.png"); // add planet menu
    Texture2D cancel_add_planet = LoadTexture("Images/cancel_button.png");// cancel button
    Texture2D cancel_add_planet_blank = LoadTexture("Images/add_planet_cancel_blank_button.png");
    Texture2D pluton_in_stats = LoadTexture("Images/mercury_in_stats_menu.png");
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

        static int end_program, start_game;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover_new_game)
        {
            start_game++;
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover_quit)
        {
            end_program++;
        }
        if (end_program > 0) // close the program if quit is pressed (end_program is bigger than 0)
        {
            return 0;
        }
        if (start_game > 0) // continue to the main program if new game is pressed (start_game is bigger than 0)
        {
            break;
        }

        EndDrawing();

    }
    while (!WindowShouldClose())
    {

        BeginDrawing();
ClearBackground(BLACK); // black background by default

DrawTexture(background, 5, 0, WHITE); // galaxy background

// draw orbit of each
draw_orbit(sun::a, sun::e, sun::perihelionAngle);
draw_orbit(mercury::a, mercury::e, mercury::perihelionAngle);
draw_orbit(venus::a, venus::e, venus::perihelionAngle);
draw_orbit(earth::a, earth::e, earth::perihelionAngle);
draw_orbit(mars::a, mars::e, mars::perihelionAngle);
draw_orbit(jupiter::a, jupiter::e, jupiter::perihelionAngle);
draw_orbit(saturn::a, saturn::e, saturn::perihelionAngle);
draw_orbit(uranus::a, uranus::e, uranus::perihelionAngle);
draw_orbit(neptune::a, neptune::e, neptune::perihelionAngle);
       

        EndDrawing();
    }

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
}
void draw_orbit(const double a, const double e, const double perihelionAngle)
{

    for (double theta = 0.0; theta <= 360.0; theta++)
    {
        double radians = (theta + perihelionAngle) * DEG2RAD;
        double radius = a * (1 - e * e) / (1 + e * cos(radians - perihelionAngle));
        double x = screenWidth / 2 + radius * cos(radians);
        double y = screenHeight / 2 + radius * sin(radians);

        DrawPixel((int)x, (int)y, WHITE);
    }
}
Vector2 rotate_point(float& angle, float a, float e, float perihelionAngle, float speed)
{

    float radians = (angle + perihelionAngle) * DEG2RAD;
    float radius = a * (1 - e * e) / (1 + e * cos(radians - perihelionAngle));
    angle += speed;
    if (angle > 360.f)
        angle = 0.f;
    return Vector2{ screenWidth / 2.f + radius * float(cos(radians)), screenHeight / 2.f + radius * float(sin(radians)) };

}
Vector2 rotate_point_back(float& angle, float a, float e, float perihelionAngle, float speed)
{
    float radians = (angle + perihelionAngle) * DEG2RAD;
    float radius = a * (1 - e * e) / (1 + e * cos(radians - perihelionAngle));
    angle -= speed;
    if (angle < 0.f)
        angle = 360.f + angle;
    return Vector2{ screenWidth / 2.f + radius * float(cos(radians)), screenHeight / 2.f + radius * float(sin(radians)) };
}
void rotate_planet(float& angle, float a, float e, float perihelionAngle, float speed, int& left, int& down)
{
    Vector2 newp = rotate_point(angle, a, e, perihelionAngle, speed);
    left = newp.x;
    down = newp.y;
    //rotate mercury
    //  Vector2 newp = rotate_point(align_mercury::angle, mercury::a, mercury::e,mercury::perihelionAngle, 10.f);
    //  align_mercury::left = newp.x ;
    // align_mercury::down = newp.y ;
}

  


  

    
   
   
    


        


        
  
