#include "Point.h"
#include <cmath>
#include <format>
#include <sstream>
#include <iomanip>

Point::Point(double xCord, double yCord)
{
    x = xCord;
    y = yCord;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
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