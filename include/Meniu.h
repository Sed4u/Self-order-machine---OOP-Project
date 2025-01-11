
#ifndef MENIU_H
#define MENIU_H
#include "Element.h"
#include <vector>

class Meniu {
    vector<Element *> lista;
    static Meniu *instance;

    Meniu() = default;

public:
    static Meniu *get_instance() {
        if (instance == nullptr) {
            instance = new Meniu();
        }
        return instance;
    }

    void afisare_meniu() const;

    ~Meniu();

    [[nodiscard]] vector<Element *> &get_lista();
};
#endif //MENIU_H
