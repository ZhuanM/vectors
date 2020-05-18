#pragma once
#include <iostream>
using namespace std;

class Element {
public:
	Element();
	~Element();
	virtual double getX() const;
	virtual double getY() const;
	virtual double getZ() const;
	virtual void print() const;
	virtual istream& inserter(istream& i);
	virtual ostream& extractor(ostream& o) const;
private:

};

istream& operator>>(istream& i, Element& el);
ostream& operator<<(ostream& o, const Element& el);
