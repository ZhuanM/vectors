#include "Tetrahedron.h"
#include "Point.h"
#include "Vector.h"
#include "EqualPointException.h"
#include <iostream>
#include <cmath>

Tetrahedron::Tetrahedron() { 
    Point a(0, 0, 0);
    Point b(0, 0, 0);
    Point c(0, 0, 0);
    Point d(0, 0, 0);
    this->setA(a);
    this->setB(b);
    this->setC(c);
    this->setD(d);
}

Tetrahedron::Tetrahedron(const Point& A, const Point& B, const Point& C, const Point& D) {
    this->setA(A);
    this->setB(B);
    this->setC(C);
    this->setD(D);
}

Tetrahedron::~Tetrahedron() {}

Tetrahedron::Tetrahedron(const Tetrahedron& other) {
    this->setA(other.a);
    this->setB(other.b);
    this->setC(other.c);
    this->setD(other.d);
}

bool Tetrahedron::pointsAreEqual(const Point& p1, const Point& p2, const Point& p3, const Point& p4) const {
    try {
        if(p1 == p2) {
            throw EqualPointException("A and B are equal!");
        }
        else if(p1 == p3) {
            throw EqualPointException("A and C are equal!");
        }
        else if(p1 == p4) {
            throw EqualPointException("A and D are equal!");
        }
        else if(p2 == p4) {
            throw EqualPointException("B and D are equal!");
        }
        else if(p2 == p3) {
            throw EqualPointException("B and C are equal!");
        }
        else if(p3 == p4) {
            throw EqualPointException("C and D are equal!");
        }
        else {
            return false;
        }
    }
    catch(EqualPointException& e) {
        std::cout << e.what_msg() << std::endl;
        return true;
    }
}

bool Tetrahedron::isRegular() const {
    Vector v1(this->getA(), this->getB());
    Vector v2(this->getA(), this->getC());
    Vector v3(this->getA(), this->getD());
    Vector v4(this->getB(), this->getD());
    Vector v5(this->getB(), this->getC());
    Vector v6(this->getC(), this->getD());

    if (v1 == v2 && v2 == v3 && v3 == v4 && v4 == v5 && v5 == v6) {
        return true;
    }
    return false;
}

bool Tetrahedron::isOrthocentric() const {
    Vector v1(this->getA(), this->getB());
    Vector v2(this->getA(), this->getC());
    Vector v3(this->getA(), this->getD());
    Vector v4(this->getB(), this->getD());
    Vector v5(this->getB(), this->getC());
    Vector v6(this->getC(), this->getD());

    if (v1.vecLength()*v1.vecLength() + v6.vecLength()*v6.vecLength() == v2.vecLength()*v2.vecLength() + v4.vecLength()*v4.vecLength() 
    && v2.vecLength()*v2.vecLength() + v4.vecLength()*v4.vecLength() == v3.vecLength()*v3.vecLength() + v5.vecLength()*v5.vecLength()) {
        return true;
    }
    return false;
}

double Tetrahedron::volume() const {
    double res;
    Vector v1(this->getA(), this->getB());
    Vector v2(this->getA(), this->getC());
    Vector v3(this->getA(), this->getD());
    res = (v1.getX()*(v2.getY()*v3.getZ()-v2.getZ()*v3.getY())-v1.getY()*(v2.getX()*v3.getZ()-v2.getZ()*v3.getX())+v1.getZ()*(v2.getX()*v3.getY()-v2.getY()*v3.getX())) / 6;
    return res;
}

double Tetrahedron::surroundingSurface() const {
    double res;
    Vector v(this->getA(), this->getB());
    res = sqrt(3) * v.vecLength() * v.vecLength();
    return res;
}

Tetrahedron& Tetrahedron::operator=(const Tetrahedron& other) {
    if (this != &other) {
        this->setA(other.a);
        this->setB(other.b);
        this->setC(other.c);
        this->setD(other.d);
    }
    return *this;
}

bool Tetrahedron::operator<(const Point& p)const {
    double D0 = this->getA().getX()*(this->getB().getY()*(this->getC().getZ()*1 - 1*this->getD().getZ())-this->getB().getZ()*(this->getC().getY()*1-1*this->getD().getY())+1*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY()))
     - this->getA().getY()*(this->getB().getX()*(this->getC().getZ()*1-1*this->getD().getZ())-this->getB().getZ()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + this->getA().getZ()*(this->getB().getX()*(this->getC().getY()*1-1*this->getD().getY())-this->getB().getY()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()))
     + 1*(this->getB().getX()*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY())-this->getB().getY()*(this->getC().getX()*this->getD().getZ()-this->getC().getZ()*this->getD().getX())+this->getB().getZ()*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()));
    double D1 = p.getX()*(this->getB().getY()*(this->getC().getZ()*1 - 1*this->getD().getZ())-this->getB().getZ()*(this->getC().getY()*1-1*this->getD().getY())+1*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY()))
     - p.getY()*(this->getB().getX()*(this->getC().getZ()*1-1*this->getD().getZ())-this->getB().getZ()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + p.getZ()*(this->getB().getX()*(this->getC().getY()*1-1*this->getD().getY())-this->getB().getY()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()))
     + 1*(this->getB().getX()*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY())-this->getB().getY()*(this->getC().getX()*this->getD().getZ()-this->getC().getZ()*this->getD().getX())+this->getB().getZ()*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()));;
    double D2 = this->getA().getX()*(p.getY()*(this->getC().getZ()*1 - 1*this->getD().getZ())-p.getZ()*(this->getC().getY()*1-1*this->getD().getY())+1*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY()))
     - this->getA().getY()*(p.getX()*(this->getC().getZ()*1-1*this->getD().getZ())-p.getZ()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + this->getA().getZ()*(p.getX()*(this->getC().getY()*1-1*this->getD().getY())-p.getY()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()))
     + 1*(p.getX()*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY())-p.getY()*(this->getC().getX()*this->getD().getZ()-this->getC().getZ()*this->getD().getX())+p.getZ()*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()));;
    double D3 = this->getA().getX()*(this->getB().getY()*(p.getZ()*1 - 1*this->getD().getZ())-this->getB().getZ()*(p.getY()*1-1*this->getD().getY())+1*(p.getY()*this->getD().getZ()-p.getZ()*this->getD().getY()))
     - this->getA().getY()*(this->getB().getX()*(p.getZ()*1-1*this->getD().getZ())-this->getB().getZ()*(p.getX()*1-1*this->getD().getX())+1*(p.getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + this->getA().getZ()*(this->getB().getX()*(p.getY()*1-1*this->getD().getY())-this->getB().getY()*(p.getX()*1-1*this->getD().getX())+1*(p.getX()*this->getD().getY()-p.getY()*this->getD().getX()))
     + 1*(this->getB().getX()*(p.getY()*this->getD().getZ()-p.getZ()*this->getD().getY())-this->getB().getY()*(p.getX()*this->getD().getZ()-p.getZ()*this->getD().getX())+this->getB().getZ()*(p.getX()*this->getD().getY()-p.getY()*this->getD().getX()));;
    double D4 = this->getA().getX()*(this->getB().getY()*(this->getC().getZ()*1 - 1*p.getZ())-this->getB().getZ()*(this->getC().getY()*1-1*p.getY())+1*(this->getC().getY()*p.getZ()-this->getC().getZ()*p.getY()))
     - this->getA().getY()*(this->getB().getX()*(this->getC().getZ()*1-1*p.getZ())-this->getB().getZ()*(this->getC().getX()*1-1*p.getX())+1*(this->getC().getX()*p.getZ()-getC().getZ()*p.getX()))
     + this->getA().getZ()*(this->getB().getX()*(this->getC().getY()*1-1*p.getY())-this->getB().getY()*(this->getC().getX()*1-1*p.getX())+1*(this->getC().getX()*p.getY()-this->getC().getY()*p.getX()))
     + 1*(this->getB().getX()*(this->getC().getY()*p.getZ()-this->getC().getZ()*p.getY())-this->getB().getY()*(this->getC().getX()*p.getZ()-this->getC().getZ()*p.getX())+this->getB().getZ()*(this->getC().getX()*p.getY()-this->getC().getY()*p.getX()));;

    return (D0 == D1 + D2 + D3 + D4);
}

bool Tetrahedron::operator>(const Point& p)const {
    double D0 = this->getA().getX()*(this->getB().getY()*(this->getC().getZ()*1 - 1*this->getD().getZ())-this->getB().getZ()*(this->getC().getY()*1-1*this->getD().getY())+1*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY()))
     - this->getA().getY()*(this->getB().getX()*(this->getC().getZ()*1-1*this->getD().getZ())-this->getB().getZ()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + this->getA().getZ()*(this->getB().getX()*(this->getC().getY()*1-1*this->getD().getY())-this->getB().getY()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()))
     + 1*(this->getB().getX()*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY())-this->getB().getY()*(this->getC().getX()*this->getD().getZ()-this->getC().getZ()*this->getD().getX())+this->getB().getZ()*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()));
    double D1 = p.getX()*(this->getB().getY()*(this->getC().getZ()*1 - 1*this->getD().getZ())-this->getB().getZ()*(this->getC().getY()*1-1*this->getD().getY())+1*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY()))
     - p.getY()*(this->getB().getX()*(this->getC().getZ()*1-1*this->getD().getZ())-this->getB().getZ()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + p.getZ()*(this->getB().getX()*(this->getC().getY()*1-1*this->getD().getY())-this->getB().getY()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()))
     + 1*(this->getB().getX()*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY())-this->getB().getY()*(this->getC().getX()*this->getD().getZ()-this->getC().getZ()*this->getD().getX())+this->getB().getZ()*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()));;
    double D2 = this->getA().getX()*(p.getY()*(this->getC().getZ()*1 - 1*this->getD().getZ())-p.getZ()*(this->getC().getY()*1-1*this->getD().getY())+1*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY()))
     - this->getA().getY()*(p.getX()*(this->getC().getZ()*1-1*this->getD().getZ())-p.getZ()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + this->getA().getZ()*(p.getX()*(this->getC().getY()*1-1*this->getD().getY())-p.getY()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()))
     + 1*(p.getX()*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY())-p.getY()*(this->getC().getX()*this->getD().getZ()-this->getC().getZ()*this->getD().getX())+p.getZ()*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()));;
    double D3 = this->getA().getX()*(this->getB().getY()*(p.getZ()*1 - 1*this->getD().getZ())-this->getB().getZ()*(p.getY()*1-1*this->getD().getY())+1*(p.getY()*this->getD().getZ()-p.getZ()*this->getD().getY()))
     - this->getA().getY()*(this->getB().getX()*(p.getZ()*1-1*this->getD().getZ())-this->getB().getZ()*(p.getX()*1-1*this->getD().getX())+1*(p.getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + this->getA().getZ()*(this->getB().getX()*(p.getY()*1-1*this->getD().getY())-this->getB().getY()*(p.getX()*1-1*this->getD().getX())+1*(p.getX()*this->getD().getY()-p.getY()*this->getD().getX()))
     + 1*(this->getB().getX()*(p.getY()*this->getD().getZ()-p.getZ()*this->getD().getY())-this->getB().getY()*(p.getX()*this->getD().getZ()-p.getZ()*this->getD().getX())+this->getB().getZ()*(p.getX()*this->getD().getY()-p.getY()*this->getD().getX()));;
    double D4 = this->getA().getX()*(this->getB().getY()*(this->getC().getZ()*1 - 1*p.getZ())-this->getB().getZ()*(this->getC().getY()*1-1*p.getY())+1*(this->getC().getY()*p.getZ()-this->getC().getZ()*p.getY()))
     - this->getA().getY()*(this->getB().getX()*(this->getC().getZ()*1-1*p.getZ())-this->getB().getZ()*(this->getC().getX()*1-1*p.getX())+1*(this->getC().getX()*p.getZ()-getC().getZ()*p.getX()))
     + this->getA().getZ()*(this->getB().getX()*(this->getC().getY()*1-1*p.getY())-this->getB().getY()*(this->getC().getX()*1-1*p.getX())+1*(this->getC().getX()*p.getY()-this->getC().getY()*p.getX()))
     + 1*(this->getB().getX()*(this->getC().getY()*p.getZ()-this->getC().getZ()*p.getY())-this->getB().getY()*(this->getC().getX()*p.getZ()-this->getC().getZ()*p.getX())+this->getB().getZ()*(this->getC().getX()*p.getY()-this->getC().getY()*p.getX()));;

    return !(D0 == D1 + D2 + D3 + D4);
}

bool Tetrahedron::operator==(const Point& p)const {
    double D0 = this->getA().getX()*(this->getB().getY()*(this->getC().getZ()*1 - 1*this->getD().getZ())-this->getB().getZ()*(this->getC().getY()*1-1*this->getD().getY())+1*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY()))
     - this->getA().getY()*(this->getB().getX()*(this->getC().getZ()*1-1*this->getD().getZ())-this->getB().getZ()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + this->getA().getZ()*(this->getB().getX()*(this->getC().getY()*1-1*this->getD().getY())-this->getB().getY()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()))
     + 1*(this->getB().getX()*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY())-this->getB().getY()*(this->getC().getX()*this->getD().getZ()-this->getC().getZ()*this->getD().getX())+this->getB().getZ()*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()));
    double D1 = p.getX()*(this->getB().getY()*(this->getC().getZ()*1 - 1*this->getD().getZ())-this->getB().getZ()*(this->getC().getY()*1-1*this->getD().getY())+1*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY()))
     - p.getY()*(this->getB().getX()*(this->getC().getZ()*1-1*this->getD().getZ())-this->getB().getZ()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + p.getZ()*(this->getB().getX()*(this->getC().getY()*1-1*this->getD().getY())-this->getB().getY()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()))
     + 1*(this->getB().getX()*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY())-this->getB().getY()*(this->getC().getX()*this->getD().getZ()-this->getC().getZ()*this->getD().getX())+this->getB().getZ()*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()));;
    double D2 = this->getA().getX()*(p.getY()*(this->getC().getZ()*1 - 1*this->getD().getZ())-p.getZ()*(this->getC().getY()*1-1*this->getD().getY())+1*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY()))
     - this->getA().getY()*(p.getX()*(this->getC().getZ()*1-1*this->getD().getZ())-p.getZ()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + this->getA().getZ()*(p.getX()*(this->getC().getY()*1-1*this->getD().getY())-p.getY()*(this->getC().getX()*1-1*this->getD().getX())+1*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()))
     + 1*(p.getX()*(this->getC().getY()*this->getD().getZ()-this->getC().getZ()*this->getD().getY())-p.getY()*(this->getC().getX()*this->getD().getZ()-this->getC().getZ()*this->getD().getX())+p.getZ()*(this->getC().getX()*this->getD().getY()-this->getC().getY()*this->getD().getX()));;
    double D3 = this->getA().getX()*(this->getB().getY()*(p.getZ()*1 - 1*this->getD().getZ())-this->getB().getZ()*(p.getY()*1-1*this->getD().getY())+1*(p.getY()*this->getD().getZ()-p.getZ()*this->getD().getY()))
     - this->getA().getY()*(this->getB().getX()*(p.getZ()*1-1*this->getD().getZ())-this->getB().getZ()*(p.getX()*1-1*this->getD().getX())+1*(p.getX()*this->getD().getZ()-getC().getZ()*this->getD().getX()))
     + this->getA().getZ()*(this->getB().getX()*(p.getY()*1-1*this->getD().getY())-this->getB().getY()*(p.getX()*1-1*this->getD().getX())+1*(p.getX()*this->getD().getY()-p.getY()*this->getD().getX()))
     + 1*(this->getB().getX()*(p.getY()*this->getD().getZ()-p.getZ()*this->getD().getY())-this->getB().getY()*(p.getX()*this->getD().getZ()-p.getZ()*this->getD().getX())+this->getB().getZ()*(p.getX()*this->getD().getY()-p.getY()*this->getD().getX()));;
    double D4 = this->getA().getX()*(this->getB().getY()*(this->getC().getZ()*1 - 1*p.getZ())-this->getB().getZ()*(this->getC().getY()*1-1*p.getY())+1*(this->getC().getY()*p.getZ()-this->getC().getZ()*p.getY()))
     - this->getA().getY()*(this->getB().getX()*(this->getC().getZ()*1-1*p.getZ())-this->getB().getZ()*(this->getC().getX()*1-1*p.getX())+1*(this->getC().getX()*p.getZ()-getC().getZ()*p.getX()))
     + this->getA().getZ()*(this->getB().getX()*(this->getC().getY()*1-1*p.getY())-this->getB().getY()*(this->getC().getX()*1-1*p.getX())+1*(this->getC().getX()*p.getY()-this->getC().getY()*p.getX()))
     + 1*(this->getB().getX()*(this->getC().getY()*p.getZ()-this->getC().getZ()*p.getY())-this->getB().getY()*(this->getC().getX()*p.getZ()-this->getC().getZ()*p.getX())+this->getB().getZ()*(this->getC().getX()*p.getY()-this->getC().getY()*p.getX()));;

    if(D1 == 0 || D2 == 0 || D3 == 0 || D4 == 0) {
        return true;
    }
    return false;
}

void Tetrahedron::menu() {
    int choice;
    Tetrahedron t(*this);
    std::cout << "1. Find if Tetrahedron is Orthocentric.\n";
	std::cout << "2. Find if Tetrahedron is Regular.\n";
	std::cout << "3. Volume.\n";
	std::cout << "4. Surrounding Surface.\n";
	std::cout << "5. Find if a Point is on the same Plane and inside the Tetrahedron.\n";
	std::cout << "6. Find if a Point is on the same Plane and outside the Tetrahedron.\n";
	std::cout << "7. Find if a Point lies on one of the sides of the Tetrahedron.\n";

    if(pointsAreEqual(t.getA(), t.getB(), t.getC(), t.getD()))
        return;
    do{
        std::cin>>choice;
    }while(choice < 1 || choice>7);
    
    Point p;
    switch(choice) {
        case 1:
            std::cout<<((t.isOrthocentric()) ? "The Tetrahedron is Orthocentric!\n" : "The Tetrahedron is NOT Orthocentric!\n");
            break;
        case 2:
            std::cout<<((t.isRegular()) ? "The Tetrahedron is Regular!\n" : "The Tetrahedron is NOT Regular!\n");
            break;
        case 3:
            std::cout<<"Volume: "<< t.volume() <<std::endl;
            break;
        case 4:
            std::cout<<"Surrounding Surface: "<< t.surroundingSurface() <<std::endl;
            break;
        case 5:
            std::cout<<"Enter the elements of the Point: \n";
            std::cin>>p;
            std::cout<<((t<p) ? "The Point lies inside the Tetrahedron!\n" : "The Point IS NOT inside the Tetrahedron!\n");
            break;
        case 6:
            std::cout<<"Enter the elements of the Point: \n";
            std::cin>>p;
            std::cout<<((t>p) ? "The Point lies inside the Tetrahedron!\n" : "The Point IS NOT inside the Tetrahedron!\n");
            break;
        case 7:
            std::cout<<"Enter the elements of the Point: \n";
            std::cin>>p;
            std::cout<<((t==p) ? "The Point lies on a side of the Tetrahedron!\n" : "The Point DOES NOT lie on one of the sides of the Tetrahedron!\n");
            break;
    }
}

std::istream& Tetrahedron::extractor(std::istream& i) {
    std::cout << "\nPlease enter a: ";
    Point a;
    i >> a;
    this->setA(a);
    std::cout << "\nPlease enter b: ";
    Point b;
    i >> b;
    this->setB(b);
    std::cout << "\nPlease enter c: ";
    Point c;
    i >> c;
    this->setC(c);
    std::cout << "\nPlease enter d: ";
    Point d;
    i >> d;
    this->setD(d);
    bool error = pointsAreEqual(a, b, c, d);
    if (error) {
        std::cout<<"Points are equal!";
        return i;
    }
    return i;
}

std::ostream& Tetrahedron::inserter(std::ostream& o) const {
    o << "\na = " << this->getA() << std::endl;
    o << "b = " << this->getB() << std::endl;
    o << "c = " << this->getC() << std::endl;
    o << "d = " << this->getD() << std::endl;
    return o;
}
