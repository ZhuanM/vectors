#ifndef _H_POINT_H_
#define _H_POINT_H_
#include "Element.h"
#include <iostream>

class Point : public Element {

public:
    Point();
    Point(double,double,double);
    ~Point();
    Point(const Point&);
    Point& operator=(const Point&);

    bool operator==(const Point&) const;

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

#endif