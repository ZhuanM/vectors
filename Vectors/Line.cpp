#include "Line.h"
#include "Point.h"
#include "Vector.h"

#include <iostream>
#include <cmath>

Line::Line() {
    Point x(0., 0., 0.);
    Vector v(0., 0., 0.);
    this->setA(x);
    this->setB(x);
    this->setVector(v);
}

Line::Line(Point& x, Vector& vector) {
	this->setA(x);
    this->setB(x);
    this->setVector(vector);
}

Line::Line(Point& x, Point& y) {
	Vector v(x, y);
    this->setA(x);
    this->setB(y);
    this->setVector(v);
}

Line::~Line() {}

Line::Line(const Line& other) {
	this->setA(other.a);
	this->setB(other.b);
	this->setVector(other.vector);
}

Line& Line::operator=(const Line& other) {
	if (this != &other) {
		this->setA(other.a);
		this->setB(other.b);
		this->setVector(other.vector);
	}
	return *this;
}

Vector Line::findDirection() const{
	Vector vector(this->getA(), this->getB());
<<<<<<< HEAD

	return vector.direction();
=======
	
	return  vector.direction();
>>>>>>> b9838e3dd7955a950eda0de31359dc806e237a83
}

double Line::findAngle(const Line& l, const Line& p) {
	Vector a(l.getA().getX(), l.getA().getY(), l.getA().getZ());

	Vector b(p.getA().getX(), p.getA().getY(), p.getA().getZ());
	
	double cos = a * b / a.vecLength() * b.vecLength();

	return cos / 180;
}

bool Line::operator+(const Point& l) const {
	Line line;
	if ((line.a.getX() <= l.getX() && l.getX() <= line.b.getX()) && (line.a.getY() <= l.getY() && l.getY() <= line.b.getY()) &&
		(line.a.getZ() <= l.getZ() && l.getZ() <= line.b.getZ())) {
		return true;
	}

	return false;
}

bool Line::operator||(const Line& l) const {
	Line line;

	Vector a, b;

	a.setX(line.getX());
	a.setY(line.getY());
	a.setZ(line.getZ());

	b.setX(l.getX());
	b.setY(l.getY());
	b.setZ(l.getZ());

	double cos = a * b / a.vecLength() * b.vecLength();

	if (cos == 0 || cos == -1 || cos == 1) {
		return true;
	}

	return false;
}

bool Line::operator==(const Line& l) const {
	Line line;

	if ((line.getA().getX() == l.getA().getX() && line.getA().getY() == l.getA().getY() && line.getA().getZ() == l.getA().getZ()) &&
		(line.getB().getX() == l.getB().getX() && line.getB().getY() == l.getB().getY() && line.getB().getZ() == l.getB().getZ())) {
		return true;
	}

	return false;
}

bool Line::operator&&(const Line& l) const {
	Line line;

	Vector a, b;

	a.setX(line.getX());
	a.setY(line.getY());
	a.setZ(line.getZ());

	b.setX(l.getX());
	b.setY(l.getY());
	b.setZ(l.getZ());

	double cos = a * b / a.vecLength() * b.vecLength();

	if (cos != sqrt(2) / 2 && cos != -sqrt(2) / 2 && cos != 0 && cos != -1 && cos != 1) {
		return true;
	}

	return false;
}



bool Line::operator|(const Line& l) const {
	Line line;

	Vector a, b;

	a.setX(line.getX());
	a.setY(line.getY());
	a.setZ(line.getZ());

	b.setX(l.getX());
	b.setY(l.getY());
	b.setZ(l.getZ());

	double cos = a * b / a.vecLength() * b.vecLength();

	if (cos == sqrt(2) / 2 || cos == -sqrt(2) / 2) {
		return true;
	}

	return false;
}


std::istream& Line::extractor(std::istream& i) {
    int choice;
    std::cout<<"Enter the type of input: \n";
    std::cout<<"1.Line via a Point and a Vector.\n";
    std::cout<<"2.Line via 2 Points.\n";

    do{
        std::cin>>choice;
    }while(choice<1 || choice>2);

    switch(choice) {
        case 1: 
        {
            Point p;
            std::cout<<"Enter the elements of the Point: \n";
            std::cin>>p;
            Vector v;
            std::cout<<"Enter the elements of the Vector: \n";
            std::cin>>v;
            Line l(p, v);
            *this = l;
        }
            break;
        case 2:
        {
            Point a,b;
            std::cout<<"Enter the elements of the 1st Point: \n";
            i >> a;
            std::cout<<"Enter the elements of the 2nd Point: \n";
            i >> b;
            Line l(a,b);
            *this = l;
        }
            break;
    }
    return i;
}
std::ostream& Line::inserter(std::ostream& o) const {
    o <<"Line: \n";
    o << "x = "<< a.getX() <<" + "<< vector.getX()<<" * t\n";
    o << "y = "<< a.getY() <<" + "<< vector.getY()<<" * t\n";
    o << "z = "<< a.getZ() <<" + "<< vector.getZ()<<" * t\n";
    return o;
}

void Line::menu() {
    int choice;
    std::cout<<"Line: \n";
	std::cout<<"1: Direction.\n";
	std::cout<<"2: Not implemented.\n";
	std::cout<<"3: Angle between 2 lines.\n";
	std::cout<<"4: Find if a Point lies on the Line(+).\n";
	std::cout<<"5: Find if 2 Lines are Parallel(||).\n";
	std::cout<<"6: Find if 2 Lines are the same(==).\n";
	std::cout<<"7: Find if a Line intersects another Line(&&).\n";
	std::cout<<"8: Find if a Line crosses another Line(!=).\n";
	std::cout<<"9: Find if a Line is Perpendicular to another Line(|).\n";


    do {
        std::cin>>choice;
    }while(choice<1 || choice>9);

    Line l(*this), l2;
    Point p;

    switch(choice) {
        case 1:
            std::cout<<"\nDirection: "<<l.findDirection() <<std::endl;
            break;
        case 2:
            std::cout<<"Not implemented.\n";
            break;
        case 3:
            std::cout<<"Enter the elements of the second line: \n";
            std::cin>>l2;
            std::cout<<"\nAngle of the line: "<<l.findAngle(l, l2)<< std::endl;
            break;
        case 4:
            std::cout << "\nEnter the elements of the Point: \n";
		    std::cin >> p;
		    std::cout<<((l+p) ? "The Point lies on the Line!\n" : "The Point DOES NOT lie on the Line!\n");
            break;
        case 5:
            std::cout << "\nEnter the elements of the 2nd Line: \n";
		    std::cin >> l2;
		    std::cout<<((l||l2) ? "The Lines are Parallel!\n" : "The Lines ARE NOT Parallel!\n");
            break;
        case 6:
            std::cout << "\nEnter the elements of the 2nd Line: \n";
		    std::cin >> l2;
		    std::cout<<((l==l2) ? "The Lines are the same!\n" : "The Lines ARE NOT the same!\n");
            break;
        case 7:
            std::cout << "\nEnter the elements of the 2nd Line: \n";
		    std::cin >> l2;
		    std::cout<<((l&&l2) ? "The Lines intersect!\n" : "The LinesDOES NOT intersect!\n");
            break;
        case 8:
            std::cout<<"Not implemented.\n";
            break;
        case 9:
            std::cout << "\nEnter the elements of the 2nd Line: \n";
		    std::cin >> l2;
		    std::cout<<((l|l2) ? "The Lines are Perpendicular!\n" : "The Lines ARE NOT Perpendicular!\n");
            break;
            break;
    }
}