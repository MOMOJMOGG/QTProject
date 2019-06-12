#include <stdio.h>
#include "c.h"

int main()
{
    double baseSide = 3;
    double height = 3;
    double tri_area = Area_Triangle(baseSide, height);
    
    double radius = 5;
    double circle_area = Area_Circle(radius);
    
    double width = 6;
    height = 8;
    double rect_area = Area_Rectangle(width, height);

    printf("triangle area = %1.2f \n", tri_area);
    printf("circle_area = %1.2f \n", circle_area);
    printf("rectangle area = %1.2f \n", rect_area);
    return 0;
}
