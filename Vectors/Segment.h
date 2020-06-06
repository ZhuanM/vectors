// #pragma once
// #include "Line.h"
// #include <iostream>

// class Segment : public Line {

// public:
//     Segment();
//     Segment(Point&, Point&, Point&);
//     ~Segment();
//     Segment(const Segment&);
//     Segment &operator=(const Segment&);

//     bool operator==(const Point&) const;
//     bool operator>(const Point&) const;
//     bool operator<(const Point&) const;

//     void setA(Point val) { a = val; }
//     void setB(Point val) { b = val; }
//     void setC(Point val) { c = val; }

//     double getA()const { return a; }
//     double getB()const { return b; }
//     double getC()const { return c; }

//     virtual void print() const;

//     virtual std::istream& inserter(std::istream& i);
//     virtual std::ostream& extractor(std::ostream& o) const;

// private:
//     Point a, b, c;
// };