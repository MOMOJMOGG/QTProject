#include "b.h"

extern "C" int add(int a, int b)
{
return a+b;
}

extern "C" int sub(int a, int b)
{
return a-b;
}

extern "C" double div(double a, double b)
{
return a/b;
}

extern "C" double mul(double a, double b)
{
return a*b;
}
