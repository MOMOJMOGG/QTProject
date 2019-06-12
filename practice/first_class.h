#pragma once
#include "c.h"
class Area_Calculator
{
	public :
	Area_Calculator();
	~Area_Calculator();
	private:
	    double m_radius;
	    double m_width;
	    double m_height;
	    double m_base;
	public:
	    void SetTriangleParam(double base, double height);
	    void SetCircleParam(double radium);
	    void SetRectangleParam(double width, double height);
	    
        double GetTriangleArea();
        double GetCircleArea();
        double GetRectangleArea();	    
};
