#include "Segment.h"
#include "Line.h"
#include <iostream>

Segment::Segment() {
    t[0] = 0.;
    t[1] = 1.;
}

Segment::Segment(const Point& p, const Vector& v) : Line(p, v) {
    t[0] = 0.;
    t[1] = 1.;
}

Segment::Segment(const Point& p, const Vector& v, double t1, double t2) : Line(p, v) {
    if(t1>t2) {
        t[0] = t2;
        t[1] = t1;
    }
    else {
        t[0] = t1;
        t[1] = t2;
    }
}

Segment::~Segment() {}

Segment::Segment(const Segment& s) {
    t[0] = s.getT(0);
    t[1] = s.getT(1);
}

Segment& Segment::operator=(const Segment& s) {
    if(this == &other)
        return *this;
    else {
        t[0] = s.getT(0);
        t[1] = s.getT(1);
    }
}

double Segment::getT(int i)const {
    if (i>=0 && i<2)
        return t[i];
    return 0.;
}

void Segment::setT(int i, double n) {
    if(i>=0 && i<2) {
        t[i] = n;
        if(t[0]>t[1]) {
            double tmp = t[0];
            t[0] = t[1];
            t[1] = tmp;
        }
    }
}

double Segment::length() {
    Line l;
	Point a((l.getX()).getX() + (l.getVector()).getX() * t[0], (l.getY()).getY() + (l.getVector()).getY() * t[0],
        (l.getZ()).getZ() + (l.getVector()).getZ() * t[0]);
    Point a((l.getX()).getX() + (l.getVector()).getX() * t[1], (l.getY()).getY() + (l.getVector()).getY() * t[1],
        (l.getZ()).getZ() + (l.getVector()).getZ() * t[1]);
	Vector AB(a, b);
	return AB.Length();
}

Point Segment::midPoint() {
    Line l;
    Point a((l.getX()).getX() + (l.getVector()).getX() * t[0], (l.getY()).getY() + (l.getVector()).getY() * t[0],
        (l.getZ()).getZ() + (l.getVector()).getZ() * t[0]);
    Point a((l.getX()).getX() + (l.getVector()).getX() * t[1], (l.getY()).getY() + (l.getVector()).getY() * t[1],
        (l.getZ()).getZ() + (l.getVector()).getZ() * t[1]);
    
    Point res(((l.getX()).getX() +(l.getX()).getX()) / 2, ((l.getY()).getY() +  (l.getY()).getY()) /2,
        ((l.getZ()).getZ() + (l.getZ()).getZ()) / 2);
    //((xA + xB)/2, (yA + yB)/2, (zA + zB)/2)
    return res;
}

bool Segment::operator==(const Point&) {
    
}
    
//void Segment::print() const;

std::istream& Segment::extractor(std::istream& i);
std::ostream& Segment::inserter(std::ostream& o) const;