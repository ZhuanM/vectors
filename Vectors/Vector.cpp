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
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

Vector& Vector::operator=(const Vector& other) {
    if(this == &other)
        return *this;
    else {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
    }
    return *this;
}

double Vector::vecLength()const {
    return sqrt(this->getX()*this->getX() + this->getY()*this->getY() + this->getZ()*this->getZ());
}

Vector& Vector::direction()const {
    try {
        if(this->isZero())
            throw VectorLengthException();
        else {
            Vector res;
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

bool Vector::isZero()const {
    if(this->getX() == 0 && this->getY() == 0 && this->getZ() == 0)
        return true;
    return false;
}

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
        std::cout << what_msg() << std::endl;
        return false;
    }
}

//needs work
void Vector::print() const;

void menu()const {
    std::cout<<"asdasdas"<<std::endl;
}

std::istream& Vector::inserter(std::istream& i) {
    std::cout << "\nPlease enter x: ";
    i >> x;
    std::cout << "\nPlease enter y: ";
    i >> y;
    std::cout << "\nPlease enter z: ";
    i >> z;
    return i; 
}
std::ostream& Vector::extractor(std::ostream& o) const {
    o << "\nx = " << this->getX() << std::endl;
	o << "y = " << this->getY() << std::endl;
	o << "z = " << this->getZ() << std::endl;
    return o; 
}