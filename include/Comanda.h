
#ifndef COMANDA_H
#define COMANDA_H
#include <vector>
#include "Element.h"
#include "Meniu.h"
#include "Staff.h"
class Staff;

class Comanda {
    static unsigned int count;
    unsigned int id_c;
    vector<pair<Element *, unsigned int> > lista;
    bool status; //gata sau nu - 0 nu 1 da
    bool locatie; //aici sau pachet - 0 aici 1 pachet
    float total;

public:
    Comanda();

    void calculeazaTotal();

    void adauga_element(Meniu *meniu, unsigned int id);

    void afiseazaComanda();

    void setLocatie(bool locatie);

    void modificaCantitate();

    void confirmaComanda(Staff &staff);

    ~Comanda();

    friend class Staff;
};
#endif //COMANDA_H
