#pragma once

#include "Vector.h"
#include <iostream>

class Line : public Vector {
public:
	//constructores
	Line();
	Line(Point&, Vector&);
	Line(Point&, Point&);
	~Line();

	//functions
	Vector direction() const;

	//overload operators
	bool operator+(const Point&) const;

	bool operator||(const Line&) const;

	bool operator==(const Line&) const;

	bool operator&&(const Line&) const;

	bool operator!=(const Line&) const;

	bool operator|(const Line&) const;
private:
	Point x, y;
	Vector vector;
};