#pragma once

class Point
{
public:
	Point() = default;
	Point(double x, double y);
	Point(const Point& other);

	Point& operator=(const Point& other);

	double getX();
	double getY();
	void move(const Point& other);
	void move(double x, double y);

private:
	double _x = 0;
	double _y = 0;
};