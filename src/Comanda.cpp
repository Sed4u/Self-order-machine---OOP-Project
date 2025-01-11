#include "Comanda.h"
#include "Staff.h"
#include <algorithm>
using namespace std;

unsigned int Comanda::count = 0;

Comanda::Comanda() : id_c(++count), status(false), locatie(false), total(0) {
}


void Comanda::adauga_element(Meniu *meniu, const unsigned int id) {
    auto lista_elemente = meniu->get_lista();
    Element *found_elem = nullptr;

    for (auto *e : lista_elemente) {
        if (e->getId() == id) {
            found_elem = e;
            break;
        }
    }

    if (found_elem != nullptr) {
        bool produs_gasit = false;
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (it->first->getId() == found_elem->getId()) {
                cout << "Produs deja existent in comanda. Modifici cantitatea? (y/n): ";
                char optiune;
                cin >> optiune;
                if (optiune == 'y') {
                    cout << found_elem->getNume() << " - Cantitatea noua (0 pentru a sterge elementul din comanda): ";
                    unsigned int cantitate;
                    cin >> cantitate;

                    if (cantitate == 0) {
                        lista.erase(it);
                    } else {
                        it->second = cantitate;
                    }
                }
                produs_gasit = true;
                break;
            }
        }
        if (!produs_gasit) {
            unsigned int cantitate;
            cout << found_elem->getNume() << " - Cantitate: ";
            cin >> cantitate;

            lista.emplace_back(found_elem, cantitate);
        }
    } else {
        cout << "Elementul cu id-ul " << id << " nu a fost gasit!" << endl;
    }
}

void Comanda::setLocatie(bool l) {
    this->locatie = l;
}

void Comanda::calculeazaTotal() {
    total = 0;
    for (const auto &[element, cantitate]: lista) {
        total += element->getPret() * static_cast<float>(cantitate);
    }
}


void Comanda::afiseazaComanda() {
    calculeazaTotal();
    cout << "Detalii comanda " << id_c << ":\n";
    cout << "Servire: ";
    locatie ? (cout << "La pachet") : (cout << "In restaurant");
    cout << "\nTotal: " << total << " lei\n";
    sort(lista.begin(), lista.end(),
         [](const pair<Element *, unsigned int> &a, const pair<Element *, unsigned int> &b) {
             return *(a.first) > *(b.first);
         });
    for (const auto &[element, cantitate]: lista) {
        cout << *element << "  x " << cantitate << endl;
    }
}


void Comanda::modificaCantitate() {
    cout << "ID-ul elementului caruia vrei sa ii modifici cantitatea: ";
    unsigned int id;
    cin >> id;

    pair<Element*, unsigned int>* found_elem = nullptr;

    for (auto& e : lista) {
        if (e.first->getId() == id) {
            found_elem = &e;
            break;
        }
    }

    if (found_elem != nullptr) {
        cout << found_elem->first->getNume() << " - Cantitatea noua (0 pentru a sterge elementul din comanda): ";
        unsigned int cantitate;
        cin >> cantitate;

        if (cantitate == 0) {
            lista.erase(remove_if(lista.begin(), lista.end(), [found_elem](const pair<Element*, unsigned int>& e) {
                return e.first->getId() == found_elem->first->getId();
            }), lista.end());
        } else {
            found_elem->second = cantitate;
        }
    } else {
        cout << "Elementul cu ID-ul " << id << " nu a fost gasit!";
    }
}


void Comanda::confirmaComanda(Staff &staff) {
    cout << "\t1. Plateste\n\t2. Anuleaza comanda\n";
    unsigned int optiune;
    cout << "Optiune: ";
    cin >> optiune;
    if (optiune == 1) {
        if(total > 0) {
            cout << "Comanda va fi gata in cateva minute. Pofta buna!\n";
            staff.adaugaComanda(this);
        }
        else {
            cout << "Comanda invalida! Comanda ta a fost anulata!\n";
            count--;
            delete this;
        }
    } else if (optiune == 2) {
        cout << "Comanda a fost anulata!\n";
        count--;
        delete this;
    }
}

Comanda::~Comanda() {
    for (const auto &pair: lista) {
        delete pair.first;
    }
    lista.clear();
}
