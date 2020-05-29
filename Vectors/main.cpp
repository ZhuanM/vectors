//g++ main.cpp Element.cpp Point.cpp Vector.cpp -o test
#include <iostream>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
using namespace std;

int main() {

	Point a(5.67, 4.32, 6.98);
	Point b(5.67, 4.32, 6.98);
	Point c;
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

	cout<<"vec: "<<vec<<"vec2: "<<vec2<<"vec3: "<<vec3<<endl;

	return 0;
}