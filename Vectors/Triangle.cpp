#include "Triangle.h"
#include "Point.h"
#include "Vector.h"
#include <iostream>

Triangle::Triangle() {
    // this->setA(new Point());
    // this->setB(new Point());
    // this->setC(new Point());
}

Triangle::Triangle(Point& A, Point& B, Point& C) {
    this->setA(A);
    this->setB(B);
    this->setC(C);
}

Triangle::~Triangle() {}

Triangle::Triangle(const Triangle& other) {
    this->setA(other.a);
    this->setB(other.b);
    this->setC(other.c);
}

double Triangle::area() const {
    double res;
    Vector v1(this->getA(), this->getB());
    Vector v2(this->getA(), this->getC());
    res = (v1 ^ v2).vecLength() / 2;
    return  res;
}

double Triangle::centroid() const {
    double res;
    Vector v1(this->getA(), this->getB());
    Vector v2(this->getA(), this->getC());
    Vector v3(this->getB(), this->getC());
    // res = (v1 + v2 + v3) / 3;
    return res;
}

double Triangle::perimeter() const {
    double res;
    Vector v1(this->getA(), this->getB());
    Vector v2(this->getA(), this->getC());
    Vector v3(this->getB(), this->getC());
    res = v1.vecLength() + v2.vecLength() + v3.vecLength();
    return res;
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        this->setA(other.a);
        this->setB(other.b);
        this->setC(other.c);
    }
    return *this;
}

bool Triangle::operator==(const Point& p)const {
    // TODO
}

bool Triangle::operator>(const Point& p)const {
    // TODO
}

bool Triangle::operator<(const Point& p)const {
    // TODO
}

void Triangle::print() const {
    std::cout << "Triangle" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
}

std::istream& Triangle::inserter(std::istream& i) {
    std::cout << "\nPlease enter a: ";
    i >> a;
    std::cout << "\nPlease enter b: ";
    i >> b;
    std::cout << "\nPlease enter c: ";
    i >> c;
    return i;
}

std::ostream& Triangle::extractor(std::ostream& o) const {
    o << "\na = " << this->getA() << std::endl;
    o << "b = " << this->getB() << std::endl;
    o << "c = " << this->getC() << std::endl;
    return o;
}