#include "first_class.h"

Area_Calculator::Area_Calculator()
{
    m_radius = 0;
    m_width = 0;
    m_height = 0;
    m_base = 0;	
}
Area_Calculator::~Area_Calculator()
{
	
}
void Area_Calculator::SetCircleParam(double radius)
{
    m_radius = radius;
}

void Area_Calculator::SetRectangleParam(double width, double height)
{
    m_width = width;
    m_height = height;	
}

void Area_Calculator::SetTriangleParam(double base, double height)
{
    m_base = base;
    m_height = height;	
}

double Area_Calculator::GetTriangleArea()
{
    return Area_Triangle(m_base, m_height);	
}

double Area_Calculator::GetCircleArea()
{
    return Area_Circle(m_radius);	
}

double Area_Calculator::GetRectangleArea()
{
    return Area_Rectangle(m_width, m_height);	
}
