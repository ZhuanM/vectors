#include "Point.h"
#include "Triangle.h"
#include <iostream>

Point::Point() {
    x = 0.;
    y = 0.;
    z = 0.;
}

Point::Point(double X,double Y,double Z) {
    x = X;
    y = Y;
    z = Z;
}

Point::~Point() {}

Point::Point(const Point& other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

Point& Point::operator=(const Point& other) {
    if(this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

bool Point::operator==(const Point& p)const {
    if(x == p.x && y == p.y && z == p.z)
        return true;
    return false;
}

bool Point::operator<(const Triangle& t)const {
    Point p(*this);
    Triangle t1(t.getA(), t.getB(), t.getC());
    Triangle t2(p, t.getB(), t.getC());
    Triangle t3(t.getA(), p, t.getC());
    Triangle t4(t.getA(), t.getB(), p);

    double area = t1.area();
    double area1 = t2.area();
    double area2 = t3.area();
    double area3 = t4.area();

    return !(area == area1 + area2 + area3);  
}

bool Point::operator>(const Triangle& t)const {
    Point p(*this);
    Triangle t1(t.getA(), t.getB(), t.getC());
    Triangle t2(p, t.getB(), t.getC());
    Triangle t3(t.getA(), p, t.getC());
    Triangle t4(t.getA(), t.getB(), p);

    double area = t1.area();
    double area1 = t2.area();
    double area2 = t3.area();
    double area3 = t4.area();

    return (area == area1 + area2 + area3);
}

bool Point::operator==(const Triangle& t)const {
    Point p(*this);
    const float zero = 0.01f;
    Triangle t1(t.getA(), p, t.getB());
    Triangle t2(t.getA(), p, t.getC());
    Triangle t3(t.getB(), p, t.getC());
    if(t1.area() < zero) {
        return true;
    }
    else if(t2.area() < zero) {
        return true;
    }
    else if(t3.area() < zero) {
        return true;
    }
    return false;
}

void Point::print() const {
    std::cout<<"Point"<< std::endl;
    std::cout<<"x: "<< x << std::endl;
    std::cout<<"y: "<< y << std::endl;
    std::cout<<"z: "<< z << std::endl;
}

std::istream& Point::inserter(std::istream& i) {
    std::cout << "\nPlease enter x: ";
    i >> x;
    std::cout << "\nPlease enter y: ";
    i >> y;
    std::cout << "\nPlease enter z: ";
    i >> z;
    return i; 
}

std::ostream& Point::extractor(std::ostream& o) const { 
    o << "\nx = " << this->getX() << std::endl;
	o << "y = " << this->getY() << std::endl;
	o << "z = " << this->getZ() << std::endl;
    return o; 
}