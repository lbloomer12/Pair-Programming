#include <iostream>
#include <cmath>
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
#include "Line.h"
#include "Point.h"

using namespace std;

//--
TEST_CASE("Test Point")  
{ 
	SECTION("Constructor")
	{
		Point testPoint(1.2, 3.4);

		REQUIRE(testPoint.getX() == 1.2);
		REQUIRE(testPoint.getY() == 3.4);
	}

	SECTION("ToString")
	{
		Point testPoint(1.2, 3.4);

		REQUIRE(testPoint.toString() == "X: 1.2, Y: 3.4");
	}
}
//--
TEST_CASE("Test Line")  
{ 
	Point testPoint1(1.0, 2.0);
	Point testPoint2(3.0, 4.0);
	Point testPoint3(2.0, 3.0);
	Point testPoint4(5.0, 6.0);

	Line testLine(testPoint1, testPoint2);

	SECTION("Distance")
	{
		REQUIRE(testLine.getLength() == sqrt(pow(3-1, 2) + pow(4-2, 2)));
	}

	SECTION("Slope")
	{
		REQUIRE(testLine.getSlope() == (1.0 * (4-2)) / (3-1));
	}

	SECTION("Point on Line")
	{
		REQUIRE(testLine.containsPoint(testPoint3) == true);
		REQUIRE(testLine.containsPoint(testPoint4) == false);
	}

	SECTION("Midpoint")
	{

		REQUIRE(testLine.getMidpoint().getX() == testPoint3.getX());
		REQUIRE(testLine.getMidpoint().getY() == testPoint3.getY());
	}

	SECTION("Extend Line")
	{
		testLine.extendLine(2.0);
		REQUIRE(testLine.getLength() == 6.8);
	}

	SECTION("ToString")
	{
		REQUIRE(testLine.toString() == "Line- Point 1: [X: 1.0, Y: 2.0], Point 2: [X: 3.0, Y: 4.0], Length: 2.8");
	}
}