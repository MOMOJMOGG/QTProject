#include "b.h"
#include "c.h"

extern "C" double Area_Triangle(double base, double height)
{
    return div(mul(base, height),2);
}

extern "C" double Area_Circle(double radius)
{
    double pi = 3.1415926;
    return mul(mul(radius,radius),pi);
}

extern "C" double Area_Rectangle(double width,double height)
{
    return mul(width, height);
}

