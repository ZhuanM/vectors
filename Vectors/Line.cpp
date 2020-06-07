#include "Line.h"

#include <iostream>

Line::Line(Point& x, Vector& vector) {
	x = x;
	vector = vector;
}

Line::Line(Point& x, Point& y) {
	x = x;
	y = y;
}

Line::~Line(){}

bool Line::operator+(const Point& l) const {
	Line line;
	if ((line.a.getX() <= l.getX() && l.getX() <= line.b.getX()) && (line.a.getY() <= l.getY() && l.getY() <= line.b.getY()) &&
		(line.a.getZ() <= l.getZ() && l.getZ() <= line.b.getZ())) {
		return true;
	}

	return false;
}

bool Line::operator||(const Line& l) const {
	Line line;
	
	Vector a, b;

	a.setX(line.getX());
	a.setY(line.getY());
	a.setZ(line.getZ());

	b.setX(l.getX());
	b.setY(l.getY());
}