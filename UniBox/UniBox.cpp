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
       menu_show(blank_info, menu, stats, checker, info, pluton_in_stats);

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
void rotate_planet_back(float& angle, float a, float e, float perihelionAngle, float speed, int& left, int& down)
{
    Vector2 newp = rotate_point_back(angle, a, e, perihelionAngle, speed);
    left = newp.x;
    down = newp.y;
    //rotate mercury
    //  Vector2 newp = rotate_point(align_mercury::angle, mercury::a, mercury::e,mercury::perihelionAngle, 10.f);
    //  align_mercury::left = newp.x ;
    // align_mercury::down = newp.y ;
}
string convert_float_to_str(float a) // convert float to string 
{
    stringstream r;
    r << a; // gets float value
    string t; // temporary string
    r >> t; // converting the float value to a string
    // if (a == speed::speed_sun || a == speed::speed_mercury || a == speed::speed_venus || a == speed::speed_earth || a == speed::speed_mars || a == speed::speed_jupiter || a == speed::speed_saturn || a == speed::speed_uranus || a == speed::speed_neptune)
    // {
    //     t+="kmh";
    //     return t; 
     //}
    // else
    return t;
    /* stringstream convert;
    convert << temperatures["sun"];
    string temp_string;
    convert >> temp_string;
    const char* temperature = temp_string.c_str(); // c_str() is used to convert string to const char * so it can be printed and taken as an argument */
}
void menu_show(Texture2D blank_info, Texture2D menu, Texture2D Stats, Texture2D checker, Texture2D info, Texture2D pluton_in_stats)
{
    // checker is a rectangle texture which is used to check if we are hovering on the following options


    bool check_hover_info = CheckCollisionPointRec(GetMousePosition(), { 1665, 20, (float)blank_info.width, (float)blank_info.height });

    if (true) // like while(true) but it is an if statement inside an while(!WindowShouldClose) loop, same like while(true)
    {
        DrawTexture(info, 1665, 20, WHITE); // draw info button, 1665 is left(x) and 20 is down(y)

        DrawTexture(blank_info, 1665, 20, BLANK); // use this texture as an invisible filler, so that the info button works
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_info && info_check == 0) // if the button is clicked and info_check is 0 (it hasn't been clicked before) the menu is shown and info_check becomes 1
    {
        info_check++;
    }
    else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && check_hover_info && info_check == 1) // if the button has already been clicked (info_check is 1), and it is clicked again it becomes 0 and the menu is not shown
    {
        info_check = 0;
    }
    if (info_check > 0)
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
                DrawTexture(Stats, left_stats, align_stats_down[8] + 51, RAYWHITE);
                DrawText("-173", left_temperature[7] + 5, align_temperature_down[7] + 60 + 51, text_size, WHITE);
                DrawText("2337km", left_length[7] + 10, align_length_down[7] + 60 + 51, text_size, WHITE);
                DrawText("100", left_speed[7] + 20, align_speed_down[7] + 60 + 51, text_size, WHITE);
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
void draw_planet(Texture2D planet, int& left, int& down, float& angle)
{

    DrawTexturePro(planet,
        Rectangle{ 0, 0, float(planet.width), float(planet.height) },
        Rectangle{ float(left), float(down),
        float(planet.width), float(planet.height) },
        Vector2{ planet.width / 2.f, planet.height / 2.f }, angle, WHITE);

}
  


  

    
   
   
    


        


        
  
