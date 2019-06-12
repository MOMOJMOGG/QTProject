#include "area.h"
#include "b.h"


Area::Area()
{
    m_radius = 0;
    m_width = 0;
    m_height = 0;
    m_base = 0;
}


Area::~Area()
{

}
void Area::SetCircleParam(double radius)
{
    m_radius = radius;
}

void Area::SetRectangleParam(double width, double height)
{
    m_width = width;
    m_height = height;
}

void Area::SetTriangleParam(double base, double height)
{
    m_base = base;
    m_height = height;
}

double Area::GetTriangleArea()
{
    return div(mul(m_base,m_height),2);
}

double Area::GetCircleArea()
{
    return mul(mul(m_radius,m_radius),3.1415926);
}

double Area::GetRectangleArea()
{
    return mul(m_base,m_height);
}
