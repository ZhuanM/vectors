#pragma once

#include "Vector.h"
#include "Point.h"
#include <iostream>

class Line : public Vector {
public:
	//constructores
	Line();
	Line(Point&, Vector&);
	Line(Point&, Point&);
	~Line();

	Point getA() const { return a; };
	Point getB() const { return b; };
	Vector getVector() const { return vector; };

	void setA(Point val) { a = val; };
	void setB(Point val) { b = val; };

	//functions
	Vector findDirection() const;

	double findAngle(const Line&, const Line&);

	//overload operators
	bool operator+(const Point&) const;

	bool operator||(const Line&) const;

	bool operator==(const Line&) const;

	bool operator&&(const Line&) const;

	bool operator!=(const Line&) const;

	bool operator|(const Line&) const;
private:
	Point a, b;
	Vector vector;
};