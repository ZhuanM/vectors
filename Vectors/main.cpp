//g++ main.cpp Element.cpp Point.cpp Vector.cpp VectorLengthException.cpp Triangle.cpp EqualPointException.cpp -o test
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
    Point b(5, 6, 7);
    Point c(19.3, 15, 20.3);
    //Triangle t1;
	//cin>>t1;
    Triangle t2(a, b, c);
    Triangle t3;
    t3 = t2;

	//cout<<"\nt1: "<<t1<<"\nt2: "<<t2<<"\nt3: "<<t3<<endl;
	cout<<"t3 area: "<< t3.area() << endl;
	cout<<"t3 per: "<< t3.perimeter() << endl;
	cout<<"t3 centroid: "<< t3.centroid() << endl;
	


	
}

int main() {

	Testing();

	return 0;
}