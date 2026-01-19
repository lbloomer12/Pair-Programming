#include <string>

using namespace std;

class Point {
    public:
        string getX();
        string getY();
        string toString();
        Point(double x, double y);

    private:
        double x;
        double y;
};