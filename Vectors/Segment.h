#pragma once
#include "Line.h"
#include <iostream>

class Segment : public Line {

public:
    Segment();
    Segment(const Line&)
    Segment(const Point&, const Vector&);
    Segment(const Point&, const Vector&, double, double);
    ~Segment();
    Segment(const Segment&);
    Segment& operator=(const Segment&);

    double getT(int n)const { return t[n]; }
    void setT(int, double);
    //void check(double&, double&);
    double length();
    Point midPoint(); 
    
    virtual void print() const;

    virtual std::istream& extractor(std::istream& i);
    virtual std::ostream& inserter(std::ostream& o) const;

private:
    double t[2];
};