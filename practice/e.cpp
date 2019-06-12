#include <stdio.h>
#include "first_class.h"

int main()
{
    Area_Calculator *calculator	= new Area_Calculator();
    
    calculator->SetTriangleParam(4,4);
    double tri_area = calculator->GetTriangleArea();
    
    calculator->SetCircleParam(10);
    double circle_area = calculator->GetCircleArea();
    
    calculator->SetRectangleParam(6,8);
    double rect_area = calculator->GetRectangleArea();
    
    printf("triangle area = %1.2f \n", tri_area);
    printf("circle area = %1.2f \n", circle_area);
    printf("rectangle area = %1.2f \n", rect_area);
    
    delete calculator;
    return 0;
}
