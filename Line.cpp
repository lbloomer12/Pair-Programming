#include "Line.h"
#include <sstream>
#include <iomanip>
#include <cmath>
#include <iostream>

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

bool Line::containsPoint(const Point& p)
{
    double x = p.getX(), y = p.getY();
    bool inBoundsX = (x <= point2.getX() && x >= point1.getX());
    
    if(inBoundsX && ((y-point1.getY()) / (x-point1.getX())) == getSlope()) 
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
    double roundX1 = round(point1.getX() * 10.0) / 10.0;
    double roundY1 = round(point1.getY() * 10.0) / 10.0;
    stringstream streamx1;
    stringstream streamy1;
    streamx1 << fixed << setprecision(1) << roundX1;
    streamy1 << fixed << setprecision(1) << roundY1;
    string strX1 = streamx1.str();
    string strY1 = streamy1.str();

    double roundX2 = round(point2.getX() * 10.0) / 10.0;
    double roundY2 = round(point2.getY() * 10.0) / 10.0;
    stringstream streamx2;
    stringstream streamy2;
    streamx2 << fixed << setprecision(1) << roundX2;
    streamy2 << fixed << setprecision(1) << roundY2;
    string strX2 = streamx2.str();
    string strY2 = streamy2.str();

    double roundLen = round(getLength() * 10.0) / 10.0;
    stringstream streamlen;
    streamlen << fixed << setprecision(1) << roundLen;
    string strLen = streamlen.str();

    return "Line- Point 1: [X: " + strX1 + ", Y: " + strY1 + "], Point 2: [X: " + strX2 + ", Y: " + strY2 + "], Length: " + strLen;
}