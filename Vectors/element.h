#pragma once
#include <iostream>
//using namespace std;

class Element {
public:
	Element();
	~Element();
	virtual double getX() const;
	virtual double getY() const;
	virtual double getZ() const;
	virtual void menu() const;
	virtual std::istream& extractor(std::istream& i);
	virtual std::ostream& inserter(std::ostream& o) const;
};

std::istream& operator>>(std::istream& i, Element& el);
std::ostream& operator<<(std::ostream& o, const Element& el);
