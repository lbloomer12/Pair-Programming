#include "Line.h"
#include <cmath>

Line::Line(Point& p1, Point& p2)
{
    if(p1.getX() < p2.getX()) 
    {
        point1 = p1;
        point2 = p2;
    } 
    else 
    {
        point1 = p2;
        point2 = p1;
    }
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
    double midpointX = (point1.getX() + point2.getX()) / 2;
    double midpointY = (point1.getY() + point2.getY()) / 2;
    Point midpoint(midpointX, midpointY);
    return midpoint;
}

void Line::extendLine(double value)
{
    double newX1, newX2, newY1, newY2;
    double slope = getSlope();
    newX1 = point1.getX() - value / (sqrt(1 + slope*slope));
    newX2 = point2.getX() + value / (sqrt(1 + slope*slope));
    newY1 = point1.getY() - (slope * value) / (sqrt(1 + slope*slope));
    newY2 = point2.getY() + (slope * value) / (sqrt(1 + slope*slope));

    point1.setX(newX1);
    point1.setY(newY1);

    point2.setX(newX2);
    point2.setY(newY2);
}

string Line::toString() 
{
    return "";
}