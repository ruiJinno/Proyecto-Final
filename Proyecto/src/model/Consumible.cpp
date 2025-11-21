#include "Consumible.h"
#include "Jugador.h"
#include <iostream>

void Consumible::usar() {
    std::cout << "Usaste " << nombre << " y recuperaste " << cantidadVida << " de vida." << std::endl;
}

void Consumible::mostrarInfo() const {
    std::cout << "Objeto: " << nombre << " (Vida que restaura: " << cantidadVida << ")" << std::endl;;
}
