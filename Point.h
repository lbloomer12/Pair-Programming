#pragma once
#include <string>

using namespace std;

class Point {
    public:
        double getX();
        double getY();
        string toString();
        Point(double x, double y);

    private:
        double x;
        double y;
};