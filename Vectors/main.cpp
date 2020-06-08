//g++ main.cpp Element.cpp Point.cpp Vector.cpp VectorLengthException.cpp Triangle.cpp EqualPointException.cpp Line.cpp -o test
#include <iostream>
#include <fstream>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include "Triangle.h"
#include "EqualPointException.h"
#include "Line.h"
#include "Segment.h"

using namespace std;

void list();

void Testing() {
	char ch;
	Element * e;

	ofstream fout("vectors.txt");
	if(!fout){
        cerr<<"Unable to create the file"<<endl;
        //return 1;
    }

	do{
		list();
		cin>>ch;
		fout<<ch<<endl;
	}while(ch<'0' || ch>'6');

	//fout.close();

	// ifstream fin("vectors.txt");
	// if(!fin){
    //     cerr<<"Unable to create the file"<<endl;
    //     //return 2;
    // }

	switch(ch) {
		//point
		case '1':
			system("cls");
			e = new Point();
			cin>>*e;
			fout<<*e<<endl;
			fout.close();
			e->menu();
			break;

		//vector
		case '2':
			system("cls");
			e = new Vector();
			cin>>*e;
			ch = 'y';
			while(ch == 'y' || ch == 'Y') {
				system("cls");
				//cout<< *e<<endl;
				e->menu();
				cout<<"\nWould you like to continue? (y/n) ";
				cin >> ch;
			}
			break;

		//triangle
		case '3':
			system("cls");
			e = new Triangle();
			cin >> *e;
			//pointsAreEqual(e->getA(), e->getB(), e->getC());
			ch= 'y';
			while (ch == 'y' || ch == 'Y') {
				system("cls");
				cout << *e << endl;
				e->menu();
				cout<<"\nWould you like to continue? (y/n) ";
				cin >> ch;
			}
			break;

		//line
		case '4':
			system("cls");
			e = new Line();
			cin>>*e;
			ch = 'y';
			while(ch == 'y' || ch == 'Y') {
				system("cls");
				cout << *e << endl;
				e->menu();
				cout<<"\nWould you like to continue? (y/n) ";
				cin >> ch;
			}
			break;
		//segment
		case '5':
		
		//tetr
		case '6':
			system("cls");
		case '0':
			system("exit");
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