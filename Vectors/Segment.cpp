// #include "Segment.h"
// #include "Line.h"
// #include <iostream>

// Segment::Segment() {
//     a = new Point();
//     b = new Point();
//     c = new Point();
// }

// Segment::Segment(Point& A, Point& B, Point& C) {
//     a = A;
//     b = B;
//     c = C;
// }

// Segment::~Segment() {}

// Segment::Segment(const Segment& other) {
//     a = other.a;
//     b = other.b;
//     c = other.c;
// }

// Segment& Segment::operator=(const Segment& other) {
//     if (this != &other) {
//         a = other.a;
//         b = other.b;
//         c = other.c;
//     }
//     return *this;
// }

// bool Segment::operator==(const Point& p)const {
//     // TODO
// }

// bool Segment::operator>(const Point& p)const {
//     // TODO
// }

// bool Segment::operator<(const Point& p)const {
//     // TODO
// }

// void Segment::print() const {
//     std::cout << "Segment" << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "b: " << b << std::endl;
//     std::cout << "c: " << c << std::endl;
// }

// std::istream& Segment::inserter(std::istream& i) {
//     std::cout << "\nPlease enter a: ";
//     i >> a;
//     std::cout << "\nPlease enter b: ";
//     i >> b;
//     std::cout << "\nPlease enter c: ";
//     i >> c;
//     return i;
// }

// std::ostream& Segment::extractor(std::ostream& o) const {
//     o << "\na = " << this->getA() << std::endl;
//     o << "b = " << this->getB() << std::endl;
//     o << "c = " << this->getC() << std::endl;
//     return o;
// }