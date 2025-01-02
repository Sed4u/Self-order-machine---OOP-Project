
#ifndef MANCARE_H
#define MANCARE_H
#include "Element.h"
#include <iostream>
#include <string>
#include <utility>
using namespace std;
class Mancare : public Element {
    unsigned int grame;
public:
    Mancare() : Element("", 0, 0), grame(0) {}
    Mancare(string nume,const float kcal,const float pret,const unsigned int grame) : Element(std::move(nume),kcal,pret), grame(grame) {}
    Mancare(const Mancare& other);
    ostream& print(ostream& os) const override;
    istream& read(istream& is) override;
    ~Mancare() override = default;

    void setGrame(unsigned int gr);
    [[nodiscard]] unsigned int getGrame() const;
};
#endif //MANCARE_H
