#include "Line.h"
#include <cmath>

Line::Line(Point& p1, Point& p2)
{
    point1 = p1;
    point2 = p2;
}

double Line::getLength()
{
    return sqrt(pow(point2.getX() - point1.getX(), 2) + pow(point2.getY() - point1.getY(), 2));
}

double Line::getSlope() 
{
    return (point1.getY() - point2.getY()) / (point1.getX() - point2.getX());
}

bool Line::containsPoint(Point p)
{
    int x = p.getX(), y = p.getY();
    bool inBoundsX = (x <= point1.getX() && x >= point2.getX()) || (x <= point2.getX() && x >= point1.getX());
    bool inBoundsY = (y <= point1.getY() && y >= point2.getY()) || (y <= point2.getY() && y >= point1.getY());

    if(inBoundsX && inBoundsY && ( (y-point1.getY()) / (x-point1.getX()) == getSlope() ) ) 
    {
        return true;
    }
    return false;
}

Point Line::getMidpoint()
{
    Point p;
    return p;
}

void Line::extendLine(double value)
{
    
}

string Line::toString() 
{
    return "";
}