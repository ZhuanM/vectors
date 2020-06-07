#include "Tetrahedron.h"
#include "Triangle.h"
#include "Point.h"
#include "Vector.h"
#include "EqualPointException.h"
#include <iostream>

Tetrahedron::Tetrahedron() { }

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

// double Triangle::area() const {
//     double res;
//     Vector v1(this->getA(), this->getB());
//     Vector v2(this->getA(), this->getC());
//     res = (v1 ^ v2).vecLength() / 2;
//     return  res;
// }

Tetrahedron& Tetrahedron::operator=(const Tetrahedron& other) {
    if (this != &other) {
        this->setA(other.a);
        this->setB(other.b);
        this->setC(other.c);
        this->setD(other.d);
    }
    return *this;
}

// bool Tetrahedron::operator<(const Point& p)const {
//     Tetrahedron t1(this->getA(), this->getB(), this->getC());
//     Tetrahedron t2(p, this->getB(), this->getC());
//     Tetrahedron t3(this->getA(), p, this->getC());
//     Tetrahedron t4(this->getA(), this->getB(), p);

//     double area = t1.area();
//     double area1 = t2.area();
//     double area2 = t3.area();
//     double area3 = t4.area();

//     return !(area == area1 + area2 + area3);  
// }

// bool Tetrahedron::operator>(const Point& p)const {
//     Tetrahedron t1(this->getA(), this->getB(), this->getC());
//     Tetrahedron t2(p, this->getB(), this->getC());
//     Tetrahedron t3(this->getA(), p, this->getC());
//     Tetrahedron t4(this->getA(), this->getB(), p);

//     double area = t1.area();
//     double area1 = t2.area();
//     double area2 = t3.area();
//     double area3 = t4.area();

//     return (area == area1 + area2 + area3);
// }

// bool Tetrahedron::operator==(const Point& p)const {
//     const float zero = 0.01f;
//     Tetrahedron t1(this->getA(), p, this->getB());
//     Tetrahedron t2(this->getA(), p, this->getC());
//     Tetrahedron t3(this->getB(), p, this->getC());
//     if(t1.area() < zero) {
//         return true;
//     }
//     else if(t2.area() < zero) {
//         return true;
//     }
//     else if(t3.area() < zero) {
//         return true;
//     }
//     return false;
// }

void Tetrahedron::menu() const {
    // TODO
}

std::istream& Tetrahedron::extractor(std::istream& i) {
    std::cout << "\nPlease enter a: ";
    Point a;
    i >> a;
    std::cout << "\nPlease enter b: ";
    Point b;
    i >> b;
    std::cout << "\nPlease enter c: ";
    Point c;
    i >> c;
    std::cout << "\nPlease enter d: ";
    Point d;
    i >> d;
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
