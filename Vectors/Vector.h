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
    bool isZero()const;
    Vector direction()const;
    bool isParallel(const Vector&)const;
    bool isPerpendicular(const Vector&)const;

    Vector operator+(const Vector&);
    Vector operator-(const Vector&);
    double operator*(const Vector&);
    Vector operator^(const Vector&);
    double operator()(const Vector&, const Vector&);
    Vector operator*(double);


    //virtual void print() const;
    //void menu()const;

    virtual std::istream& inserter(std::istream& i);
	virtual std::ostream& extractor(std::ostream& o) const;

private:
};

Vector operator*(const double, const Vector&);