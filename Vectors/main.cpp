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
	char ch;
	Element * e;
	do{
		list();
		cin>>ch;
	}while(ch<'0' || ch>'6');

	switch(ch) {
		case '1':
			system("cls");
			e = new Point();
			cin>>*e;
			e->menu();
			break;
		case '2':
			system("cls");
			e = new Vector();
			cin>>e;
			ch = 'y'
			while(ch == 'y' || ch == 'Y') {
				system("cls");
				//cout<< *e<<endl;
				e->menu();
				cout<<"\nWould you like to continue? (y/n) ";
				cin >> ch;
			}
			break;
		case '3':
			system("cls");
		case '4':
			system("cls");
		case '5':
			system("cls");
			e = new Triangle();
			cin >> *e;
			c = 'y';
			while (c == 'y' || c == 'Y') {
				system("cls");
				cout << *e << endl;
				a->menu();
				cout<<"\nWould you like to continue? (y/n) ";
				cin >> ch;
			}
			break;
		case '6':
			system("cls");
		case '0':
			system("exit");
	}
}
	


	
}

int main() {

	Testing();

	return 0;
}

void list() {
	cout<<"Project: Vectors\n\n";
	cout<<"1. Point\n";
	cout<<"2. Vector\n";
	cout<<"3. Triangle\n";
	cout<<"4. Line\n";
	cout<<"5. Segment\n";
	cout<<"6. Tetrahedron\n";
	cout<<"0. Exit\n";
}