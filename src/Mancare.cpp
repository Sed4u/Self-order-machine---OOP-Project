#include "Mancare.h"
#include "Element.h"
#include <iostream>

using namespace std;

Mancare::Mancare(const Mancare &other)  : Element(other) {
    this->grame = other.grame;
}

ostream& Mancare::print(ostream& os) const {
    Element::print(os);
    os << ", Grame: " << grame;
    return os;
}

istream& Mancare::read(istream& is) {
    Element::read(is);
    cout << "Grame: ";
    is >> grame;
    return is;
}

void Mancare::setGrame(const unsigned int gr) {
    this->grame = gr;
}

unsigned int Mancare::getGrame() const {
    return this->grame;
}

