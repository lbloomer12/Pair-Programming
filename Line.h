#include <string>
#include "Point.h"

using namespace std;

class Line {
    public:
        Line(Point p1, Point p2);
        double getLength();
        double getSlope();
        bool containsPoint(Point p);
        Point getMidpoint();
        void extendLine(double value);
        string toString();

    private:
        Point point1;
        Point point2;
};