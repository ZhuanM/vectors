#include "Triangle.h"
#include <iostream>

Triangle::Triangle() {
    a = new Point();
    b = new Point();
    c = new Point();
}

Triangle::Triangle(Point& A, Point& B, Point& C) {
    a = A;
    b = B;
    c = C;
}

Triangle::~Triangle() {}

Triangle::Triangle(const Triangle& other) {
    a = other.a;
    b = other.b;
    c = other.c;
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        c = other.c;
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