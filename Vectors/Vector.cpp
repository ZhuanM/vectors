#include "Vector.h"
#include "VectorLengthException.h"
#include <cmath>

Vector::Vector() {
    this->setX(0.);
    this->setY(0.);
    this->setZ(0.);
}

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


bool Vector::isParallel(const Vector& v)const {
    try {
        if(this->isZero() && v.isZero()) 
            throw VectorLengthException();
        else {
            if(this->getX() / v.getX() == this->getY() / v.getY() == this->getZ() / v.getZ())
                return true;
            return false;
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
        std::cout << e.what_msg() << std::endl;
        return false;
    }
}

Vector Vector::projection( Vector& v) {
    Vector a(*this);
    Vector res(v*((a * v)/v.vecLength()));
	return res;
}

Vector Vector::operator+(const Vector& v) {
    Vector res;
    res.setX(this->getX() + v.getX());
    res.setY(this->getY() + v.getY());
    res.setZ(this->getZ() + v.getZ());
    return res;
}

Vector Vector::operator-(const Vector& v) {
    Vector res;
    res.setX(this->getX() - v.getX());
    res.setY(this->getY() - v.getY());
    res.setZ(this->getZ() - v.getZ());
    return res;
}

double Vector::operator*(const Vector& v) {
    return (this->getX()*v.getX() + this->getY()*v.getY() + this->getZ()*v.getZ());
}

Vector Vector::operator^(const Vector& v) {
    Vector res;
    res.setX(this->getY()*v.getZ() - this->getZ()*v.getY());
    res.setY(this->getZ()*v.getX() - this->getX()*v.getZ());
    res.setZ(this->getX()*v.getY() - this->getY()*v.getX());
    return res;
}

double Vector::operator()(const Vector& v1, const Vector& v2) {
    return (*this ^ v1) * v2;
}

Vector Vector::operator*(double n) {
    Vector res;
    res.setX(this->getX() * n);
    res.setY(this->getY() * n);
    res.setZ(this->getZ() * n);
    return res;
}

Vector operator*(const double n, const Vector& v) {
    Vector res;
    res.setX(v.getX() * n);
    res.setY(v.getY() * n);
    res.setZ(v.getZ() * n);
    return res;
}


std::istream& Vector::extractor(std::istream& i) {
    Point::extractor(i);
    return i;
}
std::ostream& Vector::inserter(std::ostream& o) const {
    o << "\nx = " << this->getX() << std::endl;
	o << "y = " << this->getY() << std::endl;
	o << "z = " << this->getZ() << std::endl;
    return o; 
}

void Vector::menu(){
    int choice;
    std::cout<<"Vector: \n";
	std::cout<<"1: Length.\n";
	std::cout<<"2: Direction.\n";
	std::cout<<"3: Projection of Vector onto Vector.\n";
	std::cout<<"4: Check if it is the Zero Vector.\n";
	std::cout<<"5: Check if two Vectors are Parallel with one another.\n";
	std::cout<<"6: Check if two Vector are Perpendicular with one another.\n";
	std::cout<<"7: Vector + Vector.\n";
	std::cout<<"8: Scalar Product - Vector * real number.\n";
	std::cout<<"9: Scalar Product - Vectors * Vector.\n";
	std::cout<<"10: Multiplication of two Vectors.\n";
	std::cout<<"11: Combined Multiplication of Vectors.\n";

    
	do{
        std::cin>>choice;
    }while(choice < 1 || choice>11);

    Vector v(*this);
    Vector v2, v3;
    switch(choice) {
        case 1:
            std::cout<<"The lenght of the Vector is: "<< v.vecLength() <<std::endl;
            break;
        case 2:
            std::cout<<"The direction of the Vector is: "<< v.direction() <<std::endl;
            break;
        case 3:
            std::cout<<"Enter the elements of the 2nd Vector:";
            std::cin>>v2;
            std::cout<<"The projection is: "<< v.projection(v2) <<std::endl;
            break;
        case 4:
            std::cout<<((v.isZero()) ? "It's a Zero Vector!\n" : "It IS NOT a Zero Vector!\n");
            break;
        case 5:
            std::cout<<"Enter the elements of the 2nd Vector:";
            std::cin>>v2;
            std::cout<<((v.isParallel(v2)) ? "The Vectors are parallel!\n" : "The Vectors ARE NOT parallel!\n");
            break;
        case 6:
            std::cout<<"Enter the elements of the 2nd Vector:";
            std::cin>>v2;
            std::cout<<((v.isPerpendicular(v2)) ? "The Vectors are parallel!\n" : "The Vectors ARE NOT parallel!\n");
            break;
        case 7:
            std::cout<<"Enter the elements of the 2nd Vector:";
            std::cin>>v2;
            std::cout<<"Result: \n"<< (v+v2) <<std::endl;
            break;
        case 8:
            int x;
            std::cout<<"Enter a number:";
            std::cin>>x;
            std::cout<<"Result: \n"<< (v*x) <<std::endl;
            break;
        case 9:
            std::cout<<"Enter the elements of the 2nd Vector:";
            std::cin>>v2;
            std::cout<<"Result: \n"<< (v*v2) <<std::endl;
            break;
        case 10:
            std::cout<<"Enter the elements of the 2nd Vector:";
            std::cin>>v2;
            std::cout<<"Result: \n"<< (v^v2) <<std::endl;
            break;
        case 11:
            std::cout<<"Enter the elements of the 2nd Vector:";
            std::cin>>v2;
            std::cout<<"Enter the elements of the 3rd Vector:";
            std::cin>>v3;
            std::cout<<"Result: \n"<< v(v2, v3) <<std::endl;
            break;
    }

}