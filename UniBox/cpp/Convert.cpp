#include <sstream>
#include "../Includes/Convert.h"
string convert_float_to_str(float a) // convert float to string 
{
    stringstream r;
    r << a; // gets float value
    string t; // temporary string
    r >> t; // converting the float value to a string
    return t;
    // c_str() is used to convert string to const char * so it can be printed and taken as an argument */
}
