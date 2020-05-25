#pragma once
#include "Element.h"
#include "Triangle.h"
#include <iostream>

class Point : public Element {

public:
    Point();
    Point(double,double,double);
    ~Point();
    Point(const Point&);
    Point& operator=(const Point&);

    bool operator==(const Point&) const;

    bool operator==(const Triangle&) const;
    bool operator>(const Triangle&) const;
    bool operator<(const Triangle&) const;

    void setX(double val) { x = val; }
    void setY(double val) { y = val; }
    void setZ(double val) { z = val; }

    double getX()const { return x; }
    double getY()const { return y; }
    double getZ()const { return z; }

    virtual void print() const;

    virtual std::istream& inserter(std::istream& i);
	virtual std::ostream& extractor(std::ostream& o) const;

private:
    double x, y, z;
};