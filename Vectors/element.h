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
	virtual void print() const;
	virtual std::istream& inserter(std::istream& i);
	virtual std::ostream& extractor(std::ostream& o) const;
private:
};

std::istream& operator>>(std::istream& i, Element& el);
std::ostream& operator<<(std::ostream& o, const Element& el);
