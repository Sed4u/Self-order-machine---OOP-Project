#include <iostream>
#include <Element.h>
#include <Bautura.h>

using namespace std;

Bautura::Bautura(const Bautura &other)  : Element(other) {
    this->mililitri = other.mililitri;
}

ostream& Bautura::print(ostream& os) const {
    Element::print(os);
    os << ", Mililitri: " << mililitri;
    return os;
}

istream& Bautura::read(istream& is) {
    Element::read(is);
    cout << "Mililitri: ";
    is >> mililitri;
    return is;
}

void Bautura::setMililitri(const unsigned int mil) {
    this->mililitri = mil;
}

unsigned int Bautura::getMililitri() const {
    return this->mililitri;
}