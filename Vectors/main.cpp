#include <iostream>
#include "Element.h"
#include "Point.h"
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


	if(a==c)
		cout<<"a = c"<<endl;

	
	cout << "Enter a point: ";
	cin >> test;
	cout << endl << test;


	return 0;
}