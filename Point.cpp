#include "Point.h"
#include <cmath>
#include <format>
#include <sstream>
#include <iomanip>

Point::Point() 
{
    x = 0.0;
    y = 0.0;
}

Point::Point(double xCord, double yCord)
{
    x = xCord;
    y = yCord;
}

Point::Point(const Point& p)
{
    x = p.getX();
    y = p.getY();
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

void Point::setX(double newX)
{
    x = newX;
}

void Point::setY(double newY)
{
    y = newY;
}

string Point::toString()
{
    double roundX = round(x * 10.0) / 10.0;
    double roundY = round(y * 10.0) / 10.0;
    stringstream streamx;
    stringstream streamy;
    streamx << fixed << setprecision(1) << roundX;
    streamy << fixed << setprecision(1) << roundY;
    string strX = streamx.str();
    string strY = streamy.str();

    return "X: " + strX + ", Y: " + strY;
}