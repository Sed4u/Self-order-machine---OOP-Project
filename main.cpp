#include "Staff.h"
#include "Meniu.h"
#include "Interfata.h"

int main() {
    Meniu* meniu = Meniu::get_instance();
    Staff& staff = Staff::get_instance();
    Interfata::run(meniu,staff);
    return 0;
}
