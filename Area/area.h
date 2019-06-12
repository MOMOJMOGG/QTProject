#ifndef AREA_H
#define AREA_H

#if defined(AREA_LIBRARY)
#define AREASHARED_EXPORT __attribute__((visibility("default")))
#else
#define AREASHARED_EXPORT __attribute__((visivility("default")))
#endif

class AREASHARED_EXPORT Area
{

public:
    Area();
    ~Area();
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

#endif // AREA_H
