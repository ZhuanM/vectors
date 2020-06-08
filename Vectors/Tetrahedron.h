#pragma once
#include "Triangle.h"
#include "Point.h"
#include <iostream>

class Tetrahedron : public Triangle {

public:
    Tetrahedron();
    Tetrahedron(const Point&, const Point&, const Point&, const Point&);
    ~Tetrahedron();
    Tetrahedron(const Tetrahedron&);
    Tetrahedron &operator=(const Tetrahedron&);

    bool pointsAreEqual(const Point&, const Point&, const Point&, const Point&) const;
    bool isRegular() const;
    bool isOrthocentric() const;
    double volume() const;
    double surroundingSurface() const;

    bool operator<(const Point&) const;
    bool operator>(const Point&) const;
    bool operator==(const Point&) const;

    void setA(Point val) { a = val; }
    void setB(Point val) { b = val; }
    void setC(Point val) { c = val; }
    void setD(Point val) { d = val; }

    Point getA()const { return a; }
    Point getB()const { return b; }
    Point getC()const { return c; }
    Point getD()const { return d; }

    virtual void menu();

    virtual std::istream& extractor(std::istream& i);
    virtual std::ostream& inserter(std::ostream& o) const;

private:
    Point a, b, c, d;
};
