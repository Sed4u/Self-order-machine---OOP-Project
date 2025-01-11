#include <iostream>
#include "Meniu.h"
#include "Staff.h"
#include "Interfata.h"
#include <fstream>
#include <vector>
#include "Factory.h"
#include "Produs.h"

using namespace std;

void Interfata::populeazaMeniu(Meniu *meniu) {
    const vector<Element *> mancare = {
        new Produs<Mancare>("Big Mac", 508, 18.00, 219),
        new Produs<Mancare>("McChicken", 403, 17.00, 173),
        new Produs<Mancare>("Cheeseburger", 301, 7.00, 115),
        new Produs<Mancare>("Double Cheeseburger", 445, 12.00, 155),
        new Produs<Mancare>("Chicken McNuggets (6 bucati)", 259, 14.00, 87),
        new Produs<Mancare>("Filet-o-Fish", 327, 17.50, 142),
        new Produs<Mancare>("McWrap Crispy", 479, 19.00, 215),
        new Produs<Mancare>("Cartofi prajiti", 320, 9.50, 117),
        new Produs<Mancare>("McMuffin cu Ou si Bacon", 295, 12.00, 113),
        new Produs<Mancare>("McToast", 265, 6.50, 102)
    };
    for (size_t i = 0; i < mancare.size(); ++i) {
        meniu->get_lista() = *mancare[i] + meniu->get_lista();
    }
    const vector<Element *> bauturi = {
        new Produs<Bautura>("Coca-Cola", 112, 7.00, 250),
        new Produs<Bautura>("Fanta", 105, 7.00, 250),
        new Produs<Bautura>("Sprite", 100, 7.00, 250),
        new Produs<Bautura>("Milkshake", 330, 12.00, 300),
        new Produs<Bautura>("Cafea", 0, 6.00, 250),
        new Produs<Bautura>("Apa plata", 0, 5.00, 500),
        new Produs<Bautura>("Suc de portocale", 150, 10.00, 400)
    };
    for (size_t i = 0; i < bauturi.size(); ++i) {
        meniu->get_lista() = *bauturi[i] + meniu->get_lista();
    }
}


void Interfata::run(Meniu *meniu, Staff &staff) {
    populeazaMeniu(meniu);
    bool intf = false;
    while (!intf) {
        cout << "Bine ati venit!\n\t1. Comanda acum!"
                "\n\t2. Vizualizare status comanda"
                "\n\t3. Staff only!"
                "\n\t4. Exit\n";
        unsigned int optiune;
        cout << "Optiune: ";
        cin >> optiune;
        switch (optiune) {
            case 1: {
                auto *comanda = new Comanda();
                bool cmd = false;
                cout << "Alege locul unde vei servi. (default in restaurant)"
                        "\n\t1. In restaurant"
                        "\n\t2. La pachet\n";
                unsigned int lct;
                cout << "Optiune: ";
                cin >> lct;
                if (lct == 2) {
                    comanda->setLocatie(true); //optiunea 2 pt la pachet, optiunea 1 pentru in restaurant
                } else {
                    if (optiune == 1) {
                        comanda->setLocatie(false);
                    }
                }
                cout << endl;
                meniu->afisare_meniu();
                while (!cmd) {
                    cout << endl;
                    comanda->afiseazaComanda();
                    cout <<
                            "\n\t1. Alege un produs si adauga-l la comanda ta!"
                            "\n\t2. Modifica comanda ta"
                            "\n\t3. Finalizeaza comanda\n";
                    unsigned int optiune_comanda;
                    cout << "Optiune: ";
                    cin >> optiune_comanda;
                    switch (optiune_comanda) {
                        case 1: {
                            unsigned int id;
                            cout << "Ce produs doresti?\nIntrodu id-ul produsului: ";
                            cin >> id;
                            comanda->adauga_element(meniu, id);
                            break;
                        }
                        case 2:
                            comanda->modificaCantitate();
                            break;
                        case 3:
                            cout << "Inca putin si am terminat! (default anuleaza comanda)\n";
                            comanda->confirmaComanda(staff);
                            cmd = true;
                            break;
                        default:
                            cout << "Alege una dintre optiunile indicate!\n";
                            break;
                    }
                }
                break;
            }
            case 2:
                staff.afiseazaStatusComenzi();
                break;
            case 3: {
                const string parola = "ciscosecpa55";
                string incercare;
                cout << "Introdu parola: ";
                cin >> incercare;

                if (incercare == parola) {
                    cout << "Bine ai venit!\n";
                    bool stf = false;
                    while (!stf) {
                        cout <<
                                "\t1. Adauga un element in meniu"
                                "\n\t2. Modifica un element din meniu"
                                "\n\t3. Sterge un element din meniu"
                                "\n\t4. Modifica status-ul unei comenzi"
                                "\n\t5. Inapoi la pagina principala\n";
                        unsigned int optiune_staff;
                        cout << "Optiune: ";
                        cin >> optiune_staff;
                        switch (optiune_staff) {
                            case 1: {
                                cout << "\t1. Adauga mancare\n\t2. Adauga bautura\n";
                                unsigned int optiune_aduagare;
                                cout << "Optiune: ";
                                cin >> optiune_aduagare;
                                if (optiune_aduagare == 1) {
                                    const ElementFactory* factory = FactorySelector::getFactory("Mancare");
                                    Element * produs = factory->createElement();
                                    meniu->get_lista().push_back(produs);
                                }
                                else if (optiune_aduagare == 2) {
                                    const ElementFactory* factory = FactorySelector::getFactory("Bautura");
                                    Element * produs = factory->createElement();
                                    meniu->get_lista().push_back(produs);
                                }
                                else cout << "Optiunea nu exista!\n";
                                break;
                            }
                            case 2:
                                staff.modificaElement();
                                break;
                            case 3:
                                staff.stergeElement();
                                break;
                            case 4:
                                staff.afiseazaComenzi();
                                staff.setStatus();
                                break;
                            case 5:
                                stf = true;
                                break;
                            default:
                                cout << "Alege una dintre optiunile indicate!\n";
                                break;
                        }
                    }
                } else {
                    cout << "Acces interzis persoanelor neautorizate!\n";
                }
                break;
            }
            case 4:
                intf = true;
                break;
            default:
                cout << "Alege una dintre optiunile indicate!\n";
                break;
        }
    }
}
