#include "Triangle.h"
#include "Point.h"
#include "Vector.h"
#include "EqualPointException.h"
#include <iostream>

Triangle::Triangle() { }

Triangle::Triangle(const Point& A, const Point& B, const Point& C) {
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

bool Triangle::pointsAreEqual(const Point& p1, const Point& p2, const Point& p3) const {
    try {
        if(p1 == p2) {
            throw EqualPointException("A and B are equal!");
        }
        else if(p1 == p3) {
            throw EqualPointException("A and C are equal!");
        }
        else if(p2 == p3) {
            throw EqualPointException("B and C are equal!");
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

// bool Triangle::pointsAreEqual(const Point& p1, const Point& p2, const Point& p3) const {
//     Vector a(p1, p2);   //ab
//     Vector b(p2, p3);   //bc
//     Vector c(p1, p3);   //cd
//     try {
//         if(a.isParallel(b)) {
//             throw EqualPointException("A and B are equal!");
//         }
//         else if(a.isParallel(c)) {
//             throw EqualPointException("A and C are equal!");
//         }
//         else if(b.isParallel(c)) {
//             throw EqualPointException("B and C are equal!");
//         }
//         else {
//             return false;
//         }
//     }
//     catch(EqualPointException& e) {
//         std::cout << e.what_msg() << std::endl;
//         return true;
//     }
// }

int Triangle::type() const {
	Triangle t;

	Vector v1(t.getA(), t.getB());
	Vector v2(t.getA(), t.getC());

	double cos = v1 * v2 / v1.vecLength() * v2.vecLength();

	if (cos == 90) {
		std::cout << "The triangle is right-angled." << std::endl;
	}
	else if (cos < 0 || cos > 90) {
		std::cout << "The triangle is obtus." << std::endl;
	}
	else {
		Vector v3(t.getB(), t.getA());
		Vector v4(t.getB(), t.getC());

		double c = v3 * v4 / v3.vecLength() * v4.vecLength();

		if (c == 90) {
			std::cout << "The triangle is right-angled." << std::endl;
		}
		else if (cos < 0 || cos > 90) {
			std::cout << "The triangle is obtus." << std::endl;
		}
		else {
			std::cout << "The triangle is acute." << std::endl;
		}
        
	}


	Vector v5(t.getB(), t.getC());

	double a = v1.vecLength();
	double b = v2.vecLength();
	double c = v5.vecLength();

	if (a == b || b == c || a == c) {
		std::cout << "The trinagle is isosceles." << std::endl;
	}
	else if (a == b && a == c && b == c) {
		std::cout << "The triangle is equilateral." << std::endl;
	}
	else if (a != b & b != c && a != c) {
		std::cout << "The triangle is multifaceted." << std::endl;
	}
    return 0;
}

double Triangle::area() const {
    double res;
    Vector v1(this->getA(), this->getB());
    Vector v2(this->getA(), this->getC());
    res = (v1 ^ v2).vecLength() / 2;
    return  res;
}

Point Triangle::centroid() const {
    Point res;
    Vector v1(this->getA(), this->getB());
    Vector v2(this->getA(), this->getC());
    Vector v3(this->getB(), this->getC());
    res.setX((v1.getX() + v2.getX() + v3.getX()) / 3);
    res.setY((v1.getY() + v2.getY() + v3.getY()) / 3);
    res.setZ((v1.getZ() + v2.getZ() + v3.getZ()) / 3);
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

bool Triangle::operator<(const Point& p)const {
    Triangle t1(this->getA(), this->getB(), this->getC());
    Triangle t2(p, this->getB(), this->getC());
    Triangle t3(this->getA(), p, this->getC());
    Triangle t4(this->getA(), this->getB(), p);

    double area = t1.area();
    double area1 = t2.area();
    double area2 = t3.area();
    double area3 = t4.area();

    return !(area == area1 + area2 + area3);  
}

bool Triangle::operator>(const Point& p)const {
    Triangle t1(this->getA(), this->getB(), this->getC());
    Triangle t2(p, this->getB(), this->getC());
    Triangle t3(this->getA(), p, this->getC());
    Triangle t4(this->getA(), this->getB(), p);

    double area = t1.area();
    double area1 = t2.area();
    double area2 = t3.area();
    double area3 = t4.area();

    return (area == area1 + area2 + area3);
}

bool Triangle::operator==(const Point& p)const {
    const float zero = 0.01f;
    Triangle t1(this->getA(), p, this->getB());
    Triangle t2(this->getA(), p, this->getC());
    Triangle t3(this->getB(), p, this->getC());
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



std::istream& Triangle::extractor(std::istream& i) {
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
    pointsAreEqual(a, b, c);
    
    return i;
}

std::ostream& Triangle::inserter(std::ostream& o) const {
    o << "\na: " << this->getA() << std::endl;
    o << "b: " << this->getB() << std::endl;
    o << "c: " << this->getC() << std::endl;
    return o;
}

void Triangle::menu(){
    int choice;
    Triangle t(*this);
    std::cout << "1. Type.\n";
	std::cout << "2. Area.\n";
	std::cout << "3. Perimeter.\n";
	std::cout << "4. Centroid.\n";
	std::cout << "5. Find if a Point is on the same Plane and inside the Triangle.\n";
	std::cout << "6. Find if a Point is on the same Plane and outside the Triangle.\n";
	std::cout << "7. Find if a Point lies on one of the sides of the Triangle.\n";

    
    if(pointsAreEqual(t.getA(),t.getB(),t.getC()))
        return;
    do{
        std::cin>>choice;
    }while(choice < 1 || choice>7);

    
    
    Point p;
    switch(choice) {
        case 1:
            std::cout<<"\nType: "<<t.type()<<std::endl;
            break;
        case 2:
            std::cout<<"\nArea: "<< t.area() <<std::endl;
            break;
        case 3:
            std::cout<<"Perimeter: "<< t.perimeter() <<std::endl;
            break;
        case 4:
            std::cout<<"Centroid: "<< t.centroid() <<std::endl;
            break;
        case 5:
            std::cout<<"Enter the elements of the Point: \n";
            std::cin>>p;
            std::cout<<((t<p) ? "The Point lies inside the Triangle!\n" : "The Point IS NOT inside the Triangle!\n");
            break;
        case 6:
            std::cout<<"Enter the elements of the Point: \n";
            std::cin>>p;
            std::cout<<((t>p) ? "The Point lies inside the Triangle!\n" : "The Point IS NOT inside the Triangle!\n");
            break;
        case 7:
            std::cout<<"Enter the elements of the Point: \n";
            std::cin>>p;
            std::cout<<((t==p) ? "The Point lies on a side of the Triangle!\n" : "The Point DOES NOT lie on one of the sides of the Triangle!\n");
            break;
    }

}