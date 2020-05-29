//g++ main.cpp Element.cpp Point.cpp Vector.cpp VectorLengthException.cpp -o test
#include <iostream>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
using namespace std;

void Testing() {
	Point a(5.67, 4.32, 6.98);
	Point b(5.67, 4.32, 6.98);
	Point c,d;
	Point test;

	cout << "a: " << a << "b: " << b << "c: " << c << endl;
	

	if(a==b)
		cout<<"a = b"<<endl;
	else
		cout <<"a != b"<< endl;

	Vector vec, vec2;

	cin>>vec;

	vec2 = vec;

	Vector vec3(vec);

	Vector vec4(1, 1, 2);

	Vector vec5(0,0,0);

	cout<<"vec: "<<vec<<"vec2: "<<vec2<<"vec3: "<<vec3<<endl;

	cout<<"vec4: "<<vec4.isZero()<<endl;

	cout<<"vec4: "<<vec4.direction()<<endl;
	cout<<"vec5: "<<vec5.direction()<<endl;

	cout<<vec4.isPerpendicular(vec)<<endl;
}

int main() {

	Testing();

	return 0;
}