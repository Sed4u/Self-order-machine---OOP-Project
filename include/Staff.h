
#ifndef STAFF_H
#define STAFF_H
#include "Meniu.h"
#include "Comanda.h"
#include <vector>
class Comanda;

class Staff {
    Meniu *meniu;
    vector<Comanda *> comenzi;
    static Staff staffInstance;

    Staff();

public:
    Staff(const Staff &) = delete;

    Staff &operator=(const Staff &) = delete;

    static Staff &get_instance() {
        return staffInstance;
    }

    ~Staff();

    void setStatus();

    void adaugaComanda(Comanda *comanda);

    void afiseazaComenzi() const;

    void afiseazaStatusComenzi() const;

    void stergeElement() const;

    void modificaElement() const;
};
#endif //STAFF_H
