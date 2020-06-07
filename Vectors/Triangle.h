#pragma once
#include "Point.h"
#include <iostream>

class Triangle : public Point {

public:
    Triangle();
    Triangle(const Point&, const Point&, const Point&);
    ~Triangle();
    Triangle(const Triangle&);
    Triangle &operator=(const Triangle&);

    double area() const;
    double perimeter() const;
    Point centroid() const;

    bool pointsAreEqual(const Point&, const Point&, const Point&) const;

    bool operator<(const Point&) const;
    bool operator>(const Point&) const;
    bool operator==(const Point&) const;

    void setA(Point val) { a = val; }
    void setB(Point val) { b = val; }
    void setC(Point val) { c = val; }

    Point getA()const { return a; }
    Point getB()const { return b; }
    Point getC()const { return c; }

    virtual std::istream& extractor(std::istream& i);
    virtual std::ostream& inserter(std::ostream& o) const;
    
    virtual void menu() const;

private:
    Point a, b, c;
};
