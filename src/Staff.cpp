#include "Staff.h"
#include <algorithm>

#include "Produs.h"
using namespace std;

Staff Staff::staffInstance;

Staff::Staff() : meniu(Meniu::get_instance()) {
}

Staff::~Staff() {
    for (const auto comanda: comenzi) {
        delete comanda;
    }
    comenzi.clear();
    meniu = nullptr;
}

void Staff::afiseazaComenzi() const {
    cout << "-------------------------Comenzi-------------------------\n";
    for (const auto &i: comenzi) {
        i->afiseazaComanda();
        cout << "Status comanda: ";
        i->status ? (cout << "GATA!") : (cout << "IN PREGATIRE...");
        cout << endl << endl;
    }
    cout << "---------------------------------------------------------\n";
}

void Staff::adaugaComanda(Comanda *comanda) {
    comenzi.push_back(comanda);
}


void Staff::setStatus() {
    cout << "ID-ul comenzii pe careia doresti sa ii modifici status-ul: ";
    unsigned int id;
    cin >> id;

    Comanda *found_comanda = nullptr;

    for (auto *c: comenzi) {
        if (c->id_c == id) {
            found_comanda = c;
            break;
        }
    }

    if (found_comanda != nullptr) {
        unsigned int optiune;
        cout << "\t1. In pregatire\n";
        cout << "\t2. Gata\n";
        cout << "Optiune: ";
        cin >> optiune;

        if (optiune == 2) {
            // Gata
            found_comanda->status = true;
            cout << "Comanda cu ID-ul " << id << " a fost setata la Gata." << endl;
        } else if (optiune == 1) {
            // in pregatire
            found_comanda->status = false;
            cout << "Comanda cu ID-ul " << id << " a fost setata la In pregatire." << endl;
        }
    } else {
        cout << "Comanda cu ID-ul " << id << " nu a fost gasita!" << endl;
    }
}

void Staff::modificaElement() const {
    cout << "ID-ul elementului pe care vrei sa il modifici: ";
    unsigned int id;
    cin >> id;

    Element *found_elem = nullptr;

    for (auto *e: meniu->get_lista()) {
        if (e->getId() == id) {
            found_elem = e;
            break;
        }
    }

    if (found_elem != nullptr) {
        cout << "Vei modifica datele elementului:\n";
        cout << *found_elem << endl;

        cout << "Introduceti noul nume: ";
        string nou_nume;
        if (cin.peek() == '\n')
            cin.get();
        getline(cin, nou_nume);
        found_elem->setNume(nou_nume);

        cout << "Introduceti noul numar de calorii: ";
        float nou_kcal;
        cin >> nou_kcal;
        found_elem->setKcal(nou_kcal);

        cout << "Introduceti noul pret: ";
        float nou_pret;
        cin >> nou_pret;
        found_elem->setPret(nou_pret);


        if (auto *bautura = dynamic_cast<Produs<Bautura> *>(found_elem)) {
            cout << "Introduceti noul numar de mililitri: ";
            unsigned int noi_mililitri;
            cin >> noi_mililitri;
            bautura->setUnitati(noi_mililitri);
        } else if (auto *mancare = dynamic_cast<Produs<Mancare> *>(found_elem)) {
            cout << "Introduceti noul numar de grame: ";
            unsigned int noi_grame;
            cin >> noi_grame;
            mancare->setUnitati(noi_grame);
        }
    } else {
        cout << "Elementul cu ID-ul " << id << " nu a fost gasit." << endl;
    }
}


void Staff::stergeElement() const {
    cout << "ID-ul elementului pe care vrei sa il stergi: ";
    unsigned int id;
    cin >> id;

    Element *found_elem = nullptr;
    auto& lista_elemente = meniu->get_lista();
    for (auto *e: lista_elemente) {
        if (e->getId() == id) {
            found_elem = e;
            break;
        }
    }

    if (found_elem != nullptr) {
        lista_elemente.erase(std::remove(lista_elemente.begin(), lista_elemente.end(), found_elem), lista_elemente.end());

        for (auto& comanda : comenzi) {
            auto& comanda_lista = comanda->lista;
            comanda_lista.erase(std::remove_if(comanda_lista.begin(), comanda_lista.end(),
                [found_elem](const pair<Element*, unsigned int>& e) {
                    return e.first == found_elem;
                }), comanda_lista.end());
        }

        delete found_elem;
        cout << "Elementul cu ID-ul " << id << " a fost sters!" << endl;
    } else {
        cout << "Elementul cu ID-ul " << id << " nu a fost gasit!" << endl;
    }
}

void Staff::afiseazaStatusComenzi() const {
    cout << "---------Comenzi---------" << endl;
    for (const auto &i: comenzi) {
        cout << "Comanda " << i->id_c << " - ";
        i->status ? (cout << "GATA!") : (cout << "IN PREGATIRE...");
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

