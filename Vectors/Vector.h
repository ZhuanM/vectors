#pragma once
#include "Point.h"
#include <iostream>

class Vector : public Point {

public:
    Vector();
    Vector(double, double, double);
    Vector(const Point&, const Point&);
    ~Vector();
    Vector(const Vector&);
    Vector& operator=(const Vector&);

    double vecLength()const;
    Vector& direction()const;
    bool isZero()const;
    bool isParalel(const Vector&)const;
    bool isPerpendicular(const Vector&)const;


    virtual void print() const;
    void menu()const;

    virtual std::istream& inserter(std::istream& i);
	virtual std::ostream& extractor(std::ostream& o) const;

private:

};