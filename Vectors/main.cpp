//g++ main.cpp Element.cpp Point.cpp Vector.cpp VectorLengthException.cpp -o test
#include <iostream>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include "Triangle.h"
#include "EqualPointException.h"

using namespace std;

void Testing() {
	Point a(2, 2, 2);
    Point b(3, 5, 6);
    Point c(5.6, 15, 20.3);
    Triangle t1();
    Triangle t2(a, b, c);
    Triangle t3;
    t3 = t2;
}

int main() {

	Testing();

	return 0;
}