#include "Line.h"

#include <iostream>
#include <cmath>

Line::Line() {}

Line::Line(Point& x, Vector& vector) {
	x = x;
	vector = vector;
}

Line::Line(Point& x, Point& y) {
	x = x;
	y = y;
}

Line::~Line() {}

Line::Line(const Line& other) {
	this->setA(other.a);
	this->setB(other.b);
	this->setVector(other.vector);
}

Line& Line::operator=(const Line& other) {
	if (this != &other) {
		this->setA(other.a);
		this->setB(other.b);
		this->setVector(other.vector);
	}
	return *this;
}

Vector Line::findDirection() const{
	Vector vector(this->getA(), this->getB());
	
	Vector v;

	v = vector.direction();

	return v;
}

double Line::findAngle(const Line& l, const Line& p) {
	Vector a(l.getA().getX(), l.getA().getY(), l.getA().getZ());

	Vector b(p.getA().getX(), p.getA().getY(), p.getA().getZ());
	
	double cos = a * b / a.vecLength() * b.vecLength();

	return cos;
}

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
	b.setZ(l.getZ());

	double cos = a * b / a.vecLength() * b.vecLength();

	if (cos == 0 || cos == -1 || cos == 1) {
		return true;
	}

	return false;
}

bool Line::operator==(const Line& l) const {
	Line line;

	if ((line.getA().getX() == l.getA().getX() && line.getA().getY() == l.getA().getY() && line.getA().getZ() == l.getA().getZ()) &&
		(line.getB().getX() == l.getB().getX() && line.getB().getY() == l.getB().getY() && line.getB().getZ() == l.getB().getZ())) {
		return true;
	}

	return false;
}

bool Line::operator&&(const Line& l) const {
	Line line;

	Vector a, b;

	a.setX(line.getX());
	a.setY(line.getY());
	a.setZ(line.getZ());

	b.setX(l.getX());
	b.setY(l.getY());
	b.setZ(l.getZ());

	double cos = a * b / a.vecLength() * b.vecLength();

	if (cos != sqrt(2) / 2 && cos != -sqrt(2) / 2 && cos != 0 && cos != -1 && cos != 1) {
		return true;
	}

	return false;
}

bool Line::operator|(const Line& l) const {
	Line line;

	Vector a, b;

	a.setX(line.getX());
	a.setY(line.getY());
	a.setZ(line.getZ());

	b.setX(l.getX());
	b.setY(l.getY());
	b.setZ(l.getZ());

	double cos = a * b / a.vecLength() * b.vecLength();

	if (cos == sqrt(2) / 2 || cos == -sqrt(2) / 2) {
		return true;
	}

	return false;
}
