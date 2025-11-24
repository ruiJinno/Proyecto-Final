//
// Created by Elian on 24/11/2025.
//

#include "view.h"
#include <iostream>

View::View(Mapa* m) : mapa(m) {}

void View::mostrarMapa() {
    Habitacion* hab = mapa->getHabitacion();
    if (!hab) return;

    int tam = hab->getTam();
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (mapa->getJugador()->getPosX() == j && mapa->getJugador()->getPosY() == i) {
                std::cout << mapa->getJugador()->getSimbolo() << "[*]";
            } else if (hab->obtenerEnemigo(j, i)) {
                std::cout << "[E]";
            } else if (hab->obtenerObjeto(j, i)) {
                std::cout << "[O]";
            } else if (hab->obtenerNPC(j, i)) {
                std::cout << "[N]";
            } else {
                std::cout << "[ ]";
            }
        }
        std::cout << "\n";
    }
}

void View::mostrarOpciones() {
    std::cout << "\nOpciones: \n";
    std::cout << "W/A/S/D - Mover\n";
    std::cout << "I - Ver inventario\n";
    std::cout << "U - Usar - Equipar\n";
    std::cout << "Q - Salir\n";
}

char View::obtenerInput() {
    char opcion;
    std::cout << "\nIngresa tu accion: ";
    std::cin >> opcion;
    return opcion;
}

void View::actualizar() {
    mostrarMapa();
    mostrarOpciones();
}
