#pragma once

#include "Point.h"
#include "Vector.h"
#include "Point.h"
#include <iostream>

class Line : public Vector {
public:
	Line();
	Line(Point&, Vector&);
	Line(Point&, Point&);
	~Line();
	Line(const Line&);
	Line& operator=(const Line&);

	Point getA() const { return a; };
	Point getB() const { return b; };
	Vector getVector() const { return vector; };

	void setA(Point val) { a = val; };
	void setB(Point val) { b = val; };
	void setVector(Vector val) { vector = val; };

	Vector findDirection() const;
	double findAngle(const Line&, const Line&);

	bool operator+(const Point&) const;
	bool operator||(const Line&) const;
	bool operator==(const Line&) const;
	bool operator&&(const Line&) const;
	bool operator!=(const Line&) const;
	bool operator|(const Line&) const;

    virtual std::istream& extractor(std::istream& i);
    virtual std::ostream& inserter(std::ostream& o) const;

	virtual void menu();

private:
	Point a, b;
	Vector vector;
};