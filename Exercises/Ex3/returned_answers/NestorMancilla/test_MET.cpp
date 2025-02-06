#include <iostream>
#include "MET.h"

int main() {
    MET met(3, 4);
    std::cout << "MET: " << met.getMET() << "\n";
    std::cout << "Phi: " << met.getPhi() << "\n";
}

