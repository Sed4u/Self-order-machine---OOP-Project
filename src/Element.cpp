#include "Element.h"

#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>
unsigned int Element::count = 0;

Element::Element(string nume, float kcal, float pret) : id_e(++count), nume(std::move(nume)), kcal(kcal), pret(pret) {
}

Element::Element(const Element &other) {
    this->id_e = other.id_e;
    this->pret = other.pret;
    this->nume = other.nume;
    this->kcal = other.kcal;
}

Element &Element::operator=(const Element &other) {
    if (this == &other) {
        return *this;
    }
    this->id_e = other.id_e;
    this->pret = other.pret;
    this->nume = other.nume;
    this->kcal = other.kcal;
    return *this;
}

ostream &operator<<(std::ostream &os, const Element &e) {
    return e.print(os);
}

istream &operator>>(istream &is, Element &e) {
    return e.read(is);
}

vector<Element *> Element::operator+(vector<Element *> &lista_elemente) {
    lista_elemente.push_back(this);
    return lista_elemente;
}


bool operator<(const Element &e1, const Element &e2) {
    return e1.pret < e2.pret;
}

bool operator>(const Element &e1, const Element &e2) {
    return e1.pret > e2.pret;
}

Element::~Element() = default;

unsigned int Element::getId() const {
    return id_e;
}

float Element::getPret() const {
    return pret;
}

const string &Element::getNume() const {
    return nume;
}

float Element::getKcal() const {
    return kcal;
}

void Element::setPret(float p) {
    this->pret = p;
}

void Element::setNume(const string &n) {
    this->nume = n;
}

void Element::setKcal(float k) {
    this->kcal = k;
}


ostream &Element::print(ostream &os) const {
    os << "ID: " << id_e << ", Nume: " << nume << ", Kcal: " << kcal << ", Pret: " << pret << " lei";
    return os;
}

istream &Element::read(istream &is) {
    cout << "Nume: ";
    if (cin.peek() == '\n')
        cin.get();
    getline(is, nume);

    bool ok = false;
    bool ok1 = false;
    while (ok == false) {
        try {
            if (ok1 == false) {
                cout << "Kcal: ";
                is >> kcal;
                if (kcal < 0) {
                    throw invalid_argument("Kcal nu poate fi negativ!");
                }
            }
            ok1 = true;
            cout << "Pret: ";
            is >> pret;
            if (pret < 0) {
                throw invalid_argument("Pretul nu poate fi negativ!");
            }
            ok = true;
        } catch (invalid_argument &err) {
            cout << "Eroare: " << err.what() << endl;
        }
    }
    return is;
}
