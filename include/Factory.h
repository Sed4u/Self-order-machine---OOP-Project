
#ifndef FACTORY_H
#define FACTORY_H
#include "Element.h"
#include "Produs.h"
using namespace std;

class ElementFactory {
public:
    [[nodiscard]] virtual Element* createElement() const = 0;
    virtual ~ElementFactory() = default;
};

template <class T>
class Factory : public ElementFactory {
public:
    [[nodiscard]] Element* createElement() const override {
        Element* prod = new Produs<T>;
        cin >> *prod;
        return prod;
    }
    ~Factory() override = default;
};

class FactorySelector {
public:
    static ElementFactory* getFactory(const string& tip) {
        static Factory<Mancare> mancareFactory;
        static Factory<Bautura> bauturaFactory;

        if (tip == "Mancare") {
            return &mancareFactory;
        } else if (tip == "Bautura") {
            return &bauturaFactory;
        } else {
            throw invalid_argument("Tip necunoscut");
        }
    }
};
#endif //FACTORY_H
