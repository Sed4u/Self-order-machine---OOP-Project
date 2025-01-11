
#ifndef PRODUS_H
#define PRODUS_H
#include "Element.h"

using namespace std;

class Bautura{};
class Mancare{};

template<class T>
class Produs: public Element {
    unsigned int unitati;

public:
    Produs() : Element("", 0, 0), unitati(0) {
    }

    Produs(string nume, const float kcal, const float pret, const unsigned int unitati) : Element(std::move(nume), kcal,
        pret), unitati(unitati) {
    }

    Produs(const Produs &other) : Element(other) {
        this->unitati = other.unitati;
    }

    ostream &print(ostream &os) const override {
        Element::print(os);
        if(typeid(T) == typeid(Mancare)) {
            os << ", Grame: " << unitati;
        }
        else if (typeid(T) == typeid(Bautura)) {
            os << ", Mililitri: " << unitati;
        }
        cout << " " << eSanatos();
        return os;
    }

    istream &read(istream &is) override {
        Element::read(is);
        if(typeid(T) == typeid(Mancare)) {
            cout << "Grame: ";
        }
        else if (typeid(T) == typeid(Bautura)) {
            cout << "Mililitri: ";
        }
        is >> unitati;
        return is;
    }

    ~Produs() override = default;

    void setUnitati(unsigned int uni) {
        this->unitati = uni;
    }

    [[nodiscard]] string eSanatos() const override {
        return getKcal() < 300 ? "(Optiune usoara)" : "(Bogat in calorii)";
    }
};
#endif //PRODUS_H
