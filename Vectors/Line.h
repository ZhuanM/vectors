#pragma once

#include "Vector.h"
#include <iostream>

class Line : public Vector {
public :
	//constructores
	Line();
	Line(Point&, Vector&);
	Line(Point&, Point&);
	~Line();

	//functions
	virtual void VectorDirection(const Line&) const;

	//overload operators

private:
	Point x, y;
	Vector vector;
};