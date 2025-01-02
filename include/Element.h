
#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Element {
    static unsigned int count;
    unsigned int id_e;
    string nume;
    float kcal;
    float pret;
public:

    Element() : id_e(++count), kcal(0), pret(0) {}
    explicit Element(string nume, float kcal, float pret);
    Element(const Element& other);
    Element& operator=(const Element& other);
    friend ostream& operator<<(ostream& os, const Element& e);
    friend istream& operator>>(istream& is, Element& e);
    friend bool operator<(const Element& e1, const Element& e2);
    friend bool operator>(const Element& e1, const Element& e2);
    virtual ~Element();

    [[nodiscard]] unsigned int getId() const;
    [[nodiscard]] float getPret() const;
    [[nodiscard]] const string& getNume() const;
    [[nodiscard]] float getKcal() const;

    void setPret(float p);
    void setNume(const string& n);
    void setKcal(float k);

    virtual vector<Element*> operator+(vector<Element*>& lista_elemente);

    virtual ostream& print(ostream& os) const;

    virtual istream& read(istream& is);
};
#endif //ELEMENT_H
