#include "../Includes/Orbit.h"
/*
 а = avarage distance to sun
 e = warping a planet
 perihelionAngle = closest point of each planet to the sun
*/
namespace sun
{
	const double a = 0.0;
	const double e = 0.0;
	const double perihelionAngle = 0.0;
}
namespace mercury
{
	const double a = 63.9; // 57.9, 50.9
	const double e = 0.2056;
	const double perihelionAngle = 77.46;
}
namespace venus
{
	const double a = 94.2; //108.2,90.2
	const double e = 0.0067;
	const double perihelionAngle = 131.77;
}
namespace earth
{
	const double a = 128.6;  //149.6
	const double e = 0.0167;
	const double perihelionAngle = 102.94;
}
namespace mars
{
	const double a = 178.9;  //227.9,166.9
	const double e = 0.0334;  //0,0934
	const double perihelionAngle = 336.04;
}
namespace jupiter
{
	const double a = 229.6; // 778.6
	const double e = 0.019; //0.049
	const double perihelionAngle = 14.75; //14.75
}
namespace saturn
{
	const double a = 287.5; // 1433.5, 272.5
	const double e = 0.0065; //0.0565, 0.0365
	const double perihelionAngle = 92.43; //92.43
}
namespace uranus
{
	const double a = 370.5; //2872.5, 335.5, 350.5
	const double e = 0.0164; // 0.464, 0.0164, 
	const double perihelionAngle = 170.96; // 170.96
}
namespace neptune
{
	const double a = 435.1; //4495.1, 400.1
	const double e = 0.0106; //0.0106, 0.0106
	const double perihelionAngle = 44.97; //44.97
}