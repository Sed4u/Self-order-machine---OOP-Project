#include "Staff.h"
#include "Meniu.h"
#include "Interfata.h"

int main() {
    Meniu *meniu = Meniu::get_instance();
    Staff &staff = Staff::get_instance();
    Interfata::run(meniu, staff);
    return 0;
}


//TO DO: fa clasa template din mancare si bautura
//TO DO: fa o functie virtuala care sa faca ceva
//TO DO: adauga inca un design pattern
