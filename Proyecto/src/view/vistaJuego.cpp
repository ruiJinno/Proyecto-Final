#include "vistaJuego.h"
#include <iostream>

void Vista::mostrarHabitacion(const Habitacion& habitacion, const Jugador& jugador) {
    std::cout << "\n=== Estas en la habitacion: " << habitacion.getNombre() << " ===\n";

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (jugador.getPosX() == i && jugador.getPosY() == j) {
                std::cout << "[J] ";
            } else if (habitacion.obtenerEntidad(i, j)) {
                std::cout << "[E] ";
            } else {
                std::cout << "[ ] ";
            }
        }
        std::cout << "\n";
    }
}

void Vista::mostrarJugador(const Jugador& jugador) {
    std::cout << "--- Jugador ---\n";
    std::cout << "Vida: " << jugador.getVida()
              << "/" << jugador.getVidaMaxima() << "\n";

    std::cout << "Inventario:\n";
    if (jugador.getInventario().empty()) {
        std::cout << "- vacio\n";
    } else {
        for (const auto& item : jugador.getInventario())
            std::cout << "- " << item->getNombre() << "\n";
    }
    std::cout << "----------------\n";
}

void Vista::mostrarMensaje(const std::string& mensaje) {
    std::cout << mensaje << std::endl;
}
