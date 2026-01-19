#pragma once
#include <string>

using namespace std;

class Point {
    public:
        double getX() const;
        const double getY();
        const string toString();
        Point(double x, double y);
        Point(const Point& p);

    private:
        double x;
        double y;
};