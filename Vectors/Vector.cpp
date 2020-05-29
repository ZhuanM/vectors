#include "Vector.h"
#include "VectorLengthException.h"
#include <cmath>

Vector::Vector() {}

Vector::Vector(double x, double y, double z) : Point(x, y, z) {}

Vector::Vector(const Point& p1, const Point& p2) {
    this->setX(p1.getX()-p2.getX());
    this->setY(p1.getY()-p2.getY());
    this->setZ(p1.getZ()-p2.getZ());
}

Vector::~Vector() {}

Vector::Vector(const Vector& other) {
    this->setX(other.getX());
    this->setY(other.getY());
    this->setZ(other.getZ());
}

Vector& Vector::operator=(const Vector& other) {
    if(this != &other) {
        this->setX(other.getX());
        this->setY(other.getY());
        this->setZ(other.getZ());
    }
    return *this;
}

double Vector::vecLength()const {
    return sqrt(this->getX()*this->getX() + this->getY()*this->getY() + this->getZ()*this->getZ());
}

bool Vector::isZero()const {
    if(this->getX() == 0 && this->getY() == 0 && this->getZ() == 0)
        return true;
    return false;
}

Vector Vector::direction()const {
    try {
        if(this->isZero())
            throw VectorLengthException();
        else {
            Vector res(*this);
            res.setX(this->getX() / vecLength());
            res.setY(this->getY() / vecLength());
            res.setZ(this->getZ() / vecLength());
            return res;
        }
    }
    catch(VectorLengthException& e) {
        std::cout << e.what_msg() << std::endl;
        return *this;
    }

}

/*
//needs work
bool Vector::isParallel(const Vector& v)const {
    try {
        if(this->isZero() && v.isZero()) 
            throw VectorLengthException();
        else {
            if()
        }
    }
    catch(VectorLengthException& e) {
        std::cout << e.what_msg() << std::endl;
        return false;
    }
}
*/


bool Vector::isPerpendicular(const Vector& v)const {
    try {
        if(this->isZero() && v.isZero())
            throw VectorLengthException();
        else {
            if(this->getX()*v.getX() + this->getY()*v.getY() + this->getZ()*v.getZ() == 0)
                return true;
            return false;
        }
    }
    catch(VectorLengthException& e) {
        std::cout << e.what_msg() << std::endl;
        return false;
    }
}


//needs work
//void Vector::print() const;

//void menu()const {
//    std::cout<<"asdasdas"<<std::endl;
//}

std::istream& Vector::inserter(std::istream& i) {
    Point::inserter(i);
    return i; 
}
std::ostream& Vector::extractor(std::ostream& o) const {
    o << "\nx = " << this->getX() << std::endl;
	o << "y = " << this->getY() << std::endl;
	o << "z = " << this->getZ() << std::endl;
    return o; 
}