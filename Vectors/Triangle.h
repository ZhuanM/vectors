#pragma once
#include "Point.h"
#include <iostream>

class Triangle : public Point {

public:
    Triangle();
    Triangle(Point&, Point&, Point&);
    ~Triangle();
    Triangle(const Triangle&);
    Triangle &operator=(const Triangle&);

    bool operator==(const Point&) const;
    bool operator>(const Point&) const;
    bool operator<(const Point&) const;

    void setA(Point val) { a = val; }
    void setB(Point val) { b = val; }
    void setC(Point val) { c = val; }

    double getA()const { return a; }
    double getB()const { return b; }
    double getC()const { return c; }

    virtual void print() const;

    virtual std::istream& inserter(std::istream& i);
    virtual std::ostream& extractor(std::ostream& o) const;

private:
    Point a, b, c;
};