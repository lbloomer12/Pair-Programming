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
	Point testPoint(1.2, 3.4);
	Point testPoint2(0.34, 1.27);
	SECTION("Constructor")
	{
		REQUIRE(testPoint.getX() == 1.2);
		REQUIRE(testPoint.getY() == 3.4);

		REQUIRE(testPoint2.getX() == 0.34);
		REQUIRE(testPoint2.getY() == 1.27);
	}

	SECTION("ToString")
	{
		REQUIRE(testPoint.toString() == "X: 1.2, Y: 3.4");
		REQUIRE(testPoint2.toString() == "X: 0.3, Y: 1.3");
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
		double prevLength = testLine.getLength();
		double prevSlope = testLine.getSlope();

		Point checkOnLine(3.5, 4.5);
		REQUIRE(testLine.containsPoint(checkOnLine) == false);
		
		testLine.extendLine(2.0);

		REQUIRE(testLine.containsPoint(checkOnLine) == true);
		REQUIRE(testLine.getLength() == prevLength + 4.0);
		REQUIRE(testLine.getSlope() == prevSlope);
	}

	SECTION("ToString")
	{
		REQUIRE(testLine.toString() == "Line- Point 1: [X: 1.0, Y: 2.0], Point 2: [X: 3.0, Y: 4.0], Length: 2.8");
	}
}