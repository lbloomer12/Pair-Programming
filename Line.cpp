#include "Line.h"
#include <cmath>

Line::Line(Point p1, Point p2)
{
    point1 = p1;
    point2 = p2;
}

double Line::getLength()
{
    return sqrt(pow(point2.getX() - point1.getX(), 2) + pow(point2.getY() - point1.getY(), 2));
}