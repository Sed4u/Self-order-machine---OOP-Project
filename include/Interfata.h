
#ifndef INTERFATA_H
#define INTERFATA_H
#include "Meniu.h"
#include "Staff.h"
class Interfata {
public:
    Interfata() = default;
    ~Interfata() = default;
    static void populeazaMeniu(Meniu* meniu);
    static void run(Meniu* meniu,Staff& staff);
};
#endif //INTERFATA_H
