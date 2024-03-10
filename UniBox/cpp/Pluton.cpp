#include "../Includes/Pluton.h"
#include "../Includes/Orbit.h"
namespace actual_speed // float value speed
{
	 float mercury_speed =0.7f; // 1
	 float venus_speed = 0.5f; //2
	 float earth_speed = 0.3f; //3
	 float mars_speed = 0.1f; //4
	 float jupiter_speed = 0.07f; //5
     float saturn_speed = 0.03f; //6
	 float uranus_speed = 0.02f; //7
	 float neptune_speed = 0.009f; //8

}
// pluton data to make it spin and draw properly
namespace speed_pluton
{
 float speed_1 = 2.f;
 float speed_2 = 1.8f;
 float speed_3 = 1.6f;
 float speed_4 = 1.4f;
 float speed_5 = 1.2f;
 float speed_6 = 0.9f;
 float speed_7 = 0.3f; // 0.7f
 float speed_8 = 0.21f; // 0.5f
}
namespace a_pluton
{
 double a_1 = mercury::a;
 double a_2 = venus::a;
 double a_3 = earth::a;
 double a_4 = mars::a;
 double a_5 = jupiter::a;
 double a_6 = saturn::a;
 double a_7 = uranus::a;
 double a_8 = neptune::a;
}
namespace e_pluton
{
 double e_1 = mercury::e;
 double e_2 = venus::e;
 double e_3 = earth::e;
 double e_4 = mars::e;
 double e_5 = jupiter::e;
 double e_6 = saturn::e;
 double e_7 = uranus::e;
 double e_8 = neptune::e;
}
namespace peri_pluton
{
 double peri_1 = mercury::perihelionAngle;
 double peri_2 = venus::perihelionAngle;
 double peri_3 = earth::perihelionAngle;
 double peri_4 = mars::perihelionAngle;
 double peri_5 = jupiter::perihelionAngle;
 double peri_6 = saturn::perihelionAngle;
 double peri_7 = uranus::perihelionAngle;
 double peri_8 = neptune::perihelionAngle;
}
namespace angle_pluton
{
 float angle_1 = 0.f;
 float angle_2 = 0.f;
 float angle_3 = 0.f;
 float angle_4 = 1.3f;
 float angle_5 = 1.3f;
 float angle_6 = 1.3f;
 float angle_7 = 1.3f;
 float angle_8 = 1.2f;
}
namespace left_pluton
{
 int left_1 = 830;
 int left_2 = 800;
 int left_3 = 700;
 int left_4 = 659;
 int left_5 = 603;
 int left_6 = 494;
 int left_7 = 510;
 int left_8 = 390;
}
namespace down_pluton
{
 int down_1 = 385; 
 int down_2 = 390;
 int down_3 = 400;
 int down_4 = 405;
 int down_5 = 405;
 int down_6 = 375;           
 int down_7 = 410;
 int down_8 = 410; 
}