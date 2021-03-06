#include "Element.h"
using namespace std;

Element::Element() {}

Element::~Element() {}

double Element::getX() const {
	return 0.0;
}

double Element::getY() const {
	return 0.0;
}

double Element::getZ() const {
	return 0.0;
}

void Element::menu(){}

istream& Element::extractor(istream& i) { return i; }

ostream& Element::inserter(ostream& o) const { return o; }

istream& operator>>(istream& i, Element& el) {
	return el.extractor(i);
}

ostream& operator<<(ostream& o, const Element& el) {
	return el.inserter(o);
}
 