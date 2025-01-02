
#ifndef BAUTURA_H
#define BAUTURA_H
#include <Element.h>
#include <iostream>
using namespace std;
class Bautura : public Element {
    unsigned int mililitri;
public:
    Bautura() : Element("", 0, 0), mililitri(0) {}
    Bautura(string nume, const float kcal, const float pret, const unsigned int mililitri) : Element(std::move(nume),kcal,pret), mililitri(mililitri) {}
    Bautura(const Bautura& other);
    ostream& print(ostream& os) const override;
    istream& read(istream& is) override;
    ~Bautura() override = default;

    void setMililitri(unsigned int mil);
    [[nodiscard]] unsigned int getMililitri() const;
};
#endif //BAUTURA_H
