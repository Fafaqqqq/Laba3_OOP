#pragma once
#include <iostream>

class Point
{
public:
	Point() = default;
	Point(double x, double y);
	Point(const Point& other);

	Point& operator=(const Point& other);
	bool operator==(const Point& other) const;

	double getX() const;
	double getY() const;
	void move(const Point& other);
	void move(double x, double y);

	friend std::ostream& operator<<(std::ostream& out, const Point& point);

private:
	double _x = 0;
	double _y = 0;
};

